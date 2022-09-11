#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>
#include <vector>

#include "..\..\common\listnode.h"

using namespace std;

namespace Algorithms::TwoPointers
{
    /*
    977. Squares of a Sorted Array
    Easy

    Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

    Example 1:

    Input: nums = [-4,-1,0,3,10]
    Output: [0,1,9,16,100]
    Explanation: After squaring, the array becomes [16,1,0,9,100].
    After sorting, it becomes [0,1,9,16,100].
    */
    vector<int> sortedSquares(vector<int>& nums) {        
        auto output = std::vector<int>(nums.size());
        auto low = 0;
        auto high = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (abs(nums[high]) > abs(nums[low]))
            {
                output[i] = nums[high] * nums[high];
                high--;
            }
            else
            {
                output[i] = nums[low] * nums[low];
                low++;
            }
        }
        return output;
    }

    /*
    189. Rotate Array
    Medium

    Given an array, rotate the array to the right by k steps, where k is non-negative.

    Example 1:

    Input: nums = [1,2,3,4,5,6,7], k = 3
    Output: [5,6,7,1,2,3,4]
    Explanation:
    rotate 1 steps to the right: [7,1,2,3,4,5,6]
    rotate 2 steps to the right: [6,7,1,2,3,4,5]
    rotate 3 steps to the right: [5,6,7,1,2,3,4]
    */
    void rotate(vector<int>& nums, int k) {        
        k %=nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }

    /*
    283. Move Zeroes
    Easy

    Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

    Note that you must do this in-place without making a copy of the array.

    Example 1:

    Input: nums = [0,1,0,3,12]
    Output: [1,3,12,0,0]
    */
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                swap(nums[i],nums[j++]);
            }
        }
    }

    /*
    167. Two Sum II - Input Array Is Sorted
    Medium

    Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

    Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

    The tests are generated such that there is exactly one solution. You may not use the same element twice.

    Your solution must use only constant extra space.

    Example 1:

    Input: numbers = [2,7,11,15], target = 9
    Output: [1,2]
    Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
    */

    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0;
        int high = numbers.size() - 1;
        while (low < high)
        {
            auto sum = numbers[low] + numbers[high];
            if (sum == target)
                return {low + 1, high + 1};
            else if (sum > target)
                high--;
            else
                low++;
        }
        
        return {};
    }

    /*
    344. Reverse String
    Easy

    Write a function that reverses a string. The input string is given as an array of characters s.

    You must do this by modifying the input array in-place with O(1) extra memory.

    Example 1:

    Input: s = ["h","e","l","l","o"]
    Output: ["o","l","l","e","h"]
    */
    void swap(vector<char>& s, int begin, int end) 
    {
        if (begin >= end)
            return;
        auto tmp = s[end];
        s[end] = s[begin];
        s[begin] = tmp;
        
        swap(s, begin + 1, end - 1);
    }
    void reverseString(vector<char>& s)
    {
        swap(s, 0, s.size() - 1);    
    }

    /*
    19. Remove Nth Node From End of List
    Medium

    Given the head of a linked list, remove the nth node from the end of the list and return its head.

    Example 1:

    Input: head = [1,2,3,4,5], n = 2
    Output: [1,2,3,5]
    */
    void removeNext(ListNode *node)
    {
        auto tmp = node->next ? node->next->next : nullptr;
        delete node->next;
        node->next = tmp;
    }
    
    void reset(ListNode* head, ListNode*& slow, ListNode*& fast, int &slowIdx, int &fastIdx)
    {
        slow = head;
        fast = head->next;
        slowIdx = 1;
        fastIdx = 2;
    }
    
    bool checkAndRemove(ListNode *node, int idx, int idxToRemove)
    {
        if (idx + 1 == idxToRemove)
        {
            removeNext(node);
            return true;
        }
        if (idx + 2 == idxToRemove)
        {
            removeNext(node->next);
            return true;
        }
        
        return false;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow, *fast;
        int slowIdx, fastIdx;        
        auto idxToRemove = INT_MAX;
        reset(head, slow, fast, slowIdx, fastIdx);
        
        while (true)
        {
            if (idxToRemove == INT_MAX)
            {
                if (fast == 0)
                    idxToRemove = fastIdx - n;
                else if (fast->next == 0)
                    idxToRemove = fastIdx + 1 - n;
            }
            
            if (idxToRemove == 1)
                return head->next;
            
            if (checkAndRemove(fast, fastIdx, idxToRemove))
                return head;
            if (checkAndRemove(slow, slowIdx, idxToRemove))
                return head;
                        
            if (slowIdx >= idxToRemove)
            {
                reset(head, slow, fast, slowIdx, fastIdx);
                continue;
            }
            
            slow = slow->next;
            slowIdx++;
            
            fast = fast && fast->next ? fast->next->next : nullptr;
            fastIdx += 2;
        }
        
        return slow;
    }

    void run()
    {
        std::cout << "[Algorithms][TwoPointers]  Start" << std::endl;

        {
            auto v = std::vector<int> {-4,-1,0,3,10};
            auto expected = std::vector<int>{0,1,9,16,100};
            auto result = sortedSquares(v);

            assert(result == expected);

            std::cout << "  [PASSED] 977. Squares of a Sorted Array" << std::endl;
        }
        
        {
            auto v = std::vector<int> {1,2,3,4,5,6,7};
            auto expected = std::vector<int>{5,6,7,1,2,3,4};
            rotate(v, 3);

            assert(v == expected);

            std::cout << "  [PASSED] 189. Rotate Array" << std::endl;
        }
        
        {
            auto v = std::vector<int> {0,1,0,3,12};
            auto expected = std::vector<int>{1,3,12,0,0};
            moveZeroes(v);

            assert(v == expected);

            std::cout << "  [PASSED] 283. Move Zeroes" << std::endl;
        }
        
        {
            auto v = std::vector<int> {2,7,11,15};
            auto expected = std::vector<int>{1,2};
            auto result = twoSum(v, 9);

            assert(result == expected);

            std::cout << "  [PASSED] 167. Two Sum II - Input Array Is Sorted" << std::endl;
        }
        
        {
            auto v = std::vector<char> {'h','e','l','l','o'};
            auto expected = std::vector<char>{'o','l','l','e','h'};
            reverseString(v);

            assert(v == expected);

            std::cout << "  [PASSED] 344. Reverse String" << std::endl;
        }
        
        {
            auto list = new ListNode(1);
            list->next = new ListNode(2);
            list->next->next = new ListNode(3);
            list->next->next->next = new ListNode(4);
            list->next->next->next->next = new ListNode(5);
            
            auto expected = new ListNode(1);
            expected->next = new ListNode(2);
            expected->next->next = new ListNode(3);
            expected->next->next->next = new ListNode(5);

            auto result = removeNthFromEnd(list, 2);

            assert(equal(result, expected));

            std::cout << "  [PASSED] 19. Remove Nth Node From End of List" << std::endl;
        }

        std::cout << "[Algorithms][TwoPointers]  End" << std::endl;
    }
}