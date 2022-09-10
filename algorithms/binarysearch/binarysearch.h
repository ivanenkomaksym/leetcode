#define uint unsigned int

#include <cassert>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

namespace Algorithms::BinarySearch
{
    /*
    704. Binary Search
    Easy

    Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

    You must write an algorithm with O(log n) runtime complexity.

    Example 1:

    Input: nums = [-1,0,3,5,9,12], target = 9
    Output: 4
    Explanation: 9 exists in nums and its index is 4
    */
    int search(vector<int>& nums, int target) {
        uint low = 0;
        uint high = nums.size() - 1;
        
        if (low == high)
            return (nums[0] == target) ? 0 : -1;
        
        while (true)
        {
            auto index = (high + low) / 2;
            
            if (nums[index] == target)
                return index;
            
            if (high - low == 1)
            {
                if (nums[high] == target)
                    return high;
                return -1;
            }
            
            if (nums[index] < target)
                low = index;
            else
                high = index;
        }
    }

    /*
    278. First Bad Version
    Easy

    You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

    Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

    You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

    Example 1:

    Input: n = 5, bad = 4
    Output: 4
    Explanation:
    call isBadVersion(3) -> false
    call isBadVersion(5) -> true
    call isBadVersion(4) -> true
    Then 4 is the first bad version.
    */

    bool isBadVersion(int version)
    {
        if (version == 4)
            return true;

        return false;
    }

    int firstBadVersion(int n) {
        if (n == 1)
            return isBadVersion(1);
        
        long low = 1;
        long high = n;
        
        while (true)
        {                
            if (low == high - 1)
                return isBadVersion(low) ? low : high;
            
            long guess = (high + low) / 2;
            if (!isBadVersion(guess))
            {
                low = guess;
            }
            else
            {
                high = guess;
            }
        }
    }

    /*
    35. Search Insert Position
    Easy

    Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

    You must write an algorithm with O(log n) runtime complexity.

    Example 1:

    Input: nums = [1,3,5,6], target = 5
    Output: 2
    */

    int searchInsert(vector<int>& nums, int target) {
        auto low = 0;
        auto high = nums.size() - 1;
        
        while (true)
        {
            if (high - low <= 1)
            {
                if (nums[low] >= target)
                    return low;
                else if (nums[high] >= target)
                    return high;
                else
                    return high + 1;
            }
            
            auto guess = (high + low) / 2;
            if (nums[guess] == target)
            {
                return guess;
            }
            else if (nums[guess] < target)
            {
                low = guess;
            }
            else
            {
                high = guess;
            }
        }
    }

    void run()
    {
        std::cout << "[Algorithms][BinarySearch]  Start" << std::endl;

        {
            auto v = std::vector<int>{-1,0,3,5,9,12};
            auto result = search(v, 9);
            assert(result == 4);

            std::cout << "  [PASSED] 704. Binary Search" << std::endl;
        }
        
        {
            auto result = firstBadVersion(5);
            assert(result == 4);

            std::cout << "  [PASSED] 278. First Bad Version" << std::endl;
        }
        
        {
            auto v = std::vector<int>{1,3,5,6};
            auto result = searchInsert(v, 5);
            assert(result == 2);

            std::cout << "  [PASSED] 35. Search Insert Position" << std::endl;
        }

        std::cout << "[Algorithms][BinarySearch]  End" << std::endl;
    }
}