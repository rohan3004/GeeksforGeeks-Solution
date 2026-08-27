class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        int n = mat.size();
        if (n == 0) return 0;
        int m = mat[0].size();
        if (m == 0) return 0;

        // This will store the height of consecutive 1s for each column
        vector<int> curr_hist(m, 0);
        int max_area = 0;

        for (int i = 0; i < n; ++i) {
            // 1. Update the heights for the current row
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 1) {
                    curr_hist[j]++;
                } else {
                    curr_hist[j] = 0; // Reset height if we hit a 0
                }
            }

            // 2. Make a copy to sort, keeping original order intact for the next row calculations
            vector<int> sorted_hist = curr_hist;

            // Sort heights in descending order to maximize grouped heights
            sort(sorted_hist.begin(), sorted_hist.end(), greater<int>());

            // 3. Calculate max area for rectangles ending at the current row
            for (int j = 0; j < m; ++j) {
                // Area = height * width
                int area = sorted_hist[j] * (j + 1);
                max_area = max(max_area, area);
            }
        }

        return max_area;
    }
};