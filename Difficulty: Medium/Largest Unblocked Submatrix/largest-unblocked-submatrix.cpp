#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int largestArea(int n, int m, vector<vector<int>> &arr) {
        // Vectors to store blocked rows and columns, including the grid boundaries
        vector<int> rows = {0, n + 1};
        vector<int> cols = {0, m + 1};
        
        // Populate the blocked rows and columns from the input array
        for (const auto& cell : arr) {
            rows.push_back(cell[0]);
            cols.push_back(cell[1]);
        }
        
        // Sort the blocked coordinates to find continuous gaps
        sort(rows.begin(), rows.end());
        sort(cols.begin(), cols.end());
        
        int max_row_gap = 0;
        int max_col_gap = 0;
        
        // Find the maximum continuous unblocked row segment
        for (int i = 1; i < rows.size(); ++i) {
            max_row_gap = max(max_row_gap, rows[i] - rows[i - 1] - 1);
        }
        
        // Find the maximum continuous unblocked column segment
        for (int i = 1; i < cols.size(); ++i) {
            max_col_gap = max(max_col_gap, cols[i] - cols[i - 1] - 1);
        }
        
        // The maximum area is the product of the maximum contiguous gaps
        return max_row_gap * max_col_gap;
    }
};