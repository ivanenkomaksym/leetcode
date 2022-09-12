#include <string>

namespace DataStructures::Stacks
{
    /*
    20. Valid Parentheses
    Easy

    Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

    An input string is valid if:

        Open brackets must be closed by the same type of brackets.
        Open brackets must be closed in the correct order.
        Every close bracket has a corresponding open bracket of the same type.

    Example 1:

    Input: s = "()"
    Output: true
    */

    bool isOpen(char &ch)
    {
        if (ch == '(' || ch == '[' || ch == '{')
            return true;
        
        return false;
    }
    
    bool isSameType(char &left, char &right)
    {
        if (left == '(' && right == ')')
            return true;
        if (left == '[' && right == ']')
            return true;
        if (left == '{' && right == '}')
            return true;
        
        return false;
    }
    
    bool isValid(string s) {
        if (s.empty())
            return true;
        
        auto bracketsStack = std::stack<char>{};
        for (auto &ch : s)
        {
            if (isOpen(ch))
            {
                bracketsStack.push(ch);
            }
            else
            {
                if (bracketsStack.empty())
                    return false;
                auto &openBracket = bracketsStack.top();
                if (!isSameType(openBracket, ch))
                    return false;
                bracketsStack.pop();
            }
        }
        
        if (!bracketsStack.empty())
            return false;
        
        return true;
    }

    /*
    232. Implement Queue using Stacks
    Easy

    Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

    Implement the MyQueue class:

        void push(int x) Pushes element x to the back of the queue.
        int pop() Removes the element from the front of the queue and returns it.
        int peek() Returns the element at the front of the queue.
        boolean empty() Returns true if the queue is empty, false otherwise.

    Notes:

        You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
        Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.

    Example 1:

    Input
    ["MyQueue", "push", "push", "peek", "pop", "empty"]
    [[], [1], [2], [], [], []]
    Output
    [null, null, null, 1, 1, false]

    Explanation
    MyQueue myQueue = new MyQueue();
    myQueue.push(1); // queue is: [1]
    myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
    myQueue.peek(); // return 1
    myQueue.pop(); // return 1, queue is [2]
    myQueue.empty(); // return false

    */

    class MyQueue {
    private:
        std::stack<int> st;
            
    public:
        MyQueue() {
        }
        
        void push(int x) {
            auto temp = std::stack<int>();
            while (!st.empty())
            {
                temp.push(st.top());
                st.pop();
            }
            
            st.push(x);
            while (!temp.empty())
            {
                st.push(temp.top());
                temp.pop();
            }
        }
        
        int pop() {
            auto top = st.top();
            st.pop();
            return top;
        }
        
        int peek() {
            return st.top();
        }
        
        bool empty() {
            return st.empty();
        }
    };

    void run()
    {
        std::cout << "[DataStructures][Stacks]  Start" << std::endl;

        {
            auto s = "()";
            auto result = isValid(s);
            assert(result == true);

            std::cout << "  [PASSED] 20. Valid Parentheses" << std::endl;
        }

        {
            MyQueue myQueue;
            myQueue.push(1); // queue is: [1]
            myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
            assert(myQueue.peek() == 1); // return 1
            assert(myQueue.pop() == 1); // return 1, queue is [2]
            assert(myQueue.empty() == false); // return false

            std::cout << "  [PASSED] 232. Implement Queue using Stacks" << std::endl;
        }

        std::cout << "[DataStructures][Stacks]  End" << std::endl;
    }
}
