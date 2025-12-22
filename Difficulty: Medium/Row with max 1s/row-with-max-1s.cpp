class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int n = arr.size();
        if (n == 0) return -1;
        int m = arr[0].size();
        
        // Start from the top-right corner
        int col = m - 1;
        int maxRowIndex = -1;
        
        // Traverse each row
        for (int row = 0; row < n; ++row) {
            // Move left as long as we see 1s
            // If we find a 1 at the current 'col', it means this row
            // has more 1s (or extends the max found so far)
            while (col >= 0 && arr[row][col] == 1) {
                maxRowIndex = row; // Update the result to the current row
                col--;             // Move left
            }
        }
        
        return maxRowIndex;
    }
};