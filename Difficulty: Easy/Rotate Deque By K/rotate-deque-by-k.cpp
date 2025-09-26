#include <deque>
#include <algorithm> // Required for std::rotate

class Solution {
 public:
  void rotateDeque(deque<int>& dq, int type, int k) {
    int n = dq.size();
    
    // If the deque is empty or has only one element, rotation has no effect.
    if (n <= 1) {
        return;
    }
    
    // Normalize k to be within the bounds of the deque size.
    int effective_k = k % n;
    
    // If k is a multiple of n, no rotation is needed.
    if (effective_k == 0) {
        return;
    }
    
    if (type == 1) { // Right Rotation (Clockwise)
        // A right rotation by 'k' is equivalent to a left rotation by 'n - k'.
        // The element at index 'n - k' becomes the new first element.
        std::rotate(dq.begin(), dq.begin() + (n - effective_k), dq.end());
    } else { // type == 2, Left Rotation (Anti-Clockwise)
        // For a left rotation by 'k', the element at index 'k'
        // becomes the new first element.
        std::rotate(dq.begin(), dq.begin() + effective_k, dq.end());
    }
  }
};