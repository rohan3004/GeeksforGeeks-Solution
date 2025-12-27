class Solution {
public:
    // Helper function to count elements <= target in the matrix
    int countLessEqual(vector<vector<int>>& mat, int target, int n) {
        int count = 0;
        int row = n - 1;
        int col = 0;

        // Start from bottom-left corner
        while (row >= 0 && col < n) {
            if (mat[row][col] <= target) {
                // If current element is <= target, all elements in this column 
                // from row 0 to current 'row' are also <= target.
                count += (row + 1);
                col++; // Move right to check larger values
            } else {
                row--; // Move up to find smaller values
            }
        }
        return count;
    }

    int kthSmallest(vector<vector<int>> &mat, int k) {
        int n = mat.size();
        int low = mat[0][0];
        int high = mat[n-1][n-1];
        int ans = low;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Check how many numbers are <= mid
            if (countLessEqual(mat, mid, n) >= k) {
                ans = mid;      // Potentially the answer, but try to find smaller
                high = mid - 1;
            } else {
                low = mid + 1;  // Too few elements, we need a larger number
            }
        }
        return ans;
    }
};