#include <vector>

using namespace std;

class Solution {
public:
    int kBitFlips(vector<int>& arr, int k) {
        int n = arr.size();
        int currentFlips = 0;
        int totalOperations = 0;
        
        for (int i = 0; i < n; ++i) {
            // If our sliding window moves past a previous flip's range, 
            // we remove its effect by decrementing the flip counter.
            if (i >= k && arr[i - k] == 2) {
                currentFlips--;
            }
            
            // Calculate the effective bit value at the current index.
            // If it was 0 and flipped an even number of times, it's still 0.
            // If it was 1 and flipped an odd number of times, it becomes 0.
            if ((arr[i] + currentFlips) % 2 == 0) {
                
                // If we need to flip but there are fewer than 'k' elements left,
                // it's impossible to fix the array.
                if (i + k > n) {
                    return -1;
                }
                
                // Initiate a new flip starting at this index
                totalOperations++;
                currentFlips++;
                arr[i] = 2; // Mark this index as the start of a flip
            }
        }
        
        return totalOperations;
    }
};