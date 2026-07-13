class Solution {
public:
    int minOperations(vector<int> &b) {
        int n = b.size();
        vector<bool> visited(n, false);
        
        // Array to store the maximum power of each prime factor
        // The maximum cycle length is n, so primes will not exceed n
        vector<int> max_power(n + 1, 0);

        // Find all cycles in the permutation
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                int len = 0;
                int curr = i;
                
                // Traverse the cycle to find its length
                while (!visited[curr]) {
                    visited[curr] = true;
                    curr = b[curr] - 1; // 1-based indexing to 0-based indexing
                    len++;
                }
                
                // Factorize the cycle length into prime powers
                int temp = len;
                for (int j = 2; j * j <= temp; ++j) {
                    if (temp % j == 0) {
                        int count = 0;
                        while (temp % j == 0) {
                            count++;
                            temp /= j;
                        }
                        // Update the maximum power of the prime factor 'j'
                        max_power[j] = max(max_power[j], count);
                    }
                }
                // If there's any prime factor greater than sqrt(len) left
                if (temp > 1) {
                    max_power[temp] = max(max_power[temp], 1);
                }
            }
        }

        long long ans = 1;
        long long MOD = 1e9 + 7;
        
        // Reconstruct the LCM modulo 10^9+7
        for (int i = 2; i <= n; ++i) {
            if (max_power[i] > 0) {
                for (int j = 0; j < max_power[i]; ++j) {
                    ans = (ans * i) % MOD;
                }
            }
        }
        
        return ans;
    }
};