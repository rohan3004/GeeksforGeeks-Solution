#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
 public:
  // Function to find the minimum and maximum amount of money to buy all candies.
  std::vector<int> minMaxCandy(std::vector<int>& prices, int k) {
    // Get the total number of candies.
    int n = prices.size();
    
    // Sort the candy prices in ascending order.
    sort(prices.begin(), prices.end());
    
    // --- Calculate Minimum Cost ---
    // Strategy: Buy the cheapest candy and get the k most expensive for free.
    int min_cost = 0;
    int i = 0;
    int j = n - 1;
    while (i <= j) {
      // Buy the cheapest available candy.
      min_cost += prices[i];
      i++;
      
      // Get the k most expensive available candies for free.
      j -= k;
    }
    
    // --- Calculate Maximum Cost ---
    // Strategy: Buy the most expensive candy and get the k cheapest for free.
    int max_cost = 0;
    // Reset pointers for the second calculation.
    i = 0; 
    j = n - 1;
    while (i <= j) {
      // Buy the most expensive available candy.
      max_cost += prices[j];
      j--;
      
      // Get the k cheapest available candies for free.
      i += k;
    }
    
    return {min_cost, max_cost};
  }
};