class Solution {
public:
    int minCost(vector<int>& heights, vector<int>& cost) {
        int n = heights.size();
        
        vector<pair<int,long long>> towers;
        for(int i = 0; i < n; i++) {
            towers.push_back({heights[i], cost[i]});
        }
        
        sort(towers.begin(), towers.end());
        
        // Calculate total weight
        long long totalWeight = 0;
        for(auto &t : towers) {
            totalWeight += t.second;
        }
        
        // Find weighted median
        long long currWeight = 0;
        int medianHeight = 0;
        
        for(auto &t : towers) {
            currWeight += t.second;
            if(currWeight >= (totalWeight + 1) / 2) {
                medianHeight = t.first;
                break;
            }
        }
        
        // Calculate minimum cost
        long long result = 0;
        for(auto &t : towers) {
            result += 1LL * abs(t.first - medianHeight) * t.second;
        }
        
        return result;
    }
};
