#include <stack>
#include <optional>
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
    
    int maxDepthIterative(TreeNode* root) {
        if (!root)
            return 0;
        
        auto maxDepth = 1;
        auto stack = std::stack<std::pair<TreeNode*, int>>();
        stack.push({root, 1});
        while (!stack.empty())
        {
            auto [node, depth] = stack.top();
            stack.pop();

            if (node->right)
                stack.push({node->right, depth + 1});
            if (node->left)
                stack.push({node->left, depth + 1});
                
            maxDepth = std::max(maxDepth, depth);
        }
        
        return maxDepth;
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

    /*
    98. Validate Binary Search Tree
    Medium

    Given the root of a binary tree, determine if it is a valid binary search tree (BST).

    A valid BST is defined as follows:

        The left subtree of a node contains only nodes with keys less than the node's key.
        The right subtree of a node contains only nodes with keys greater than the node's key.
        Both the left and right subtrees must also be binary search trees.

    Example 1:

    Input: root = [2,1,3]
    Output: true
    */
    bool isValidBST(TreeNode* root, std::optional<int> min, std::optional<int> max) {
        if (root == nullptr)
            return true;
        
        if (max)
        {
            if (root->val >= max.value())
                return false;
        
            if (root->left && root->left->val >= max.value())
                return false;
            
            if (root->right && root->right->val >= max.value())
                return false;
        }
        
        if (min)
        {
            if (root->val <= min.value())
                return false;
        
            if (root->left && root->left->val <= min.value())
                return false;
            
            if (root->right && root->right->val <= min.value())
                return false;
        }
        
        if (root->left && !isValidBST(root->left, min, root->val))
            return false;
        
        if (root->right && !isValidBST(root->right, root->val, max))
            return false;
        
        return true;
    }
    
    bool isValidBST(TreeNode* root) {
        if (root == nullptr)
            return true;
        
        return isValidBST(root->left, std::nullopt, root->val) && isValidBST(root->right, root->val, std::nullopt);
    }

    /*
    653. Two Sum IV - Input is a BST
    Easy

    Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the BST such that their sum is equal to the given target.

    Example 1:

    Input: root = [5,3,6,2,4,null,7], k = 9
    Output: true
    */
    bool findTarget(TreeNode* root, unordered_set<int> &s, int k) {
        if (root == nullptr)
            return false;        
        
        auto findIt = s.find(root->val);
        if (findIt != s.end())
            return true;
        auto cp = k - root->val;
        s.insert(cp);
        
        if (root->left != nullptr && findTarget(root->left, s, k))
            return true;
        if (root->right != nullptr && findTarget(root->right, s, k))
            return true;
        
        return false;
    }
    
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        return findTarget(root, s, k);
    }

    /*
    235. Lowest Common Ancestor of a Binary Search Tree
    Medium

    Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

    According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

    Example 1:

    Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
    Output: 6
    Explanation: The LCA of nodes 2 and 8 is 6.
    */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if ((root -> val > p -> val) && (root -> val > q -> val)) {
            return lowestCommonAncestor(root -> left, p, q);
        }
        if ((root -> val < p -> val) && (root -> val < q -> val)) {
            return lowestCommonAncestor(root -> right, p, q);
        }
        return root;
    }

    bool fillNodeParents(TreeNode* root, TreeNode* node, std::deque<TreeNode *> &parents)
    {
        if (root == nullptr)
            return false;
            
        if (root == node)
            return true;
        
        if (fillNodeParents(root->left, node, parents) || fillNodeParents(root->right, node, parents))
        {
            parents.push_front(root);
            return true;
        }

        return false;
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
            auto tree = new TreeNode(3);
            tree->left = new TreeNode(9);
            tree->right = new TreeNode(20);
            tree->right->left = new TreeNode(15);
            tree->right->right = new TreeNode(7);
            tree->right->right->left = new TreeNode(16);
            tree->right->right->left->right = new TreeNode(24);

            auto result = maxDepthIterative(tree);
            assert(result == 5);

            std::cout << "  [PASSED] 104.2 Maximum Iterative Depth of Binary Tree" << std::endl;
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
        
        {
            auto tree = new TreeNode(5);
            tree->left = new TreeNode(1);
            tree->right = new TreeNode(4);
            tree->right->left = new TreeNode(3);
            tree->right->right = new TreeNode(6);

            auto result = isValidBST(tree);
            assert(result == false);

            std::cout << "  [PASSED] 98. Validate Binary Search Tree" << std::endl;
        }
        
        {
            auto tree = new TreeNode(5);
            tree->left = new TreeNode(3);
            tree->right = new TreeNode(6);
            tree->left->left = new TreeNode(2);
            tree->left->right = new TreeNode(4);
            tree->right->right = new TreeNode(7);

            auto result = findTarget(tree, 9);
            assert(result == true);

            std::cout << "  [PASSED] 653. Two Sum IV - Input is a BST" << std::endl;
        }
        
        {
            auto tree = new TreeNode(6);
            tree->left = new TreeNode(2);
            tree->right = new TreeNode(8);
            tree->left->left = new TreeNode(0);
            tree->left->right = new TreeNode(4);
            tree->right->left = new TreeNode(7);
            tree->right->right = new TreeNode(9);
            tree->left->right->left = new TreeNode(3);
            tree->left->right->right = new TreeNode(5);

            auto result = lowestCommonAncestor(tree, tree->left, tree->right);
            assert(result == tree);

            std::cout << "  [PASSED] 235. Lowest Common Ancestor of a Binary Search Tree" << std::endl;
        }
        
        {
            //      3
            //     / \
            //    5   1
            //   / \  / \
            //  6  2 0  8
            //    / \
            //   7   4
            //
            // (4): (3) -> (5) -> (2)

            auto tree = new TreeNode(3);
            tree->left = new TreeNode(5);
            tree->right = new TreeNode(1);
            tree->left->left = new TreeNode(6);
            tree->left->right = new TreeNode(2);
            tree->right->left = new TreeNode(0);
            tree->right->right = new TreeNode(8);
            tree->left->right->left = new TreeNode(7);
            tree->left->right->right = new TreeNode(4);

            auto expectedParents = deque<TreeNode*>();
            expectedParents.push_front(tree->left->right);
            expectedParents.push_front(tree->left);
            expectedParents.push_front(tree);

            auto result = deque<TreeNode *>();
            fillNodeParents(tree, tree->left->right->right, result);
            
            assert(result.size() == expectedParents.size());
            while (!result.empty())
            {
                assert(result.front() == expectedParents.front());
                result.pop_front();
                expectedParents.pop_front();
            }
            

            std::cout << "  [PASSED] Fill node parents" << std::endl;
        }

        std::cout << "[DataStructures][Trees]  End" << std::endl;
    }
}