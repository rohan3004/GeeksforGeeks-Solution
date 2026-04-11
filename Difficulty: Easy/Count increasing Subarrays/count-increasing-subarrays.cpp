#include <vector>
using namespace std;

class Solution {
  public:
    int countIncreasing(vector<int>& arr) {
        int n = arr.size();
        if (n < 2) return 0;
        
        int count = 0;
        int len = 1;
        
        for (int i = 1; i < n; i++) {
            // If strictly increasing, increment the current sequence length
            if (arr[i] > arr[i - 1]) {
                len++;
                // Add the number of new valid subarrays ending at index i
                count += (len - 1);
            } 
            // If the sequence breaks, reset the length counter
            else {
                len = 1;
            }
        }
        
        return count;
    }
};