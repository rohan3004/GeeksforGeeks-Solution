#include <vector>
#include <cmath>
#include <algorithm>

class Solution {
 public:
  /**
   * @brief Counts numbers less than or equal to n with exactly 9 divisors.
   *
   * A number has exactly 9 divisors if it is of the form p^8 or p1^2 * p2^2,
   * where p, p1, and p2 are prime numbers.
   *
   * @param n The upper limit (inclusive).
   * @return The count of such numbers.
   */
  int countNumbers(int n) {
    // --- Case 1: Numbers of the form p^8 ---
    // These are pre-calculated as they grow very fast.
    int count1 = 0;
    long long p8[] = {
        256LL,        // 2^8
        6561LL,       // 3^8
        390625LL,     // 5^8
        5764801LL,    // 7^8
        214358881LL,  // 11^8
        815730721LL   // 13^8
    };
    for (long long val : p8) {
      if (val <= n) {
        count1++;
      }
    }

    // --- Case 2: Numbers of the form p1^2 * p2^2 ---
    // This is equivalent to finding pairs of distinct primes (p1, p2)
    // such that p1 * p2 <= sqrt(n).
    int limit = sqrt(n);
    int count2 = 0;

    // Smallest product p1*p2 is 2*3=6. If limit < 6, no such pairs exist.
    if (limit >= 6) {
      // Generate primes up to 'limit' using Sieve of Eratosthenes.
      std::vector<bool> is_prime(limit + 1, true);
      is_prime[0] = is_prime[1] = false;
      for (int p = 2; p * p <= limit; ++p) {
        if (is_prime[p]) {
          for (int i = p * p; i <= limit; i += p) {
            is_prime[i] = false;
          }
        }
      }

      std::vector<int> primes;
      for (int p = 2; p <= limit; ++p) {
        if (is_prime[p]) {
          primes.push_back(p);
        }
      }

      // Count pairs (p1, p2) with p1 < p2 such that p1 * p2 <= limit.
      int num_primes = primes.size();
      for (int i = 0; i < num_primes; ++i) {
        long long p1 = primes[i];
        if (p1 * p1 > limit) {
          break; // Optimization: if p1*p1 > limit, then p1*p2 > limit for any p2 > p1
        }
        long long upper_p2 = limit / p1;
        // Find count of primes p2 in primes[i+1...] such that p2 <= upper_p2
        auto it = std::upper_bound(primes.begin() + i + 1, primes.end(), (int)upper_p2);
        count2 += std::distance(primes.begin() + i + 1, it);
      }
    }

    // The two cases are mutually exclusive, so we sum the counts.
    return count1 + count2;
  }
};