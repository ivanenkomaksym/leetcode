#ifndef LISTNODE_H_
#define LISTNODE_H_
 
 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

auto equal(ListNode *list1, ListNode *list2) -> bool
{
    while (list1 != nullptr && list2 != nullptr)
    {
        if (list1->val != list2->val)
            return false;

        list1 = list1->next;
        list2 = list2->next;
    }
    
    if ((list1 == nullptr) != (list2 == nullptr))
        return false;

    return true;
}

auto print(ListNode *list) -> void
{
    while (list != nullptr)
    {
        std::cout << list->val << " -> ";
        list = list->next;
    }
    std::cout << std::endl;
}

#endif