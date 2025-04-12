//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
 void dfs(vector<vector<int>>& image, int sr, int sc, int originalColor, int newColor) {
            int n = image.size();
            int m = image[0].size();
            
            // Boundary condition or if the pixel is already filled with new color
            if (sr < 0 || sc < 0 || sr >= n || sc >= m || image[sr][sc] != originalColor || image[sr][sc] == newColor) {
                return;
            }
    
            // Fill the pixel with the new color
            image[sr][sc] = newColor;
    
            // Perform DFS in all 4 directions
            dfs(image, sr + 1, sc, originalColor, newColor); // Down
            dfs(image, sr - 1, sc, originalColor, newColor); // Up
            dfs(image, sr, sc + 1, originalColor, newColor); // Right
            dfs(image, sr, sc - 1, originalColor, newColor); // Left
        }
    
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
            int originalColor = image[sr][sc];
            dfs(image, sr, sc, originalColor, newColor);
            return image;
        }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends