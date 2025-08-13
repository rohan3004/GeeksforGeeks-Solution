#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

class Solution {
 public:
  /**
   * @brief Calculates the minimum soldiers to add to make at least ceil(n/2) troops "lucky".
   * * A troop is "lucky" if its number of soldiers is a multiple of k.
   * * @param arr A vector of integers representing the number of soldiers in each troop.
   * @param k The integer to check for divisibility.
   * @return The minimum total number of soldiers to add.
   */
  int minSoldiers(std::vector<int>& arr, int k) {
    int n = arr.size();
    
    // If there are no troops, no soldiers need to be added.
    if (n == 0) {
        return 0;
    }

    // Calculate the required number of lucky troops, which is ceil(n / 2).
    int target_lucky_troops = (n + 1) / 2;

    // A vector to store the cost (soldiers to add) for each troop.
    std::vector<int> costs(n);

    // Calculate the cost for each troop to become "lucky".
    // The cost is the number of soldiers to add to reach the next multiple of k.
    // This can be calculated as (k - (arr[i] % k)) % k.
    for (int i = 0; i < n; ++i) {
        costs[i] = (k - (arr[i] % k)) % k;
    }

    // Sort the costs in ascending order to apply the greedy strategy.
    std::sort(costs.begin(), costs.end());

    // Sum the smallest 'target_lucky_troops' costs.
    // Use a 64-bit integer (long long) for the sum to prevent potential overflow,
    // as the sum could exceed the capacity of a 32-bit integer with max constraints.
    long long total_soldiers_to_add = 0;
    for (int i = 0; i < target_lucky_troops; ++i) {
        total_soldiers_to_add += costs[i];
    }

    // The function signature requires an int return type. We cast the result.
    return static_cast<int>(total_soldiers_to_add);
  }
};