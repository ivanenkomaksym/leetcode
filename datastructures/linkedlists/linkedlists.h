#include "..\..\common\listnode.h"

using namespace std;

namespace DataStructures::LinkedLists
{
    /*
    141. Linked List Cycle
    Easy

    Given head, the head of a linked list, determine if the linked list has a cycle in it.

    There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

    Return true if there is a cycle in the linked list. Otherwise, return false.

    Example 1:

    Input: head = [3,2,0,-4], pos = 1
    Output: true
    Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

    */
    bool hasCycle(ListNode *head) {
        if (head == 0 || head->next == 0)
            return false;
        
        auto slow = head;
        auto fast = head->next;
        
        while (fast != nullptr && fast->next != nullptr)
        {                         
            if (fast->next == slow)
                return true;
            if (fast->next->next == slow)
                return true;
            
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return false;
    }

    /*
    21. Merge Two Sorted Lists
    Easy

    You are given the heads of two sorted linked lists list1 and list2.

    Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

    Return the head of the merged linked list.

    

    Example 1:

    Input: list1 = [1,2,4], list2 = [1,3,4]
    Output: [1,1,2,3,4,4]
    */
    void fill(ListNode *&list, ListNode *&list3, ListNode *&list3Last)
    {
        if (list3 == 0)
        {
            list3 = new ListNode(list->val);
            list3Last = list3;
        }
        else
        {
            list3Last->next = new ListNode(list->val);
            list3Last = list3Last->next;
        }
        list = list->next;
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == 0)
            return list2;
        else if (list2 == 0)
            return list1;
        
        ListNode *list3 = 0;
        ListNode *list3Last = 0;
        
        while (list1 || list2)
        {                    
            if (list1 && list2)
            {
                if (list1->val <= list2->val)
                    fill(list1, list3, list3Last);
                else
                    fill(list2, list3, list3Last);
            }
            else if (list1)
            {
                fill(list1, list3, list3Last);
            }
            else
            {
                fill(list2, list3, list3Last);
            }
        }
        
        return list3;
    }

    /*
    203. Remove Linked List Elements
    Easy

    Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

    Example 1:

    Input: head = [1,2,6,3,4,5,6], val = 6
    Output: [1,2,3,4,5]
    */

    ListNode* removeElements(ListNode* head, int val) {
        ListNode *it = nullptr;
        auto next = head;
        while (next != nullptr)
        {
            if (next == nullptr)
                return head;
            
            if (next->val == val)
            {
                if (it == nullptr)
                {
                    head = next->next;
                    delete next;
                    next = head;
                }
                else
                {
                    it->next = next->next;
                    delete next;
                    next = it->next;
                }
            }
            else
            {
                it = next;
                next = next->next;
            }
        }
        return head;
    }

    void run()
    {
        std::cout << "[DataStructures][LinkedLists]  Start" << std::endl;

        {
            auto listNode = new ListNode(3);
            listNode->next = new ListNode(2);
            listNode->next->next = new ListNode(0);
            listNode->next->next->next = new ListNode(-4);
            listNode->next->next->next->next = listNode->next;

            auto result = hasCycle(listNode);
            assert(result == true);

            std::cout << "  [PASSED] 141. Linked List Cycle" << std::endl;
        }
        
        {
            auto list1 = new ListNode(1);
            list1->next = new ListNode(2);
            list1->next->next = new ListNode(4);
            
            auto list2 = new ListNode(1);
            list2->next = new ListNode(3);
            list2->next->next = new ListNode(4);
            
            auto expected = new ListNode(1);
            expected->next = new ListNode(1);
            expected->next->next = new ListNode(2);
            expected->next->next->next = new ListNode(3);
            expected->next->next->next->next = new ListNode(4);
            expected->next->next->next->next->next = new ListNode(4);

            auto result = mergeTwoLists(list1, list2);
            assert(equal(result, expected));

            std::cout << "  [PASSED] 21. Merge Two Sorted Lists" << std::endl;
        }
        
        {            
            auto list = new ListNode(1);
            list->next = new ListNode(2);
            list->next->next = new ListNode(6);
            list->next->next->next = new ListNode(3);
            list->next->next->next->next = new ListNode(4);
            list->next->next->next->next->next = new ListNode(5);
            list->next->next->next->next->next->next = new ListNode(6);
            
            auto expected = new ListNode(1);
            expected->next = new ListNode(2);
            expected->next->next = new ListNode(3);
            expected->next->next->next = new ListNode(4);
            expected->next->next->next->next = new ListNode(5);

            list = removeElements(list, 6);
            assert(equal(list, expected));

            std::cout << "  [PASSED] 203. Remove Linked List Elements" << std::endl;
        }

        std::cout << "[DataStructures][LinkedLists]  End" << std::endl;
    }
}