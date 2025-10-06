#include <vector>

class Solution {
private:
    // Knight's move offsets in 8 directions (e.g., 2 steps in x, 1 in y)
    int move_x[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int move_y[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    /**
     * @brief Recursive utility function to solve the Knight's Tour problem using backtracking.
     * @param x The current x-coordinate of the knight.
     * @param y The current y-coordinate of the knight.
     * @param move_count The current move number.
     * @param board The n x n chessboard.
     * @param n The dimension of the chessboard.
     * @return true if a solution is found, false otherwise.
     */
    bool solveTour(int x, int y, int move_count, std::vector<std::vector<int>>& board, int n) {
        // Base case: if all squares are visited, the tour is complete.
        if (move_count == n * n) {
            return true;
        }

        // Try all 8 possible moves from the current position (x, y).
        for (int i = 0; i < 8; ++i) {
            int next_x = x + move_x[i];
            int next_y = y + move_y[i];

            // Check if the next move is valid (within the board and not yet visited).
            if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n && board[next_x][next_y] == -1) {
                // Make the move.
                board[next_x][next_y] = move_count;
                
                // Recur for the next move. If it leads to a solution, return true.
                if (solveTour(next_x, next_y, move_count + 1, board, n)) {
                    return true;
                }
                
                // Backtrack: if the move doesn't lead to a solution, undo it.
                board[next_x][next_y] = -1; 
            }
        }
        
        // If no move from this position leads to a solution, return false.
        return false;
    }

public:
    std::vector<std::vector<int>> knightTour(int n) {
        // Initialize the solution board with -1 to mark all squares as unvisited.
        std::vector<std::vector<int>> board(n, std::vector<int>(n, -1));

        // The knight starts at the top-left corner (0, 0), which is the 0th step.
        board[0][0] = 0;

        // Start the recursive backtracking from (0, 0) with the next move count as 1.
        if (solveTour(0, 0, 1, board, n)) {
            return board; // If a solution is found, return the completed board.
        }

        // If no solution exists, return an empty vector as required.
        return {};
    }
};