class Solution {
public:
    int zigzagSequence(vector<vector<int>>& mat) {
        int n = mat.size();
        
        // Base case: for a 1x1 matrix, the answer is just the single element
        if (n == 1) return mat[0][0];
        
        // Track the top two maximums and their columns for the previous row
        int prev_max1 = -1, prev_max2 = -1;
        int prev_col1 = -1, prev_col2 = -1;
        
        // Initialize the first row
        for (int j = 0; j < n; ++j) {
            if (mat[0][j] >= prev_max1) {
                prev_max2 = prev_max1;
                prev_col2 = prev_col1;
                prev_max1 = mat[0][j];
                prev_col1 = j;
            } else if (mat[0][j] > prev_max2) {
                prev_max2 = mat[0][j];
                prev_col2 = j;
            }
        }
        
        // Process the rest of the rows
        for (int i = 1; i < n; ++i) {
            int curr_max1 = -1, curr_max2 = -1;
            int curr_col1 = -1, curr_col2 = -1;
            
            for (int j = 0; j < n; ++j) {
                // Determine the best valid sum from the previous row
                int current_sum = mat[i][j];
                if (j != prev_col1) {
                    current_sum += prev_max1;
                } else {
                    current_sum += prev_max2;
                }
                
                // Update the top two maximums for the current row
                if (current_sum >= curr_max1) {
                    curr_max2 = curr_max1;
                    curr_col2 = curr_col1;
                    curr_max1 = current_sum;
                    curr_col1 = j;
                } else if (current_sum > curr_max2) {
                    curr_max2 = current_sum;
                    curr_col2 = j;
                }
            }
            
            // Move current row's maximums to previous for the next iteration
            prev_max1 = curr_max1;
            prev_max2 = curr_max2;
            prev_col1 = curr_col1;
            prev_col2 = curr_col2;
        }
        
        // The answer will be the highest valid sum at the last row
        return prev_max1;
    }
};