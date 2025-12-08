#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

class Solution {
  public:
    // Helper array to store the split point 'k' that yields the minimum cost
    int bracket[55][55]; 
    
    // Recursive function to construct the result string
    void printParenthesis(int i, int j, string &res) {
        // Base case: If only one matrix, append its name
        if (i == j) {
            res += (char)('A' + i);
            return;
        }
        
        // Recursive step: Put brackets around the current operation
        res += "(";
        
        // Recurse for the left partition
        printParenthesis(i, bracket[i][j], res);
        
        // Recurse for the right partition
        printParenthesis(bracket[i][j] + 1, j, res);
        
        res += ")";
    }

    string matrixChainOrder(vector<int> &arr) {
        int n = arr.size();     // Size of dimensions array
        int m = n - 1;          // Number of matrices
        
        // dp[i][j] = minimum number of scalar multiplications needed 
        // to multiply the chain from matrix i to matrix j.
        int dp[n][n];

        // Initialize diagonal elements (cost of multiplying one matrix is 0)
        for (int i = 0; i < n; i++)
            dp[i][i] = 0;

        // L is the chain length (number of matrices being multiplied)
        for (int L = 2; L <= m; L++) {
            // i is the starting index of the chain
            for (int i = 0; i < m - L + 1; i++) {
                // j is the ending index of the chain
                int j = i + L - 1;
                
                dp[i][j] = INT_MAX;
                
                // Try every possible split point k between i and j
                for (int k = i; k <= j - 1; k++) {
                    
                    // q = cost/scalar multiplications
                    // Cost = cost(left part) + cost(right part) + cost to multiply resulting two matrices
                    // Dimensions: Matrix i is arr[i] x arr[i+1]
                    //             Matrix k is arr[k] x arr[k+1]
                    //             Matrix j is arr[j] x arr[j+1]
                    int q = dp[i][k] + dp[k+1][j] + arr[i] * arr[k+1] * arr[j+1];
                    
                    if (q < dp[i][j]) {
                        dp[i][j] = q;
                        bracket[i][j] = k; // Store the optimal split index
                    }
                }
            }
        }

        string result = "";
        printParenthesis(0, m - 1, result);
        return result;
    }
};