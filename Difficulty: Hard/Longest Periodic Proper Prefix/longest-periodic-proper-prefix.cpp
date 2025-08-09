#include <iostream>
#include <string>
#include <vector>

class Solution {
 public:
  /**
   * @brief Finds the length of the longest periodic proper prefix.
   *
   * A periodic proper prefix `p` of a string `s` is a non-empty prefix of `s` (but not the whole string)
   * such that `s` is a prefix of the infinite string formed by repeating `p`.
   *
   * This condition is equivalent to finding the largest `L` (where `1 <= L < n`) such that `s` has a 
   * border (a prefix that is also a suffix) of length `k = n-L`. To maximize `L`, we must minimize `k`.
   *
   * This function uses the KMP algorithm's LPS array to find the shortest non-empty border of `s`
   * and calculates the result from it.
   *
   * @param s The input string.
   * @return The length of the longest periodic proper prefix, or -1 if none exists.
   */
  int getLongestPrefix(string &s) {
    int n = s.length();
    // A proper prefix must have length < n. This requires n > 1.
    if (n <= 1) {
      return -1;
    }

    // Step 1: Compute the LPS (Longest Proper Prefix which is also Suffix) array.
    std::vector<int> lps(n, 0);
    int length = 0; // Length of the previous longest prefix suffix
    int i = 1;
    while (i < n) {
      if (s[i] == s[length]) {
        length++;
        lps[i] = length;
        i++;
      } else {
        if (length != 0) {
          length = lps[length - 1];
        } else {
          lps[i] = 0;
          i++;
        }
      }
    }

    // Step 2: Get the length of the longest border of `s`.
    // If it's 0, no non-empty border exists, so no such periodic prefix exists.
    int k = lps[n - 1];
    if (k == 0) {
      return -1;
    }

    // Step 3: Find the shortest non-empty border length by traversing the LPS chain.
    // The set of all border lengths is {lps[n-1], lps[lps[n-1]-1], ...}.
    // We want the smallest non-zero value in this set.
    while (lps[k - 1] > 0) {
      k = lps[k - 1];
    }

    // Step 4: The smallest border length is k.
    // The corresponding (and longest) periodic prefix has length L = n - k.
    return n - k;
  }
};