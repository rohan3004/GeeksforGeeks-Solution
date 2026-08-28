class Solution {
public:
    int minCost(vector<vector<int>>& mat) {
        int n = mat.size();
        if (n == 0) return 0;

        // Initialize costs for the first row
        int cost0 = mat[0][0];
        int cost1 = mat[0][1];
        int cost2 = mat[0][2];

        // Iterate from the second row to the end
        for (int i = 1; i < n; ++i) {
            // Calculate the minimum cost for each choice in the current row
            // by taking the current cost + the minimum of the OTHER two choices from the previous row
            int next_cost0 = mat[i][0] + min(cost1, cost2);
            int next_cost1 = mat[i][1] + min(cost0, cost2);
            int next_cost2 = mat[i][2] + min(cost0, cost1);

            // Update the costs for the next iteration
            cost0 = next_cost0;
            cost1 = next_cost1;
            cost2 = next_cost2;
        }

        // The answer is the minimum among the three possible choices ending at the last row
        return min({cost0, cost1, cost2});
    }
};