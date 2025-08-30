#include <vector>
#include <stack> // Though not used in the final optimal solution, it's a common approach.

class Solution {
 public:
  /**
   * @brief Finds the celebrity at a party.
   * @param mat The adjacency matrix where mat[i][j] = 1 if person i knows person j.
   * @return The 0-based index of the celebrity, or -1 if none exists.
   */
  int celebrity(std::vector<std::vector<int>>& mat) {
    int n = mat.size();
    if (n == 0) {
      return -1;
    }

    // Step 1: Find a potential celebrity candidate.
    // The logic is that if person 'a' knows person 'b', 'a' cannot be a celebrity.
    // Conversely, if 'a' does not know 'b', 'b' cannot be a celebrity.
    // By iterating through, we eliminate one person at each step, leaving one candidate.
    int candidate = 0;
    for (int i = 1; i < n; i++) {
      if (mat[candidate][i] == 1) {
        // If the current candidate knows person 'i', they are disqualified.
        // 'i' becomes the new potential candidate.
        candidate = i;
      }
    }

    // Step 2: Verify if the candidate is truly a celebrity.
    // We must check if the candidate knows no one (except themselves)
    // and if everyone else knows the candidate.
    for (int i = 0; i < n; i++) {
      if (i == candidate) {
        continue; // Skip checking the candidate against themselves.
      }

      // If the candidate knows person 'i' OR person 'i' does not know the candidate...
      if (mat[candidate][i] == 1 || mat[i][candidate] == 0) {
        return -1; // ...then they are not a celebrity.
      }
    }

    return candidate; // This person is the celebrity.
  }
};