#include <queue>
#include <stack>

class Solution {
  public:
    void reverseQueue(std::queue<int> &q) {
        // 1. Use a stack to hold the elements temporarily.
        std::stack<int> s;

        // 2. Dequeue all elements from the queue and push them onto the stack.
        // This reverses their order because of the stack's LIFO property.
        while (!q.empty()) {
            s.push(q.front());
            q.pop();
        }

        // 3. Pop all elements from the stack and enqueue them back into the queue.
        // The elements are now in reversed order.
        while (!s.empty()) {
            q.push(s.top());
            s.pop();
        }
    }
};