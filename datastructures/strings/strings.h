#include <unordered_map>

using namespace std;

namespace DataStructures::Strings
{
    /*
    387. First Unique Character in a String
    Easy

    Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

    Example 1:

    Input: s = "leetcode"
    Output: 0

    */
    int firstUniqChar(string s) {
        unordered_map<char, pair<int, int>> m;
        int idx = s.size();
        for (int i = 0; i < s.size(); i++) {
            m[s[i]].first++;
            m[s[i]].second = i;
        }
        for (const auto& [c, p] : m) {
            if (p.first == 1) {
                idx = min(idx, p.second);
            }
        }
        return idx == s.size() ? -1 : idx;
    }

    /*
    383. Ransom Note
    Easy

    Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

    Each letter in magazine can only be used once in ransomNote.

    Example 1:

    Input: ransomNote = "a", magazine = "b"
    Output: false
    */
    bool canConstruct(string ransomNote, string magazine) {
        auto m = std::map<char, int>{};
        
        for (auto &ch : magazine)
            m[ch]++;
        
        for (auto &ch: ransomNote)
        {
            auto findIt = m.find(ch);
            if (findIt == m.end())
                return false;
            
            findIt->second--;
            if (findIt->second == 0)
                m.erase(findIt);
        }
        
        return true;
    }

    /*
    242. Valid Anagram
    Easy

    Given two strings s and t, return true if t is an anagram of s, and false otherwise.

    An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

    Example 1:

    Input: s = "anagram", t = "nagaram"
    Output: true
    */
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        
        auto m = std::map<char, int>{};
        
        for (auto &ch : t)
            m[ch]++;
        
        for (auto &ch: s)
        {
            auto findIt = m.find(ch);
            if (findIt == m.end())
                return false;
            
            findIt->second--;
            if (findIt->second == 0)
                m.erase(findIt);
        }
        
        return m.empty();
    }

    void run()
    {
        std::cout << "[DataStructures][Strings]  Start" << std::endl;

        {
            auto s = "leetcode";
            auto result = firstUniqChar(s);
            assert(result == 0);

            std::cout << "  [PASSED] 387. First Unique Character in a String" << std::endl;
        }
        
        {
            auto result = canConstruct("a", "b");
            assert(result == false);

            std::cout << "  [PASSED] 387. Ransom Note" << std::endl;
        }
        
        {
            auto result = isAnagram("anagram", "nagaram");
            assert(result == true);

            std::cout << "  [PASSED] 242. Valid Anagram" << std::endl;
        }

        std::cout << "[DataStructures][Strings]  End" << std::endl;
    }
}