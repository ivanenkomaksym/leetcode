#include <stack>
#include <algorithm>

namespace DataStructures::Stacks
{
    class MinStack
    {
    public:
        MinStack() = default;
        void push(int x)
        {
            st.push(x);
            if (minSt.empty() || x <= minSt.top())
                minSt.push(x);
        }
        void pop()
        {
            if (top() == minSt.top())
                minSt.pop();
                
            st.pop();
        }
        
        int top()
        {
            return st.top();
        }
        
        int getMin()
        {
            return minSt.top();
        }

    private:
        std::stack<int> st;
        std::stack<int> minSt;
    };
}