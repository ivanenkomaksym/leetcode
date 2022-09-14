#include <numeric>
#include <string>
#include <vector>

using namespace std;

namespace Algorithms::Backtracking
{
    /*
    77. Combinations
    Medium

    Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

    You may return the answer in any order.

    Example 1:

    Input: n = 4, k = 2
    Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
    Explanation: There are 4 choose 2 = 6 total combinations.
    Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
    */
    void generate(std::vector<int> &arr, std::vector<std::vector<int>> &output, std::vector<int> &data,
                  int start, int end,
                  int index, int r)
    {
        if (index == r)
        {
            output.push_back(data);
            return;
        }
        
        for (int i = start; i <= end &&
            end - i + 1 >= r - index; i++)
        {
            data[index] = arr[i];
            generate(arr, output, data, i+1, end, index+1, r);
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        auto input = std::vector<int>(n);
        std::iota(std::begin(input), std::end(input), 1);
        
        auto data = std::vector<int>(k, 0);
        
        auto output = std::vector<vector<int>>();
               
        generate(input, output, data, 0, n - 1, 0, k);
        
        return output;
    }

    /*
    46. Permutations
    Medium

    Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

    Example 1:

    Input: nums = [1,2,3]
    Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
    */
    void permute(vector<int>& nums, vector<vector<int>>& output, int l, int r) 
    { 
        // Base case 
        if (l == r) 
        {
            output.push_back(nums);
        }
        else
        { 
            // Permutations made 
            for (int i = l; i <= r; i++) 
            { 
                // Swapping done 
                swap(nums[l], nums[i]); 

                // Recursion called 
                permute(nums, output, l+1, r); 

                //backtrack 
                swap(nums[l], nums[i]); 
            } 
        } 
    } 
    vector<vector<int>> permute(vector<int>& nums) {
        auto output = vector<vector<int>>{};
        permute(nums, output, 0, nums.size() - 1);
        
        return output;
    }

    /*
    784. Letter Case Permutation
    Medium

    Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.

    Return a list of all possible strings we could create. Return the output in any order.

    Example 1:

    Input: s = "a1b2"
    Output: ["a1b2","a1B2","A1b2","A1B2"]
    */
    void permute(string &a, vector<string> &output, int low, int high) 
    {     
        output.push_back(a);
        
        // Permutations made 
        for (int i = low; i < high; i++) 
        { 
            if (!isdigit(a[i]))
            {
                // Swapping done 
                if (islower(a[i]))
                    a[i] = toupper(a[i]);
                else
                    a[i] = tolower(a[i]);

                // Recursion called 
                permute(a, output, i + 1, high);

                //backtrack 
                if (islower(a[i]))
                    a[i] = toupper(a[i]);
                else
                    a[i] = tolower(a[i]);
            }
        } 
    } 
    vector<string> letterCasePermutation(string s) {
        auto output = vector<string>{};
        
        permute(s, output, 0, s.size());
        
        return output;
    }

    void run()
    {
        std::cout << "[Algorithms][Backtracking]  Start" << std::endl;

        {
            auto result = combine(4, 2);
            auto expected = vector<vector<int>>{{1,2},{1,3},{1,4},{2,3},{2,4},{3,4}};

            assert(result == expected);

            std::cout << "  [PASSED] 77. Combinations" << std::endl;
        }

        {
            auto v = std::vector<int>{1,2,3};
            auto result = permute(v);
            auto expected = vector<vector<int>>{{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}};

            std::sort(result.begin(), result.end());

            assert(result == expected);

            std::cout << "  [PASSED] 46. Permutations" << std::endl;
        }

        {
            auto s = "a1b2";
            auto result = letterCasePermutation(s);
            auto expected = vector<string>{"a1b2","a1B2","A1b2","A1B2"};

            std::sort(result.begin(), result.end());
            std::sort(expected.begin(), expected.end());

            assert(result == expected);

            std::cout << "  [PASSED] 784. Letter Case Permutation" << std::endl;
        }

        std::cout << "[Algorithms][Backtracking]  End" << std::endl;
    }
}