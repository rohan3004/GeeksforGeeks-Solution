#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int maxProfit(vector<int>& arr, int k) {
        if (arr.empty()) return 0;
        
        // 'cash' represents the max profit if we are not holding a stock.
        // Initially, we have 0 profit.
        int cash = 0;
        
        // 'hold' represents the max profit if we are holding a stock.
        // If we buy the stock on day 0, our profit is -arr[0].
        int hold = -arr[0];
        
        for (int i = 1; i < arr.size(); i++) {
            // We can either keep our previous cash, or sell the stock we are holding today.
            // If we sell, we add today's price and subtract the transaction fee 'k'.
            int next_cash = max(cash, hold + arr[i] - k);
            
            // We can either keep holding the stock we have, or buy a new stock today.
            // If we buy today, we subtract today's price from our current cash.
            int next_hold = max(hold, cash - arr[i]);
            
            // Update the states for the next iteration
            cash = next_cash;
            hold = next_hold;
        }
        
        // At the end, the maximum profit will always be when we are not holding any stock.
        return cash;
    }
};