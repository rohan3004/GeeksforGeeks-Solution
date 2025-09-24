#include <queue>
#include <deque>

class SpecialQueue {
    // The main queue to store elements in FIFO order.
    std::queue<int> q;
    // A deque to track minimum candidates in increasing order.
    std::deque<int> min_dq;
    // A deque to track maximum candidates in decreasing order.
    std::deque<int> max_dq;

public:
    /**
     * @brief Inserts an element at the rear of the queue.
     * @param x The integer element to insert.
     */
    void enqueue(int x) {
        // Add the element to the main queue.
        q.push(x);

        // Maintain the monotonically increasing property of min_dq.
        // Remove all elements from the back of min_dq that are greater than x.
        while (!min_dq.empty() && min_dq.back() > x) {
            min_dq.pop_back();
        }
        min_dq.push_back(x);

        // Maintain the monotonically decreasing property of max_dq.
        // Remove all elements from the back of max_dq that are smaller than x.
        while (!max_dq.empty() && max_dq.back() < x) {
            max_dq.pop_back();
        }
        max_dq.push_back(x);
    }

    /**
     * @brief Removes the element from the front of the queue.
     */
    void dequeue() {
        // Get the value of the front element before removing it.
        int front_val = q.front();
        q.pop();

        // If the dequeued element was the current minimum, remove it from min_dq.
        if (front_val == min_dq.front()) {
            min_dq.pop_front();
        }

        // If the dequeued element was the current maximum, remove it from max_dq.
        if (front_val == max_dq.front()) {
            max_dq.pop_front();
        }
    }

    /**
     * @brief Returns the front element without removing it.
     * @return The front element of the queue.
     */
    int getFront() {
        return q.front();
    }

    /**
     * @brief Returns the minimum element in the queue.
     * @return The minimum element.
     */
    int getMin() {
        return min_dq.front();
    }

    /**
     * @brief Returns the maximum element in the queue.
     * @return The maximum element.
     */
    int getMax() {
        return max_dq.front();
    }
};