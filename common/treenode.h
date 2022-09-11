#ifndef TREENODE_H_
#define TREENODE_H_
 
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

auto equal(TreeNode *p, TreeNode *q) -> bool
{
    if (!p && !q)
        return true;
    
    if (!p != !q)
        return false;
    
    if (!p->left != !q->left)
        return false;
    
    if (p->left)
        if (!equal(p->left, q->left))
            return false;
    
    if (!p->right != !q->right)
        return false;
    
    if (p->right)
        if (!equal(p->right, q->right))
            return false;
    
    return p->val == q->val;
}

#endif