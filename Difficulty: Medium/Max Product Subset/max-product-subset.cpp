#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int findMaxProduct(vector<int>& arr) {
        int n = arr.size();
        
        // Base case: If there is only one element, we have no choice but to return it.
        if (n == 1) {
            return arr[0];
        }

        long long MOD = 1e9 + 7;
        int max_neg = INT_MIN; 
        int count_neg = 0;
        int count_zero = 0;

        // First pass: Count negatives, zeroes, and find the largest negative number
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                count_zero++;
            } else if (arr[i] < 0) {
                count_neg++;
                max_neg = max(max_neg, arr[i]);
            }
        }

        // Edge case: All elements are 0
        if (count_zero == n) {
            return 0;
        }
        
        // Edge case: Only one negative number and all other elements are 0
        if (count_neg == 1 && count_zero == n - 1) {
            return 0;
        }

        long long prod = 1;
        bool skipped = false;

        // Second pass: Calculate the product
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                continue;
            }
            
            // If the total number of negatives is odd, skip the largest negative number exactly once
            if (count_neg % 2 != 0 && arr[i] == max_neg && !skipped) {
                skipped = true;
                continue;
            }
            
            // Multiply and apply modulo
            // Note: Intermediate product can be negative, which is fine in C++ long long. 
            prod = (prod * arr[i]) % MOD;
        }

        // Return the final result. 
        // Adding MOD before the final modulo operation handles C++'s negative modulo behavior safely.
        return (prod + MOD) % MOD;
    }
};