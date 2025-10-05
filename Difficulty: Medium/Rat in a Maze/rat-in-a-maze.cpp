#include <vector>
#include <string>
#include <algorithm>

class Solution {
private:
    /**
     * @brief The recursive helper function to find all paths using backtracking.
     * * @param r The current row of the rat.
     * @param c The current column of the rat.
     * @param n The size of the maze.
     * @param maze The input maze matrix.
     * @param visited A matrix to keep track of visited cells in the current path.
     * @param path The current path string being built.
     * @param allPaths A vector to store all valid paths found.
     */
    void solve(int r, int c, int n, std::vector<std::vector<int>>& maze, 
               std::vector<std::vector<int>>& visited, std::string& path, std::vector<std::string>& allPaths) {
        
        // Base case: If we've reached the destination, add the path to our results and return.
        if (r == n - 1 && c == n - 1) {
            allPaths.push_back(path);
            return;
        }

        // Mark the current cell as visited for this path.
        visited[r][c] = 1;

        // Directions are tried in lexicographical order: D, L, R, U.
        std::string directions = "DLRU";
        int dr[] = {1, 0, 0, -1}; // Change in row for D, L, R, U
        int dc[] = {0, -1, 1, 0}; // Change in column for D, L, R, U

        for (int i = 0; i < 4; ++i) {
            int next_r = r + dr[i];
            int next_c = c + dc[i];

            // Check if the next move is safe and valid.
            if (next_r >= 0 && next_r < n && next_c >= 0 && next_c < n &&
                maze[next_r][next_c] == 1 && visited[next_r][next_c] == 0) {
                
                path.push_back(directions[i]); // Make the move
                solve(next_r, next_c, n, maze, visited, path, allPaths); // Recurse
                path.pop_back(); // Backtrack: undo the move
            }
        }

        // Backtrack: Unmark the current cell as visited to make it available for other paths.
        visited[r][c] = 0;
    }

public:
    /**
     * @brief Finds all possible paths for a rat in a maze from (0,0) to (n-1, n-1).
     * * @param maze The n x n binary matrix representing the maze.
     * @return A vector of strings containing all valid paths in lexicographical order.
     */
    std::vector<std::string> ratInMaze(std::vector<std::vector<int>>& maze) {
        int n = maze.size();
        std::vector<std::string> allPaths;

        // Edge Case: If the starting or ending cell is blocked, no path is possible.
        if (n == 0 || maze[0][0] == 0 || maze[n - 1][n - 1] == 0) {
            return allPaths; // Return an empty list.
        }

        // A matrix to keep track of visited cells in the current path.
        std::vector<std::vector<int>> visited(n, std::vector<int>(n, 0));
        std::string currentPath = "";
        
        // Start the backtracking process from the source cell (0, 0).
        solve(0, 0, n, maze, visited, currentPath, allPaths);
        
        return allPaths;
    }
};