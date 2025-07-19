#include <string>
#include <map>
#include <vector>

class Solution {
public:
  /**
   * @brief Calculates the total number of distinct strings that can be formed by permuting selected vowels.
   * * The logic follows two main steps:
   * 1.  Calculate the number of ways to choose the vowels:
   * - First, we count the occurrences of each vowel ('a', 'e', 'i', 'o', 'u') in the input string.
   * - The total number of ways to select one of each unique vowel is the product of their counts.
   * - For example, in "aacidf", 'a' appears twice and 'i' appears once. The number of ways to
   * choose one 'a' and one 'i' is 2 * 1 = 2.
   * * 2.  Calculate the number of ways to arrange the chosen vowels:
   * - For each set of chosen vowels, we can arrange them in different orders (permutations).
   * - If there are 'k' unique vowels, there are k! (k-factorial) ways to arrange them.
   * - For "aacidf", there are 2 unique vowels ('a', 'i'), so there are 2! = 2 permutations ("ai", "ia").
   *
   * The final result is the product of these two values. For "aacidf", it's 2 * 2 = 4.
   * * @param s The input lowercase string.
   * @return The total number of distinct strings that can be formed.
   */
  int vowelCount(std::string& s) {
    // Step 1: Count the frequency of each vowel in the string using iterators for compatibility.
    std::map<char, int> vowel_counts;
    for (std::string::iterator it = s.begin(); it != s.end(); ++it) {
      char c = *it;
      if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        vowel_counts[c]++;
      }
    }

    // If no vowels are present, no strings can be formed according to the rules.
    if (vowel_counts.empty()) {
      return 0;
    }

    // Step 2: Calculate the product of the counts of each unique vowel using iterators.
    // This gives the total number of ways to choose one of each type.
    // We use long long to prevent potential overflow with intermediate calculations.
    long long choice_combinations = 1;
    for (std::map<char, int>::const_iterator it = vowel_counts.begin(); it != vowel_counts.end(); ++it) {
      choice_combinations *= it->second;
    }

    // Step 3: Get the number of unique vowels, which is the size of our map.
    int num_unique_vowels = vowel_counts.size();

    // Step 4: Calculate the factorial of the number of unique vowels.
    // This gives the number of permutations for any single set of chosen vowels.
    long long permutations = 1;
    for (int i = 1; i <= num_unique_vowels; ++i) {
      permutations *= i;
    }

    // Step 5: The total number of distinct strings is the product of the
    // combinations of choices and the permutations of arrangements.
    return static_cast<int>(choice_combinations * permutations);
  }
};
