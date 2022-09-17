#include <map>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

namespace Algorithms::Counting
{
    /*
    1365. How Many Numbers Are Smaller Than the Current Number
    Easy

    Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].

    Return the answer in an array.

    Example 1:

    Input: nums = [8,1,2,2,3]
    Output: [4,0,1,1,3]
    Explanation: 
    For nums[0]=8 there exist four smaller numbers than it (1, 2, 2 and 3). 
    For nums[1]=1 does not exist any smaller number than it.
    For nums[2]=2 there exist one smaller number than it (1). 
    For nums[3]=2 there exist one smaller number than it (1). 
    For nums[4]=3 there exist three smaller numbers than it (1, 2 and 2).
    */
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        auto m = std::map<int, int>{};
        for (auto n : nums)
            m[n]++;
        
        auto count = 0;
        for (auto &[k,v] : m)
        {
            swap(v, count);
            count += v;
        }
        
        for (auto i = 0; i < nums.size(); i++)
            nums[i] = m[nums[i]];
        
        return nums;
    }

    /*
    2351. First Letter to Appear Twice
    Easy

    Given a string s consisting of lowercase English letters, return the first letter to appear twice.

    Note:

        A letter a appears twice before another letter b if the second occurrence of a is before the second occurrence of b.
        s will contain at least one letter that appears twice.

    

    Example 1:

    Input: s = "abccbaacz"
    Output: "c"
    Explanation:
    The letter 'a' appears on the indexes 0, 5 and 6.
    The letter 'b' appears on the indexes 1 and 4.
    The letter 'c' appears on the indexes 2, 3 and 7.
    The letter 'z' appears on the index 8.
    The letter 'c' is the first letter to appear twice, because out of all the letters the index of its second occurrence is the smallest.
    */
    char repeatedCharacter(string s) {
        auto _set = std::unordered_set<char>{};
        
        for (auto ch : s)
        {
            auto [it, inserted] = _set.insert(ch);
            if (!inserted)
                return ch;
        }
        
        return ' ';
    }

    /*
    1748. Sum of Unique Elements
    Easy

    You are given an integer array nums. The unique elements of an array are the elements that appear exactly once in the array.

    Return the sum of all the unique elements of nums.

    Example 1:

    Input: nums = [1,2,3,2]
    Output: 4
    Explanation: The unique elements are [1,3], and the sum is 4.
    */
    int sumOfUnique(vector<int>& nums) {
        auto m = std::unordered_map<int, bool>{};
        int sum = 0;
        
        for (auto el: nums)
        {
            auto [it, inserted] = m.insert({el, true});
            if (!inserted)
            {
                if (it->second)
                {
                    sum -= el;
                    it->second = false;
                }
            }
            else
            {
                sum += el;
            }
        }
        
        return sum;
    }

    void run()
    {
        std::cout << "[Algorithms][Counting]  End" << std::endl;

        {
            auto v = std::vector<int>{8,1,2,2,3};
            auto expected = std::vector<int>{4,0,1,1,3};
            auto result = smallerNumbersThanCurrent(v);

            assert(result == expected);

            std::cout << "  [PASSED] 1365. How Many Numbers Are Smaller Than the Current Number" << std::endl;
        }
        
        {
            auto s = "abccbaacz";
            auto result = repeatedCharacter(s);

            assert(result == 'c');

            std::cout << "  [PASSED] 2351. First Letter to Appear Twice" << std::endl;
        }
        
        {
            auto v = std::vector<int>{1,2,3,2};
            auto result = sumOfUnique(v);

            assert(result == 4);

            std::cout << "  [PASSED] 1748. Sum of Unique Elements" << std::endl;
        }

        std::cout << "[Algorithms][Counting]  End" << std::endl;
    }
}