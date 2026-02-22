#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        long count = 0;
        int current_xor = 0;
        unordered_map<int, int> freq;
        
        // Base case: to handle subarrays starting from index 0 whose XOR is exactly k
        freq[0] = 1;
        
        for (int x : arr) {
            // Update the running XOR
            current_xor ^= x;
            
            // Calculate the required prefix XOR to get a subarray XOR of k
            int target = current_xor ^ k;
            
            // If the target exists in our map, add its frequency to the count
            if (freq.find(target) != freq.end()) {
                count += freq[target];
            }
            
            // Add the current_xor to the map for future elements to use
            freq[current_xor]++;
        }
        
        return count;
    }
};