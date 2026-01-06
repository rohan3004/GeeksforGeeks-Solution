#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        int n = arr.size();
        
        // Edge case: if k is larger than array size (though constraints say k <= size)
        if (k > n) return -1; 

        int current_xor = 0;

        // 1. Calculate XOR of the first window (indices 0 to k-1)
        for (int i = 0; i < k; i++) {
            current_xor ^= arr[i];
        }

        int max_xor = current_xor;

        // 2. Slide the window across the rest of the array
        for (int i = k; i < n; i++) {
            // XOR with arr[i-k] removes the element leaving the window
            // XOR with arr[i] adds the new element entering the window
            current_xor = current_xor ^ arr[i-k] ^ arr[i];
            
            // Update the maximum result found so far
            max_xor = max(max_xor, current_xor);
        }

        return max_xor;
    }
};