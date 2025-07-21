#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
 public:
  /**
   * @brief Counts the number of co-prime pairs in an array.
   * * @param arr A vector of positive integers.
   * @return The number of pairs (i, j) with i < j such that gcd(arr[i], arr[j]) = 1.
   */
  int cntCoprime(std::vector<int>& arr) {
    // Find the maximum value in the array to set bounds for our calculations.
    int max_val = 0;
    if (!arr.empty()) {
        max_val = *std::max_element(arr.begin(), arr.end());
    }
    
    const int MAX_N = max_val + 1;

    // Step 1: Precompute the Mobius function μ using a linear sieve.
    // The Mobius function is essential for the Principle of Inclusion-Exclusion.
    std::vector<int> mu(MAX_N);
    std::vector<int> lp(MAX_N, 0); // Stores the least prime factor for each number.
    std::vector<int> primes;
    mu[1] = 1;

    for (int i = 2; i < MAX_N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            mu[i] = -1; // i is a prime number.
            primes.push_back(i);
        }
        for (int p : primes) {
            if (p > lp[i] || (long long)i * p >= MAX_N) {
                break;
            }
            lp[i * p] = p;
            if (p == lp[i]) {
                mu[i * p] = 0; // i*p has a squared prime factor.
            } else {
                mu[i * p] = -mu[i]; // i*p has one more distinct prime factor.
            }
        }
    }

    // Step 2: Count the frequency of each number present in the input array.
    std::vector<int> freq(MAX_N, 0);
    for (int x : arr) {
        freq[x]++;
    }

    // Step 3: For each integer 'd', count how many numbers in 'arr' are its multiples.
    std::vector<long long> count_multiples(MAX_N, 0);
    for (int d = 1; d < MAX_N; ++d) {
        for (int m = d; m < MAX_N; m += d) {
            count_multiples[d] += freq[m];
        }
    }

    // Step 4: Apply the Mobius Inversion formula to find the total count of co-prime pairs. 🚀
    // The formula is: Result = Σ [μ(d) * C(count_multiples[d], 2)] for d from 1 to max_val.
    // where C(k, 2) is the number of pairs that can be formed from k items.
    long long ans = 0;
    for (int d = 1; d < MAX_N; ++d) {
        if (mu[d] == 0) {
            continue; // Skip if μ(d) is zero.
        }
        long long count = count_multiples[d];
        long long num_pairs = count * (count - 1) / 2;
        ans += mu[d] * num_pairs;
    }

    return static_cast<int>(ans);
  }
};