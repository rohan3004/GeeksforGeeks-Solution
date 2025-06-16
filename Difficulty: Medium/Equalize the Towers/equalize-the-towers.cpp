class Solution {
public:
    typedef long long ll;

    ll getCost(const vector<int>& heights, const vector<int>& cost, int target) {
        ll total = 0;
        for (int i = 0; i < heights.size(); ++i) {
            total += 1LL * abs(heights[i] - target) * cost[i];
        }
        return total;
    }

    int minCost(vector<int>& heights, vector<int>& cost) {
        int low = *min_element(heights.begin(), heights.end());
        int high = *max_element(heights.begin(), heights.end());

        while (low < high) {
            int mid1 = low + (high - low) / 3;
            int mid2 = high - (high - low) / 3;

            ll cost1 = getCost(heights, cost, mid1);
            ll cost2 = getCost(heights, cost, mid2);

            if (cost1 < cost2)
                high = mid2 - 1;
            else
                low = mid1 + 1;
        }

        // Check a few points near the final low to find minimum
        ll ans = getCost(heights, cost, low);
        for (int h = low - 2; h <= low + 2; ++h) {
            if (h >= 0) {
                ans = min(ans, getCost(heights, cost, h));
            }
        }

        return (int)ans;
    }
};
