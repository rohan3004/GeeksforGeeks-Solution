#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int equalSumSpan(vector<int> &a1, vector<int> &a2) {
        int n = a1.size();
        
        // Since elements are 0 or 1, the max difference is 'n' and min is '-n'.
        // We use an array of size 2*n + 1 to store the first occurrence of each sum.
        // We initialize with -2 to indicate that a sum hasn't been seen yet.
        vector<int> first_occurrence(2 * n + 1, -2); 
        
        int max_len = 0;
        int curr_sum = 0;
        
        // Base case: A difference sum of 0 is mathematically seen at index -1.
        // We shift the index by 'n' to handle negative sums without going out of bounds.
        first_occurrence[0 + n] = -1;
        
        for (int i = 0; i < n; i++) {
            // Update the running sum of differences
            curr_sum += (a1[i] - a2[i]);
            
            // If this exact sum has been seen before...
            if (first_occurrence[curr_sum + n] != -2) {
                // Calculate the length of this span and update max_len if it's larger
                max_len = max(max_len, i - first_occurrence[curr_sum + n]);
            } else {
                // Otherwise, record the first time we've seen this sum
                first_occurrence[curr_sum + n] = i;
            }
        }
        
        return max_len;
    }
};