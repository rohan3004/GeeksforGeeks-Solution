#include <vector>
#include <algorithm>
#include <climits> // For INT_MIN

using namespace std;

class Solution {
public:
  /**
   * Calculates the maximum profit from buying and selling stocks with a one-day cooldown.
   *
   * This problem is solved using dynamic programming with state transitions,
   * optimized to use O(1) space.
   *
   * We track three states at the end of each day i:
   * 1. prev_buy: Max profit if we are HOLDING a stock.
   * We either held from yesterday (prev_buy) OR we bought today.
   * To buy today, we must have 'rested' yesterday (prev_rest).
   * So, curr_buy = max(prev_buy, prev_rest - price)
   *
   * 2. prev_sell: Max profit if we JUST SOLD a stock on day i.
   * To sell today, we must have been HOLDING yesterday (prev_buy).
   * So, curr_sell = prev_buy + price
   *
   * 3. prev_rest: Max profit if we are NOT HOLDING and NOT SELLING today.
   * We are either resting (were resting yesterday) OR we are in cooldown
   * (we sold yesterday).
   * So, curr_rest = max(prev_rest, prev_sell)
   *
   * The final answer is the max profit when we are not holding a stock,
   * which is max(prev_sell, prev_rest).
   */
  int maxProfit(vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) {
      // Cannot make a profit with 0 or 1 day
      return 0;
    }

    // Initialize states based on day 0 (i=0)
    
    // Max profit if we buy on day 0
    int prev_buy = -arr[0]; 
    
    // Max profit if we sell on day 0 (not possible)
    int prev_sell = 0; 
    
    // Max profit if we rest on day 0
    int prev_rest = 0; 

    // Iterate from the second day (i=1)
    for (int i = 1; i < n; i++) {
      
      // We must use temporary variables to store the current day's states,
      // as all calculations depend on the *previous* day's values.
      
      // State 1: Buy
      // Max of (holding from yesterday) or (buying today after resting)
      int curr_buy = max(prev_buy, prev_rest - arr[i]);
      
      // State 2: Sell
      // Must have been holding yesterday to sell today
      int curr_sell = prev_buy + arr[i];
      
      // State 3: Rest
      // Max of (resting from yesterday) or (cooling down from selling yesterday)
      int curr_rest = max(prev_rest, prev_sell);
      
      // Update the 'previous' states for the next iteration
      prev_buy = curr_buy;
      prev_sell = curr_sell;
      prev_rest = curr_rest;
    }

    // The maximum profit must be on a day where we are not holding a stock.
    // This is the maximum of the 'sell' state and the 'rest' state on the last day.
    return max(prev_sell, prev_rest);
  }
};