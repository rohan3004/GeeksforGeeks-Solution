#include <vector>

class Solution {
 public:
  vector<vector<int>> combinationSum(int n, int k) {
    vector<vector<int>> result;
    vector<int> current_combination;
    // Start the backtracking process
    find_combinations(n, k, 1, current_combination, result);
    return result;
  }

 private:
  /**
   * @brief A recursive helper function to find combinations using backtracking.
   * * @param target The remaining sum to achieve.
   * @param k_remaining The number of elements still needed for the combination.
   * @param start_num The starting number for the current search (from 1 to 9).
   * @param current_combination The combination being built in the current recursive path.
   * @param result A reference to the list that stores all valid combinations.
   */
  void find_combinations(int target, int k_remaining, int start_num, 
                         vector<int>& current_combination, 
                         vector<vector<int>>& result) {
    
    // Base case: A valid combination is found if the target sum is reached
    // and we have used exactly k numbers.
    if (target == 0 && k_remaining == 0) {
      result.push_back(current_combination);
      return;
    }

    // Pruning: If the path is no longer viable (target is negative or we've run out of slots for numbers).
    if (target < 0 || k_remaining == 0) {
      return;
    }

    // Explore candidates for the next number in the combination.
    for (int i = start_num; i <= 9; ++i) {
      // Optimization: If the current number `i` is greater than the remaining `target`,
      // any subsequent number will also be too large, so we can stop searching.
      if (i > target) {
        break;
      }

      // 1. Choose the number `i`.
      current_combination.push_back(i);
      
      // 2. Explore further with the updated state.
      // We look for a sum of `target - i` with `k_remaining - 1` numbers, starting from `i + 1`.
      find_combinations(target - i, k_remaining - 1, i + 1, current_combination, result);
      
      // 3. Un-choose (Backtrack) to explore other possibilities.
      current_combination.pop_back();
    }
  }
};