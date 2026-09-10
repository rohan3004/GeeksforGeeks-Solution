class Solution {
  public:
    int pairCount(int x, int y) {
        // LCM must be a multiple of GCD
        if (y % x != 0) {
            return 0;
        }

        int n = y / x;
        int distinct_prime_factors = 0;

        // Count distinct prime factors of n
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                distinct_prime_factors++;
                // Divide out all occurrences of this prime factor
                while (n % i == 0) {
                    n /= i;
                }
            }
        }

        // If n is still greater than 1, it is a prime factor itself
        if (n > 1) {
            distinct_prime_factors++;
        }

        // The number of valid pairs is 2^k
        return 1 << distinct_prime_factors;
    }
};