#include <iostream>

#include "..\..\common\treenode.h"
#include "..\..\common\node.h"

using namespace std;

namespace Algorithms::DepthFirstSearch
{
    /*
    733. Flood Fill
    Easy

    An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

    You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].

    To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.

    Return the modified image after performing the flood fill.

    Example 1:

    Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
    Output: [[2,2,2],[2,2,0],[2,0,1]]
    Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
    Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.
    */
    void dfs(vector<vector<int>> &image, int r, int c, int color, int newColor)
    {
        auto nofRows = image.size();
        auto nofCols = image[0].size();
        if (image[r][c] == color)
        {
            image[r][c] = newColor;
            if (r >= 1) dfs(image, r - 1, c, color, newColor);
            if (c >= 1) dfs(image, r, c - 1, color, newColor);
            if (r < nofRows - 1) dfs(image, r + 1, c, color, newColor);
            if (c < nofCols - 1) dfs(image, r, c + 1, color, newColor);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        auto color = image[sr][sc];
        if (color != newColor) dfs(image, sr, sc, color, newColor);
        
        return image;
    }

    /*
    695. Max Area of Island
    Medium

    You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

    The area of an island is the number of cells with a value 1 in the island.

    Return the maximum area of an island in grid. If there is no island, return 0.

    Example 1:

    Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
    Output: 6
    Explanation: The answer is not 11, because the island must be connected 4-directionally.
    */
    int countIsland(vector<vector<int>> &grid, int nofRows, int nofCols, int r, int c)
    {        
        if (grid[r][c] != 1)
            return 0;
        
        auto count = 1;
        grid[r][c] = 2;
        
        if (r < nofRows - 1) count += countIsland(grid, nofRows, nofCols, r + 1, c);
        if (c < nofCols - 1) count += countIsland(grid, nofRows, nofCols, r, c + 1);
        if (c >= 1) count += countIsland(grid, nofRows, nofCols, r, c - 1);
        if (r >= 1) count += countIsland(grid, nofRows, nofCols, r - 1, c);
        
        return count;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max = 0;
        auto rows = grid.size();
        auto cols = grid[0].size();
        
        for (auto i = 0; i < rows; i++)
        {
            for (auto j = 0; j < cols; j++)
            {
                if (grid[i][j] == 1)
                {
                    max = std::max(max, countIsland(grid, rows, cols, i, j));
                }
            }
        }
        
        return max;
    }

    /*
    617. Merge Two Binary Trees
    Easy

    You are given two binary trees root1 and root2.

    Imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not. You need to merge the two trees into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of the new tree.

    Return the merged tree.

    Note: The merging process must start from the root nodes of both trees.

    Example 1:

    Input: root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
    Output: [3,4,5,5,4,null,7]
    */
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2)
            return nullptr;
        
        auto leftVal = root1 ? root1->val : 0;
        auto rightVal = root2 ? root2->val : 0;
        auto val = leftVal + rightVal;
        
        auto leftNode1 = root1 ? root1->left : nullptr;
        auto leftNode2 = root2 ? root2->left : nullptr;
        auto rightNode1 = root1 ? root1->right : nullptr;
        auto rightNode2 = root2 ? root2->right : nullptr;
                
        auto newHead = new TreeNode(val);
        newHead->left = mergeTrees(leftNode1, leftNode2);
        newHead->right = mergeTrees(rightNode1, rightNode2);
        
        return newHead;
    }

    /*
    116. Populating Next Right Pointers in Each Node
    Medium

    You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

    struct Node {
    int val;
    Node *left;
    Node *right;
    Node *next;
    }

    Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

    Initially, all next pointers are set to NULL.

    Example 1:

    Input: root = [1,2,3,4,5,6,7]
    Output: [1,#,2,3,#,4,5,6,7,#]
    Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
    */

    void connect(Node *node1, Node *node2) {
        if (!node1 && !node2)
            return;
        
        node1->next = node2;
        
        if (node1->left)
        {
            connect(node1->left, node1->right);
            connect(node2->left, node2->right);
                    
            connect(node1->right, node2->left);
        }
    }
    
    Node* connect(Node* root) {
        if (!root)
            return nullptr;
        
        connect(root->left, root->right);
        
        return root;
    }

    void run()
    {
        std::cout << "[Algorithms][DepthFirstSearch]  Start" << std::endl;

        {
            auto v = std::vector<std::vector<int>>{{1,1,1},{1,1,0},{1,0,1}};
            auto expected = std::vector<std::vector<int>>{{2,2,2},{2,2,0},{2,0,1}};
            auto result = floodFill(v, 1, 1, 2);

            assert(result == expected);

            std::cout << "  [PASSED] 733. Flood Fill" << std::endl;
        }
        
        {
            auto v = std::vector<std::vector<int>>{{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}};
            auto result = maxAreaOfIsland(v);

            assert(result == 6);

            std::cout << "  [PASSED] 695. Max Area of Island" << std::endl;
        }
        
        {
            auto tree1 = new TreeNode(1);
            tree1->left = new TreeNode(3);
            tree1->right = new TreeNode(2);
            tree1->left->left = new TreeNode(5);
            
            auto tree2 = new TreeNode(2);
            tree2->left = new TreeNode(1);
            tree2->right = new TreeNode(3);
            tree2->left->right = new TreeNode(4);
            tree2->right->right = new TreeNode(7);
            
            auto expected = new TreeNode(3);
            expected->left = new TreeNode(4);
            expected->right = new TreeNode(5);
            expected->left->left = new TreeNode(5);
            expected->left->right = new TreeNode(4);
            expected->right->right = new TreeNode(7);

            tree1 = mergeTrees(tree1, tree2);

            assert(equal(tree1, expected));

            std::cout << "  [PASSED] 617. Merge Two Binary Trees" << std::endl;
        }
        
        {
            auto node = new Node(1);
            node->left = new Node(2);
            node->right = new Node(3);
            node->left->left = new Node(4);
            node->left->right = new Node(5);
            node->right->left = new Node(6);
            node->right->right = new Node(7);
            
            auto expected = new Node(1);
            expected->left = new Node(2);
            expected->right = new Node(3);
            expected->left->next = expected->right;
            expected->left->left = new Node(4);
            expected->left->right = new Node(5);
            expected->left->left->next = expected->left->right;
            expected->right->left = new Node(6);
            expected->left->right->next = expected->right->left;
            expected->right->right = new Node(7);
            expected->right->left->next = expected->right->right;

            node = connect(node);

            assert(equal(node, expected));

            std::cout << "  [PASSED] 116. Populating Next Right Pointers in Each Node" << std::endl;
        }

        std::cout << "[Algorithms][DepthFirstSearch]  End" << std::endl;
    }
}