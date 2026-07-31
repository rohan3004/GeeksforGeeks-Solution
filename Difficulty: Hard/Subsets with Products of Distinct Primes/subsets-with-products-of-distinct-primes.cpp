#include <vector>

using namespace std;

class Solution {
private:
    // Helper function to return the bitmask of primes for a given number.
    // Returns -1 if the number is not square-free (has repeating prime factors).
    int get_mask(int x) {
        int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        int mask = 0;
        for (int i = 0; i < 10; ++i) {
            if (x % primes[i] == 0) {
                mask |= (1 << i);
                x /= primes[i];
                // Check if prime factor repeats
                if (x % primes[i] == 0) return -1; 
            }
        }
        return mask;
    }

    // Modular exponentiation to quickly compute (base^exp) % MOD
    long long power(long long base, long long exp) {
        long long res = 1;
        long long mod = 1000000007;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }

public:
    int countSubsets(vector<int>& arr) {
        long long freq[31] = {0};
        for (int num : arr) {
            if (num <= 30) {
                freq[num]++;
            }
        }

        // DP array to store subset combinations for up to 1024 unique masks
        long long dp[1024] = {0};
        dp[0] = 1;
        long long MOD = 1000000007;

        for (int x = 2; x <= 30; ++x) {
            if (freq[x] == 0) continue;
            int mask = get_mask(x);
            if (mask == -1) continue; // Skip invalid numbers (e.g., 4, 8, 9, 12, etc.)

            // Iterating disjoint reads dynamically modifying combinations safely in place
            for (int m = 0; m < 1024; ++m) {
                if ((m & mask) == 0) {
                    dp[m | mask] = (dp[m | mask] + dp[m] * freq[x]) % MOD;
                }
            }
        }

        long long ans = 0;
        // Sum up configurations having at least one prime valid prime factor (> 1)
        for (int i = 1; i < 1024; ++i) {
            ans = (ans + dp[i]) % MOD;
        }

        // Combining subsets of any existing 1s in the array using Permutations & Combinations
        ans = (ans * power(2, freq[1])) % MOD;

        return ans;
    }
};