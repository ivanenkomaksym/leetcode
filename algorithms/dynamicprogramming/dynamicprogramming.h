using namespace std;

namespace Algorithms::DynamicProgramming
{
    /*
    70. Climbing Stairs
    Easy

    You are climbing a staircase. It takes n steps to reach the top.

    Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

    Example 1:

    Input: n = 2
    Output: 2
    Explanation: There are two ways to climb to the top.
    1. 1 step + 1 step
    2. 2 steps
    */
    int climbStairs(int n) {
        uint a = 1, b = 1;
        while (n--)
            a = (b += a) - a;
        return a;
    }

    /*
    120. Triangle
    Medium

    Given a triangle array, return the minimum path sum from top to bottom.

    For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

    Example 1:

    Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
    Output: 11
    Explanation: The triangle looks like:
    2
    3 4
    6 5 7
    4 1 8 3
    The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
    */

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for (int j = 0; j < n; j++) dp[n - 1][j] = triangle[n - 1][j];
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < i + 1; j++) {
                int lower_left = triangle[i][j] + dp[i + 1][j];
                int lower_right = triangle[i][j] + dp[i + 1][j + 1];
                dp[i][j] = min(lower_left, lower_right);
            }
        }
        return dp[0][0];
    }

    /*
    198. House Robber
    Medium

    You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

    Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

    Example 1:

    Input: nums = [1,2,3,1]
    Output: 4
    Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
    Total amount you can rob = 1 + 3 = 4.
    */  
    int rob(vector<int>& A, vector<int>& dp, int i) {
        if(i >= size(A)) return 0;
        if(dp[i] != -1) return dp[i];
        return dp[i] = max(rob(A, dp, i+1), A[i] + rob(A, dp, i+2));
    }
    int rob(vector<int>& A) {
        vector<int> dp(size(A),-1);
        return rob(A, dp, 0);
    }
    
    void run()
    {
        std::cout << "[Algorithms][DynamicProgramming]  Start" << std::endl;

        {
            auto result = climbStairs(10);

            assert(result == 89);

            std::cout << "  [PASSED] 70. Climbing Stairs" << std::endl;
        }
        
        {
            auto v = std::vector<std::vector<int>>{{2},{3,4},{6,5,7},{4,1,8,3}};
            auto result = minimumTotal(v);

            assert(result == 11);

            std::cout << "  [PASSED] 120. Triangle" << std::endl;
        }
        
        {
            auto v = std::vector<int>{1,2,3,1};
            auto result = rob(v);

            assert(result == 4);

            std::cout << "  [PASSED] 198. House Robber" << std::endl;
        }

        std::cout << "[Algorithms][DynamicProgramming]  End" << std::endl;
    }
}
