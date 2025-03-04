#include <cassert>
#include <climits>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

namespace DataStructures::Arrays
{
    /*
    217. Contains Duplicate
    Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

    Input: nums = [1,2,3,1]
    Output: true
    */
    bool containsDuplicate(vector<int>& nums) {
        auto distinctValues = std::unordered_set<int>{};
        for (auto el : nums)
        {
            auto [it, inserted] = distinctValues.insert(el);
            if (!inserted)
                return true;
        }
        
        return false;
    }

    /*
    53. Maximum Subarray
    Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

    A subarray is a contiguous part of an array.

    Example 1:

    Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
    Output: 6
    Explanation: [4,-1,2,1] has the largest sum = 6.
    */
    int maxSubArray(vector<int>& nums) {
        auto sum = 0;
        auto maxSum = INT_MIN;
        
        for (auto i = 0; i < nums.size(); ++i)
        {
            if (sum > 0)
            {
                sum += nums[i];
            }
            else
            {
                sum = nums[i];
            }
            
            maxSum = std::max(maxSum, sum);
        }
        
        return maxSum;
    }

    /*
    1. Two Sum
    
    Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

    You may assume that each input would have exactly one solution, and you may not use the same element twice.

    You can return the answer in any order.
    Example 1:

    Input: nums = [2,7,11,15], target = 9
    Output: [0,1]
    Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

    */
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> _map;
        for(int i=0;i<nums.size();i++)
        {
            int num = nums[i];
            int cp = target - num;
            auto it = _map.find(cp);
            if(it!= _map.end())
                return {it->second,i};
            else
                _map[num] = i;
        }
        return {};
    }

    /*
    88. Merge Sorted Array

    You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

    Merge nums1 and nums2 into a single array sorted in non-decreasing order.

    The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

    Example 1:

    Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
    Output: [1,2,2,3,5,6]
    Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
    The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

    */

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        auto subNums1 = std::vector<int>(nums1.begin(), nums1.begin() + m);
        
        auto i = 0;
        auto j = 0;
        for (auto k = 0; k < m + n; k++)
        {
            if (i == m)
            {
                nums1[k] = nums2[j];
                j++;
                continue;
            }
            else if (j == n)
            {
                nums1[k] = subNums1[i];
                i++;
                continue;
            }
            
            if (subNums1[i] <= nums2[j])
            {
                nums1[k] = subNums1[i];
                i++;
            }
            else
            {
                nums1[k] = nums2[j];
                j++;
            }
        }
    }

    /*
    350. Intersection of Two Arrays II

    Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

    Example 1:

    Input: nums1 = [1,2,2,1], nums2 = [2,2]
    Output: [2,2]
    */

    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        auto m = std::map<int, int>();
        for (auto el : nums1)
        {
            m[el]++;
        }
        
        auto output = std::vector<int>();
        for (auto el : nums2)
        {
            auto findIt = m.find(el);
            if (findIt != m.end() && findIt->second > 0)
            {
                output.push_back(el);
                findIt->second--;
            }
        }
        
        return output;
    }

    /*
    121. Best Time to Buy and Sell Stock
    Easy

    You are given an array prices where prices[i] is the price of a given stock on the ith day.

    You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

    Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

    Example 1:

    Input: prices = [7,1,5,3,6,4]
    Output: 5
    Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
    Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
    */
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int iBuy = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[iBuy] > prices[i])
                iBuy = i;
            profit = max(profit, prices[i] - prices[iBuy]);
        }
        return profit;
    }

    /*
    566. Reshape the Matrix
    Easy

    In MATLAB, there is a handy function called reshape which can reshape an m x n matrix into a new one with a different size r x c keeping its original data.

    You are given an m x n matrix mat and two integers r and c representing the number of rows and the number of columns of the wanted reshaped matrix.

    The reshaped matrix should be filled with all the elements of the original matrix in the same row-traversing order as they were.

    If the reshape operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.

    

    Example 1:

    Input: mat = [[1,2],[3,4]], r = 1, c = 4
    Output: [[1,2,3,4]]
    */
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        auto rows = mat.size();
        
        if (rows == 0)
            return mat;
        
        auto cols = mat[0].size();
        auto nofItems = rows * cols;
            
        if (r * c != nofItems)
            return mat;
        
        auto output = std::vector<std::vector<int>>(r, std::vector<int>(c));
        
        for (auto i = 0; i < nofItems; i++)
        {
            auto originalRow = i / cols;
            auto originalCol = i % cols;
            
            auto outputRow = i / c;
            auto outputCol = i % c;
            
            output[outputRow][outputCol] = mat[originalRow][originalCol];
        }
        
        return output;
    }

    /*
    118. Pascal's Triangle
    Easy

    Given an integer numRows, return the first numRows of Pascal's triangle.

    In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

    

    Example 1:

    Input: numRows = 5
    Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
    */

    vector<int> pascal(int n, vector<int> &last)
    {
        if (n == 1)
            return {1};
        
        auto output = std::vector<int>{1};
        
        for (auto i = 0; i < last.size() - 1; i++)
        {
            output.push_back(last[i] + last[i + 1]);
        }
        output.push_back(1);
        
        return output;
    }
    
    vector<vector<int>> generate(int numRows) {
        auto output = std::vector<std::vector<int>>();
        
        auto current = std::vector<int>{1};
        for (auto i = 1; i <= numRows; i++)
        {
            current = pascal(i, current);
            output.push_back(current);
        }
        
        return output;
    }

    /*
    36. Valid Sudoku
    Medium

    Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

    Each row must contain the digits 1-9 without repetition.
    Each column must contain the digits 1-9 without repetition.
    Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

    Note:

        A Sudoku board (partially filled) could be valid but is not necessarily solvable.
        Only the filled cells need to be validated according to the mentioned rules.

    

    Example 1:

    Input: board = 
    [["5","3",".",".","7",".",".",".","."]
    ,["6",".",".","1","9","5",".",".","."]
    ,[".","9","8",".",".",".",".","6","."]
    ,["8",".",".",".","6",".",".",".","3"]
    ,["4",".",".","8",".","3",".",".","1"]
    ,["7",".",".",".","2",".",".",".","6"]
    ,[".","6",".",".",".",".","2","8","."]
    ,[".",".",".","4","1","9",".",".","5"]
    ,[".",".",".",".","8",".",".","7","9"]]
    Output: true
    */
    bool isValidSudoku(vector<vector<char>>& board) {
        std::set<char> horizontalLines[9];
        std::set<char> verticalLines[9];
        std::set<char> squares[3][3];
        
        for (auto hor = 0; hor < 3; hor++)
        {
            for (auto row = hor * 3; row < (hor + 1) * 3; row++)
            {
                for (auto ver = 0; ver < 3; ver++)
                {
                    for (auto col = ver * 3; col < (ver + 1) *  3; col++)
                    {
                        auto &cell = board[row][col];
                        if (cell == '.')
                            continue;
                        
                        auto result = horizontalLines[row].insert(cell);
                        if (!result.second)
                            return false;
                            
                        result = verticalLines[col].insert(cell);
                        if (!result.second)
                            return false;
                            
                        result = squares[hor][ver].insert(cell);
                        if (!result.second)
                            return false;
                    }
                }
            }
        }
        
        return true;
    }

    /*
    74. Search a 2D Matrix
    Medium

    Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

        Integers in each row are sorted from left to right.
        The first integer of each row is greater than the last integer of the previous row.

    

    Example 1:

    Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
    Output: true
    */

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        auto nofRows = matrix.size();
        auto nofCols = matrix[0].size();
        
        if (target < matrix[0][0])
            return false;
        else if (target > matrix[nofRows - 1][nofCols - 1])
            return false;
        
        int foundRow = 0;
        int startIndex = 0;
        int endIndex = nofRows - 1;
        while (startIndex < endIndex)
        {
            foundRow = (startIndex + endIndex) / 2;
            
            if (matrix[foundRow][0] == target)
                return true;
            else if (matrix[foundRow][0] <= target)
                startIndex = foundRow;
            else
                endIndex = foundRow;
            
            if (startIndex == endIndex - 1)
            {
                foundRow = matrix[endIndex][0] <= target ? endIndex : startIndex;
                break;
            }
        }
        
        int foundCol = 0;
        startIndex = 0;
        endIndex = nofCols - 1;
        while (startIndex < endIndex)
        {
            foundCol = (startIndex + endIndex) / 2;
            
            if (matrix[foundRow][foundCol] == target)
                return true;
            else if (matrix[foundRow][foundCol] <= target)
                startIndex = foundCol;
            else
                endIndex = foundCol;
            
            if (startIndex == endIndex - 1)
            {
                foundCol = matrix[foundRow][endIndex] <= target ? endIndex : startIndex;
                break;
            }
        }
        
        return matrix[foundRow][foundCol] == target;
    }

    /* Find the Longest Consecutive Sequence
    Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

    Input: nums = {100, 4, 200, 1, 3, 2}
    Output: 4
    Explanation: The longest consecutive sequence is {1, 2, 3, 4}, so the length is 4.
    */
    int longestConsecutiveSequence(vector<int> nums) {
        std::unordered_set<int> numSet;
        for (auto num : nums)
            numSet.insert(num);

        int longestStreak = 0;
        for (auto num : numSet)
        {
            if (numSet.find(num - 1) == numSet.end())
            {
                int currentNum = num;
                int currentStreak = 1;

                while (numSet.find(currentNum + 1) != numSet.end())
                {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = std::max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }

    void run()
    {
        std::cout << "[DataStructures][Arrays]  Start" << std::endl;
        {
            auto v = std::vector<int> {1,2,3,1};
            auto result = containsDuplicate(v);
            assert(result == true);

            std::cout << "  [PASSED] 217. Contains Duplicate" << std::endl;
        }

        {
            auto v = std::vector<int> {-2,1,-3,4,-1,2,1,-5,4};
            auto result = maxSubArray(v);

            assert(result == 6);

            std::cout << "  [PASSED] 53. Maximum Subarray" << std::endl;
        }

        {
            auto v = std::vector<int> {2,7,11,15};
            auto expected = std::vector<int>{0,1};
            auto result = twoSum(v, 9);

            assert(result == expected);

            std::cout << "  [PASSED] 1. Two Sum" << std::endl;
        }
        
        {
            auto nums1 = std::vector<int> {1,2,3,0,0,0};
            auto nums2 = std::vector<int> {2,5,6};
            auto expected = std::vector<int>{1,2,2,3,5,6};
            merge(nums1, 3, nums2, 3);

            assert(nums1 == expected);

            std::cout << "  [PASSED] 88. Merge Sorted Array" << std::endl;
        }
        
        {
            auto nums1 = std::vector<int> {1,2,2,1};
            auto nums2 = std::vector<int> {2,2};
            auto expected = std::vector<int>{2,2};
            auto result = intersect(nums1, nums2);

            assert(result == expected);

            std::cout << "  [PASSED] 350. Intersection of Two Arrays II" << std::endl;
        }

        {
            auto v = std::vector<int> {7,1,5,3,6,4};
            auto result = maxProfit(v);

            assert(result == 5);

            std::cout << "  [PASSED] 121. Best Time to Buy and Sell Stock" << std::endl;
        }

        {
            auto v = std::vector<std::vector<int>>{{1,2},{3,4}};
            auto expected = std::vector<std::vector<int>>{{1,2,3,4}};
            auto result = matrixReshape(v, 1, 4);

            assert(result == expected);

            std::cout << "  [PASSED] 566. Reshape the Matrix" << std::endl;
        }

        {
            auto expected = std::vector<std::vector<int>>{{1},{1,1},{1,2,1},{1,3,3,1},{1,4,6,4,1}};
            auto result = generate(5);

            assert(result == expected);

            std::cout << "  [PASSED] 118. Pascal's Triangle" << std::endl;
        }

        {
            auto v = std::vector<std::vector<char>> {{'5','3','.','.','7','.','.','.','.'}
                                                    ,{'6','.','.','1','9','5','.','.','.'}
                                                    ,{'.','9','8','.','.','.','.','6','.'}
                                                    ,{'8','.','.','.','6','.','.','.','3'}
                                                    ,{'4','.','.','8','.','3','.','.','1'}
                                                    ,{'7','.','.','.','2','.','.','.','6'}
                                                    ,{'.','6','.','.','.','.','2','8','.'}
                                                    ,{'.','.','.','4','1','9','.','.','5'}
                                                    ,{'.','.','.','.','8','.','.','7','9'}};
            auto result = isValidSudoku(v);

            assert(result == true);

            std::cout << "  [PASSED] 36. Valid Sudoku" << std::endl;
        }

        {
            auto v = std::vector<std::vector<int>>{{1,3,5,7},{10,11,16,20},{23,30,34,60}};
            auto result = searchMatrix(v, 3);

            assert(result == true);

            std::cout << "  [PASSED] 74. Search a 2D Matrix" << std::endl;
        }

        {
            auto v = std::vector<int>{100, 4, 200, 1, 3, 2};
            auto result = longestConsecutiveSequence(v);

            assert(result == 4);

            std::cout << "  [PASSED] Longest consecutive sequence" << std::endl;
        }

        std::cout << "[DataStructures][Arrays]  End" << std::endl;
    }
}