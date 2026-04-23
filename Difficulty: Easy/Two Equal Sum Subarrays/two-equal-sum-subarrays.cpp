#include <vector>

class Solution {
public:
    bool canSplit(std::vector<int>& arr) {
        long long total_sum = 0;
        
        // Calculate the total sum of the array
        for (int num : arr) {
            total_sum += num;
        }
        
        // If the total sum is odd, it's impossible to divide into two equal parts
        if (total_sum % 2 != 0) {
            return false;
        }
        
        long long target = total_sum / 2;
        long long current_sum = 0;
        
        // Iterate up to the second-to-last element to ensure both subarrays are non-empty
        for (int i = 0; i < arr.size() - 1; ++i) {
            current_sum += arr[i];
            
            // If the running sum equals half of the total sum, we found a valid split
            if (current_sum == target) {
                return true;
            }
        }
        
        return false;
    }
};