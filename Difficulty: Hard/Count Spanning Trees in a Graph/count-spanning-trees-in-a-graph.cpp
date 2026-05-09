#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countSpanTree(int n, vector<vector<int>>& edges) {
        // A graph with 1 vertex needs 0 edges for a spanning tree, exactly 1 way.
        if (n <= 1) return 1;

        // Step 1 & 2 & 3: Construct the Laplacian matrix (L = D - A)
        vector<vector<double>> L(n, vector<double>(n, 0.0));
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            L[u][u] += 1.0;       // Add to degree
            L[v][v] += 1.0;
            L[u][v] -= 1.0;       // Subtract adjacency
            L[v][u] -= 1.0;
        }

        // Step 4: Create a submatrix by removing the 0-th row and 0-th column
        int N = n - 1;
        vector<vector<double>> mat(N, vector<double>(N, 0.0));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                mat[i][j] = L[i + 1][j + 1]; 
            }
        }

        // Calculate the determinant of the (n-1)x(n-1) matrix using Gaussian Elimination
        double det = 1.0;
        for (int i = 0; i < N; ++i) {
            // Find the pivot
            int pivot = i;
            for (int j = i + 1; j < N; ++j) {
                if (abs(mat[j][i]) > abs(mat[pivot][i])) {
                    pivot = j;
                }
            }

            // If the diagonal is 0, the determinant is 0 (the graph is disconnected)
            if (abs(mat[pivot][i]) < 1e-9) {
                return 0; 
            }

            // Swap rows if a larger pivot was found below
            if (pivot != i) {
                swap(mat[i], mat[pivot]);
                det *= -1.0; // Swapping rows multiplies the determinant by -1
            }

            // Eliminate entries below the pivot
            for (int j = i + 1; j < N; ++j) {
                double factor = mat[j][i] / mat[i][i];
                for (int k = i; k < N; ++k) {
                    mat[j][k] -= factor * mat[i][k];
                }
            }
        }

        // The determinant is the product of the diagonal elements
        for (int i = 0; i < N; ++i) {
            det *= mat[i][i];
        }

        // Return the rounded absolute value
        return round(abs(det));
    }
};