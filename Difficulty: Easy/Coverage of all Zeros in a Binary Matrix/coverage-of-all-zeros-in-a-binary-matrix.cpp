class Solution {
public:
    int findCoverage(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int totalCoverage = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // We only calculate coverage for '0' cells
                if (mat[i][j] == 0) {
                    
                    // 1. Check Left
                    for (int k = j - 1; k >= 0; --k) {
                        if (mat[i][k] == 1) { 
                            totalCoverage++; 
                            break; 
                        }
                    }
                    
                    // 2. Check Right
                    for (int k = j + 1; k < n; ++k) {
                        if (mat[i][k] == 1) { 
                            totalCoverage++; 
                            break; 
                        }
                    }
                    
                    // 3. Check Up
                    for (int k = i - 1; k >= 0; --k) {
                        if (mat[k][j] == 1) { 
                            totalCoverage++; 
                            break; 
                        }
                    }
                    
                    // 4. Check Down
                    for (int k = i + 1; k < m; ++k) {
                        if (mat[k][j] == 1) { 
                            totalCoverage++; 
                            break; 
                        }
                    }
                    
                }
            }
        }
        
        return totalCoverage;
    }
};