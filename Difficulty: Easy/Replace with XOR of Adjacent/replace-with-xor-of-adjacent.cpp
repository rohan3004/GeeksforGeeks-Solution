#include <vector>

class Solution {
  public:
    void replaceElements(std::vector<int>& arr) {
        int n = arr.size();
        
        // Edge case: if the array has less than 2 elements, no adjacent elements exist
        if (n < 2) return;
        
        // Store the original first element before modifying it
        int prev = arr[0];
        
        // Update the first element
        arr[0] = arr[0] ^ arr[1];
        
        // Update the middle elements
        for (int i = 1; i < n - 1; ++i) {
            int curr = arr[i];           // Store current original value
            arr[i] = prev ^ arr[i + 1];  // Calculate new value using original prev and next
            prev = curr;                 // Move prev forward
        }
        
        // Update the last element
        arr[n - 1] = prev ^ arr[n - 1];
    }
};