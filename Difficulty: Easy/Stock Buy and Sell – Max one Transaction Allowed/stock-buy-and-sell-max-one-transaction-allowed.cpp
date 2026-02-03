#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int minPrice = INT_MAX; // Initialize to a very high value
        int maxP = 0;           // Initialize max profit to 0

        for (int price : prices) {
            // Update the minimum price encountered so far
            if (price < minPrice) {
                minPrice = price;
            }
            
            // Calculate profit if we sold at current price
            // Since we updated minPrice above, this handles the buy/sell logic correctly
            int currentProfit = price - minPrice;
            
            // Update global maximum profit
            if (currentProfit > maxP) {
                maxP = currentProfit;
            }
        }
        
        return maxP;
    }
};