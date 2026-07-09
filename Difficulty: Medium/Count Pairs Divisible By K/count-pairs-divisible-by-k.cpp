#include <vector>

class Solution {
public:
    int countKdivPairs(std::vector<int>& arr, int k) {
        long long count = 0; 
        std::vector<int> freq(k, 0);
        
        // Step 1: Count the frequencies of each remainder
        for (int num : arr) {
            freq[num % k]++;
        }
        
        // Step 2: Add combinations of elements that perfectly divide by k
        // Pairs where both elements have a remainder of 0
        count += (1LL * freq[0] * (freq[0] - 1)) / 2;
        
        // Step 3: Add combinations of elements whose remainders sum to k
        for (int i = 1; i <= k / 2; i++) {
            if (i == (k - i)) {
                // Edge case: when k is even and the remainder is exactly half of k
                // We pair elements from the same remainder group together
                count += (1LL * freq[i] * (freq[i] - 1)) / 2;
            } else {
                // Normal case: multiply the counts of the complementary remainders
                count += 1LL * freq[i] * freq[k - i];
            }
        }
        
        return count;
    }
};