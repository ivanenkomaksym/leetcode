#include <stack>
#include <vector>

#include "..\..\common\treenode.h"

using namespace std;

namespace DataStructures::Trees
{

    /*
    144. Binary Tree Preorder Traversal
    Easy

    Given the root of a binary tree, return the preorder traversal of its nodes' values.

    Example 1:

    Input: root = [1,null,2,3]
    Output: [1,2,3]
    */
    vector<int> preorderTraversal(TreeNode* root) {
        auto result = std::vector<int>{};
        
        if (!root)
            return result;
        
        auto stack = std::stack<TreeNode *>();
        stack.push(root);
        while (!stack.empty())
        {
            auto node = stack.top();
            stack.pop();
            result.push_back(node->val);
            if (node->right)
                stack.push(node->right);
            if (node->left)
                stack.push(node->left);
            
        }
        
        return result;
    }

    /*
    94. Binary Tree Inorder Traversal
    Easy

    Given the root of a binary tree, return the inorder traversal of its nodes' values.

    Example 1:

    Input: root = [1,null,2,3]
    Output: [1,3,2]
    */
    void inorderTraverse(TreeNode *node, std::vector<int> &nums)
    {
        if (!node)
            return;
        
        inorderTraverse(node->left, nums);
        
        nums.push_back(node->val);
        
        inorderTraverse(node->right, nums);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        auto result = std::vector<int>{};
        
        if (!root)
            return result;
        
        inorderTraverse(root, result);
        
        return result;
    }

    /*
    145. Binary Tree Postorder Traversal
    Easy

    Given the root of a binary tree, return the postorder traversal of its nodes' values.

    Example 1:

    Input: root = [1,null,2,3]
    Output: [3,2,1]
    */    
    void postorderTraverse(TreeNode *node, std::vector<int> &nums)
    {
        if (!node)
            return;
        
        postorderTraverse(node->left, nums);
        
        postorderTraverse(node->right, nums);
        
        nums.push_back(node->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        auto result = std::vector<int>{};
        
        if (!root)
            return result;
        
        postorderTraverse(root, result);
        
        return result;
    }

    /*
    102. Binary Tree Level Order Traversal
    Medium

    Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

    Example 1:

    Input: root = [3,9,20,null,null,15,7]
    Output: [[3],[9,20],[15,7]]
    */
    vector<vector<int>> levelOrder(TreeNode* root) {
        auto result = std::vector<std::vector<int>>{};
        
        if (!root)
            return result;
        
        auto s = std::stack<std::pair<TreeNode *, int>>{};
        s.push({root, 0});
        while (!s.empty())
        {
            auto nodePair = s.top();
            s.pop();
            auto node = nodePair.first;
            auto currentLevel = nodePair.second;
            
            if (currentLevel >= result.size())
                result.push_back({});
            result[currentLevel].push_back(node->val);
            
            if (node->right)
                s.push({node->right, currentLevel + 1});
            if (node->left)
                s.push({node->left, currentLevel + 1});
        }
        
        return result;
    }

    /*
    104. Maximum Depth of Binary Tree
    Easy

    Given the root of a binary tree, return its maximum depth.

    A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

    Example 1:

    Input: root = [3,9,20,null,null,15,7]
    Output: 3
    */
    void maxDepth(TreeNode* root, int depth, int &answer) {
        if (!root)
            return;
        
        if (!root->left && !root->right)
        {
            answer = std::max(answer, depth);
            return;
        }
        
        maxDepth(root->left, depth + 1, answer);
        maxDepth(root->right, depth + 1, answer);
    }
    
    int maxDepth(TreeNode* root) {
        auto answer = 0;
        maxDepth(root, 1, answer);
        return answer;
    }

    /*
    101. Symmetric Tree
    Easy

    Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

    Example 1:

    Input: root = [1,2,2,3,4,4,3]
    Output: true
    */
    bool isSymmetric(TreeNode* left, TreeNode *right) {
        if (!left && !right)
            return true;
        
        if (!left != !right)
            return false;
        
        if (left->val != right->val)
            return false;
        
        if (!isSymmetric(left->left, right->right))
            return false;
        
        if (!isSymmetric(left->right, right->left))
            return false;
        
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        return isSymmetric(root->left, root->right);        
    }

    void run()
    {
        std::cout << "[DataStructures][Trees]  Start" << std::endl;

        {
            auto tree = new TreeNode(1);
            tree->right = new TreeNode(2);
            tree->right->left = new TreeNode(3);

            auto expected = std::vector<int>{1,2,3};
            auto result = preorderTraversal(tree);
            assert(result == expected);

            std::cout << "  [PASSED] 144. Binary Tree Preorder Traversal" << std::endl;
        }
        
        {
            auto tree = new TreeNode(1);
            tree->right = new TreeNode(2);
            tree->right->left = new TreeNode(3);

            auto expected = std::vector<int>{1,3,2};
            auto result = inorderTraversal(tree);
            assert(result == expected);

            std::cout << "  [PASSED] 94. Binary Tree Inorder Traversal" << std::endl;
        }
        
        {
            auto tree = new TreeNode(1);
            tree->right = new TreeNode(2);
            tree->right->left = new TreeNode(3);

            auto expected = std::vector<int>{3,2,1};
            auto result = postorderTraversal(tree);
            assert(result == expected);

            std::cout << "  [PASSED] 145. Binary Tree Postorder Traversal" << std::endl;
        }
        
        {
            auto tree = new TreeNode(3);
            tree->left = new TreeNode(9);
            tree->right = new TreeNode(20);
            tree->right->left = new TreeNode(15);
            tree->right->right = new TreeNode(7);
            
            auto expected = std::vector<std::vector<int>>{{3}, {9,20}, {15,7}};

            auto result = levelOrder(tree);
            assert(result == expected);

            std::cout << "  [PASSED] 102. Binary Tree Level Order Traversal" << std::endl;
        }
        
        {
            auto tree = new TreeNode(3);
            tree->left = new TreeNode(9);
            tree->right = new TreeNode(20);
            tree->right->left = new TreeNode(15);
            tree->right->right = new TreeNode(7);

            auto result = maxDepth(tree);
            assert(result == 3);

            std::cout << "  [PASSED] 104. Maximum Depth of Binary Tree" << std::endl;
        }
        
        {
            auto tree = new TreeNode(1);
            tree->left = new TreeNode(2);
            tree->right = new TreeNode(2);
            tree->left->left = new TreeNode(3);
            tree->left->right = new TreeNode(4);
            tree->right->left = new TreeNode(4);
            tree->right->right = new TreeNode(3);

            auto result = isSymmetric(tree);
            assert(result == true);

            std::cout << "  [PASSED] 101. Symmetric Tree" << std::endl;
        }

        std::cout << "[DataStructures][Trees]  End" << std::endl;
    }
}