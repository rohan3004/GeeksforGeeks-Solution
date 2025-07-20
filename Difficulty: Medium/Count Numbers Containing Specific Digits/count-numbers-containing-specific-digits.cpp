#include <vector>
#include <cmath>
#include <numeric>
#include <unordered_set>

class Solution {
 public:
  /**
   * @brief Helper function to calculate integer power, as std::pow works with doubles.
   * @param base The base number.
   * @param exp The exponent.
   * @return The result of base raised to the power of exp.
   */
  long long power(long long base, int exp) {
    long long res = 1;
    for (int i = 0; i < exp; ++i) {
      res *= base;
    }
    return res;
  }

  int countValid(int n, std::vector<int>& arr) {
    // Step 1: Calculate the total number of n-digit positive integers.
    // First digit has 9 choices (1-9).
    // The other n-1 digits have 10 choices each (0-9).
    long long total_count = 9 * power(10, n - 1);

    // Step 2: Use complementary counting. Calculate the number of n-digit
    // numbers formed using ONLY digits NOT in arr.

    // Use a set for efficient lookup of "forbidden" digits.
    std::unordered_set<int> forbidden_digits(arr.begin(), arr.end());

    // Count the number of "allowed" digits (for the complement set).
    // c1: choices for the first digit (cannot be 0).
    // c2: choices for subsequent digits (can be 0).
    long long c1 = 0; // Count of allowed non-zero digits
    long long c2 = 0; // Count of all allowed digits

    for (int i = 0; i <= 9; ++i) {
      // Check if the digit 'i' is NOT in the forbidden set.
      if (forbidden_digits.find(i) == forbidden_digits.end()) {
        c2++; // This digit is allowed for any position other than the first.
        if (i != 0) {
          c1++; // This digit is allowed for the first position.
        }
      }
    }

    // Calculate the number of n-digit numbers with NO digits from arr.
    long long invalid_count = c1 * power(c2, n - 1);

    // Step 3: The final answer is the total count minus the invalid count.
    return static_cast<int>(total_count - invalid_count);
  }
};