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

    /*
    226. Invert Binary Tree
    Easy

    Given the root of a binary tree, invert the tree, and return its root.

    Example 1:

    Input: root = [4,2,7,1,3,6,9]
    Output: [4,7,2,9,6,3,1]
    */
    void invert(TreeNode *root)
    {        
        if (root == nullptr)
            return;
        
        auto tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        
        invert(root->left);
        invert(root->right);
    }
    
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        
        return root;
    }

    /*
    112. Path Sum
    Easy

    Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

    A leaf is a node with no children.

    

    Example 1:

    Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
    Output: true
    Explanation: The root-to-leaf path with the target sum is shown.
    */
    bool hasPathSum(TreeNode* root, int &sum, int &pathSum) {
        if (!root)
            return false;
        
        pathSum += root->val;
        
        if (!root->left && !root->right)
        {
            if (pathSum == sum)
                return true;
        }
        
        if (hasPathSum(root->left, sum, pathSum))
            return true;
        if (hasPathSum(root->right, sum, pathSum))
            return true;
        
        pathSum -= root->val;
        
        return false;
    }        
    
    bool hasPathSum(TreeNode* root, int sum) {
        auto pathSum = 0;
        return hasPathSum(root, sum, pathSum);
    }
    
    /*
    700. Search in a Binary Search Tree
    Easy

    You are given the root of a binary search tree (BST) and an integer val.

    Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

    Example 1:

    Input: root = [4,2,7,1,3], val = 2
    Output: [2,1,3]
    */
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr)
            return nullptr;
        
        if (root->val == val)
            return root;
        
        if (root->val > val && root->left != nullptr)
            return searchBST(root->left, val);
        else if (root->right != nullptr)
            return searchBST(root->right, val);
        
        return nullptr;
    }

    /*
    701. Insert into a Binary Search Tree
    Medium

    You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

    Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

    Example 1:

    Input: root = [4,2,7,1,3], val = 5
    Output: [4,2,7,1,3,5]
    */
    void insertIntoBST(TreeNode*& root, TreeNode *node, int val) {
        if (root == nullptr)
        {   
           root = new TreeNode(val);
           return;
        }
        
        if (node->val > val)
        {
            if (node->left != nullptr)
                return insertIntoBST(root, node->left, val);
            
            node->left = new TreeNode(val);
            return;
        }
        else
        {
            if (node->right != nullptr)
                return insertIntoBST(root, node->right, val);
            
            node->right = new TreeNode(val);
            return;
        }
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        insertIntoBST(root, root, val);
        
        return root;
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
        
        {
            auto tree = new TreeNode(4);
            tree->left = new TreeNode(2);
            tree->right = new TreeNode(7);
            tree->left->left = new TreeNode(1);
            tree->left->right = new TreeNode(3);
            tree->right->left = new TreeNode(6);
            tree->right->right = new TreeNode(9);
            
            auto expected = new TreeNode(4);
            expected->left = new TreeNode(7);
            expected->right = new TreeNode(2);
            expected->left->left = new TreeNode(9);
            expected->left->right = new TreeNode(6);
            expected->right->left = new TreeNode(3);
            expected->right->right = new TreeNode(1);

            auto result = invertTree(tree);
            assert(equal(result, expected) == true);

            std::cout << "  [PASSED] 226. Invert Binary Tree" << std::endl;
        }
        
        {
            auto tree = new TreeNode(5);
            tree->left = new TreeNode(4);
            tree->right = new TreeNode(8);
            tree->left->left = new TreeNode(11);
            tree->left->left->right = new TreeNode(7);
            tree->left->left->right = new TreeNode(2);
            tree->right->left = new TreeNode(13);
            tree->right->right = new TreeNode(4);
            tree->right->right->right = new TreeNode(1);

            auto result = hasPathSum(tree, 22);
            assert(result == true);

            std::cout << "  [PASSED] 112. Path Sum" << std::endl;
        }
        
        {
            auto tree = new TreeNode(4);
            tree->left = new TreeNode(2);
            tree->right = new TreeNode(7);
            tree->left->left = new TreeNode(1);
            tree->left->right = new TreeNode(3);
            
            auto expected = new TreeNode(2);
            expected->left = new TreeNode(1);
            expected->right = new TreeNode(3);

            auto result = searchBST(tree, 2);
            assert(equal(result, expected) == true);

            std::cout << "  [PASSED] 700. Search in a Binary Search Tree" << std::endl;
        }
        
        {
            auto tree = new TreeNode(4);
            tree->left = new TreeNode(2);
            tree->right = new TreeNode(7);
            tree->left->left = new TreeNode(1);
            tree->left->right = new TreeNode(3);

            auto expected = new TreeNode(4);
            expected->left = new TreeNode(2);
            expected->right = new TreeNode(7);
            expected->left->left = new TreeNode(1);
            expected->left->right = new TreeNode(3);
            expected->right->left = new TreeNode(5);

            auto result = insertIntoBST(tree, 5);
            assert(equal(result, expected) == true);

            std::cout << "  [PASSED] 701. Insert into a Binary Search Tree" << std::endl;
        }

        std::cout << "[DataStructures][Trees]  End" << std::endl;
    }
}