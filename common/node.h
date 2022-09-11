#ifndef NODE_H_
#define NODE_H_

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

auto equal(Node *p, Node *q) -> bool
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
    
    if (!p->next != !q->next)
        return false;

    if (p->next && (p->next->val != q->next->val))
        return false;

    return p->val == q->val;
}

#endif