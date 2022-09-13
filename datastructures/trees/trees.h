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

        std::cout << "[DataStructures][Trees]  End" << std::endl;
    }
}