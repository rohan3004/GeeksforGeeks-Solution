#include <algorithm> // For std::min
#include <climits>   // For INT_MAX

class Solution {
 public:
  int maxKPower(int n, int k) {
    // This will store the highest power x. Initialize to a large value.
    int result = INT_MAX;
    int temp_k = k;

    // Step 1: Find prime factorization of k.
    // Iterate from 2 up to the square root of the temporary k.
    for (int i = 2; i * i <= temp_k; ++i) {
      if (temp_k % i == 0) {
        // i is a prime factor. Count its power in k.
        int count_in_k = 0;
        while (temp_k % i == 0) {
          count_in_k++;
          temp_k /= i;
        }

        // Step 2: Calculate the count of this prime 'i' in n! using Legendre's Formula.
        int count_in_n_factorial = 0;
        long long current_power = i; // Use long long to prevent overflow
        while (current_power <= n) {
          count_in_n_factorial += n / current_power;
          
          // Prevent overflow for the next power calculation
          if (current_power > n / i) {
            break;
          }
          current_power *= i;
        }

        // Step 3 & 4: The power x is limited by this prime. Update the overall minimum.
        result = std::min(result, count_in_n_factorial / count_in_k);
      }
    }

    // Handle the case where the remaining temp_k is a prime factor itself (e.g., k=7 or k=12 -> remaining k=3)
    if (temp_k > 1) {
      int prime_factor = temp_k;
      int count_in_k = 1; // Its power is 1.

      // Calculate the count of this prime in n!
      int count_in_n_factorial = 0;
      long long current_power = prime_factor;
      while (current_power <= n) {
        count_in_n_factorial += n / current_power;

        // Prevent overflow
        if (current_power > n / (long long)prime_factor) {
            break;
        }
        current_power *= prime_factor;
      }

      // Update the result
      result = std::min(result, count_in_n_factorial / count_in_k);
    }
    
    // If result is still INT_MAX, it means k=1. But constraint is k>=2.
    // If a prime factor of k is > n, its count in n! will be 0, making result 0.
    // So, we handle the case where k's prime factors might not be found or are larger than n.
    return (result == INT_MAX) ? 0 : result;
  }
};