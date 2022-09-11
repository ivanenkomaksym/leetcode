#include <iostream>

using namespace std;

namespace Algorithms::SlidingWindow
{
    /*
    3. Longest Substring Without Repeating Characters
    Medium

    Given a string s, find the length of the longest substring without repeating characters.

    Example 1:

    Input: s = "abcabcbb"
    Output: 3
    Explanation: The answer is "abc", with the length of 3.
    */
    int lengthOfLongestSubstring(string s) {
        auto subStr = std::string{};
        auto maxLength = 0;
        for (auto ch : s)
        {
            auto found = subStr.find(ch);
            if (found != std::string::npos)
                subStr.erase(subStr.begin(), subStr.begin() + found + 1);
            subStr.push_back(ch);
            if (auto subSize = subStr.size(); subSize > maxLength)
                maxLength = subSize;
        }
        return maxLength;
    }

    void run()
    {
        std::cout << "[Algorithms][SlidingWindow]  Start" << std::endl;

        {
            auto s = "abcabcbb";
            auto result = lengthOfLongestSubstring(s);
            assert(result == 3);

            std::cout << "  [PASSED] 3. Longest Substring Without Repeating Characters" << std::endl;
        }

        std::cout << "[Algorithms][SlidingWindow]  End" << std::endl;
    }
}