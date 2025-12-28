#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
  public:
    // Helper function to calculate how many donuts a single chef can make in 'time'
    long long donutsInTime(int r, int time) {
        // We need to find k such that: r * k * (k + 1) / 2 <= time
        // 2 * time / r >= k^2 + k
        // For approximation, k^2 approx (2 * time / r) => k = sqrt(2 * time / r)
        // We can solve the quadratic or just use the sqrt approximation since k is monotonic.
        
        long long val = 2LL * time / r;
        long long k = sqrt(val);
        
        // Adjust k if necessary due to integer arithmetic/precision
        while (r * k * (k + 1) / 2 > time) {
            k--;
        }
        return k;
    }

    // Function to check if it is possible to make 'n' donuts in 'time'
    bool canComplete(const vector<int>& ranks, int n, int time) {
        long long totalDonuts = 0;
        for (int r : ranks) {
            totalDonuts += donutsInTime(r, time);
            if (totalDonuts >= n) return true; // Optimization: Early exit
        }
        return totalDonuts >= n;
    }

    int minTime(vector<int>& ranks, int n) {
        int minRank = *min_element(ranks.begin(), ranks.end());
        
        // Lower bound: 0
        // Upper bound: Fastest chef making all donuts alone.
        // Formula: rank * n * (n + 1) / 2
        long long high = (long long)minRank * n * (n + 1) / 2;
        long long low = 0;
        int ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (canComplete(ranks, n, mid)) {
                ans = mid;
                high = mid - 1; // Try smaller time
            } else {
                low = mid + 1; // Need more time
            }
        }
        return ans;
    }
};