class Solution {
public:
    vector<int> stableMarriage(vector<vector<int>> &men, vector<vector<int>> &women) {
        int n = men.size();
        
        // Precompute rankings for O(1) lookups.
        // rank[w][m] will store the rank of man m for woman w. 
        // A lower value implies a higher preference.
        vector<vector<int>> rank(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                rank[i][women[i][j]] = j;
            }
        }
        
        vector<int> women_partner(n, -1); // Currently engaged partner of each woman
        vector<bool> man_free(n, true);   // Tracks if a man is currently free
        vector<int> next_proposal(n, 0);  // Tracks the index of the next woman a man will propose to
        
        int free_count = n; // Number of free men
        
        while (free_count > 0) {
            // Find the first free man
            int m = 0;
            for (int i = 0; i < n; ++i) {
                if (man_free[i]) {
                    m = i;
                    break;
                }
            }
            
            // The woman to whom man m will propose next
            int w = men[m][next_proposal[m]++];
            
            // If woman w is free, they get engaged
            if (women_partner[w] == -1) {
                women_partner[w] = m;
                man_free[m] = false;
                free_count--;
            } else {
                // Woman w is already engaged to m1
                int m1 = women_partner[w];
                
                // Check if w prefers the new suitor m over her current partner m1
                if (rank[w][m] < rank[w][m1]) {
                    women_partner[w] = m;
                    man_free[m] = false;
                    man_free[m1] = true; // m1 is dumped and becomes free again
                }
                // If w prefers m1 over m, m remains free and will propose to his next choice later
            }
        }
        
        // Construct the final result from the men's perspective
        // result[i] denotes the woman matched with the i-th man
        vector<int> result(n);
        for (int w = 0; w < n; ++w) {
            result[women_partner[w]] = w;
        }
        
        return result;
    }
};