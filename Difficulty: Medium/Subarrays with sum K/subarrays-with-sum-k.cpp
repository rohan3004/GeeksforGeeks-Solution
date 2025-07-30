#include <vector>
#include <unordered_map>

class Solution {
  public:
    int cntSubarrays(std::vector<int> &arr, int k) {
        // Use a hash map to store the frequency of each prefix sum.
        // Key: prefix sum, Value: frequency.
        // We use long long for the sum to prevent potential integer overflow.
        std::unordered_map<long long, int> prefixSumFreq;
        
        // Initialize with a prefix sum of 0 having occurred once (for an empty prefix).
        // This is crucial for subarrays that start from index 0.
        prefixSumFreq[0] = 1;
        
        int count = 0;
        long long currentSum = 0;
        
        for (int num : arr) {
            // Update the current running prefix sum.
            currentSum += num;
            
            // Calculate the required previous prefix sum we need to find.
            long long target = currentSum - k;
            
            // If the target prefix sum exists in our map, it means we have found
            // one or more subarrays ending at the current index with a sum of k.
            if (prefixSumFreq.count(target)) {
                count += prefixSumFreq[target];
            }
            
            // Increment the frequency of the current prefix sum in the map.
            prefixSumFreq[currentSum]++;
        }
        
        return count;
    }
};