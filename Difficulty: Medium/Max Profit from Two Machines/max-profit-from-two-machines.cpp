#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
  public:
    int maxProfit(int x, int y, vector<int> &a, vector<int> &b) {
        int n = a.size();
        long long max_profit = 0;
        vector<int> diff(n);
        
        // Assume all tasks are initially assigned to Machine B
        for(int i = 0; i < n; i++) {
            max_profit += b[i];
            diff[i] = a[i] - b[i];
        }
        
        // Sort the differences in descending order
        sort(diff.rbegin(), diff.rend());
        
        // Machine A must take at least (n - y) tasks to prevent Machine B from overflowing
        int min_A_tasks = max(0, n - y);
        
        for(int i = 0; i < n; i++) {
            // Assign to A if we haven't met A's minimum quota yet, 
            // OR if A still has capacity and assigning to A increases our total profit.
            if (i < min_A_tasks) {
                max_profit += diff[i];
            } else if (i < x && diff[i] > 0) {
                max_profit += diff[i];
            } else {
                // If diff[i] <= 0 and we've met the quota, stop moving tasks to A
                break; 
            }
        }
        
        return max_profit;
    }
};