class Solution {
  public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        int low = 0, high = m - 1;
        
        while(low <= high) {
            // Find the middle column
            int mid = low + (high - low) / 2;
            
            // Find the maximum element in the current column 'mid'
            int maxRow = 0;
            for(int i = 0; i < n; i++) {
                if(mat[i][mid] > mat[maxRow][mid]) {
                    maxRow = i;
                }
            }
            
            // Get current element and neighbors
            // Use -1e9 (or a value smaller than -10^6) to represent -infinity for out of bounds
            int curr = mat[maxRow][mid];
            int left = (mid - 1 >= 0) ? mat[maxRow][mid - 1] : -1e9;
            int right = (mid + 1 < m) ? mat[maxRow][mid + 1] : -1e9;
            
            // Check if current is a peak
            if(curr >= left && curr >= right) {
                return {maxRow, mid};
            }
            
            // If left neighbor is greater, move to the left part
            if(left > curr) {
                high = mid - 1;
            } 
            // Otherwise, move to the right part
            else {
                low = mid + 1;
            }
        }
        
        return {-1, -1}; // Should not be reached
    }
};