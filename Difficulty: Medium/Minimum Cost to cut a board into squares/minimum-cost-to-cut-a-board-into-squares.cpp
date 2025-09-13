#include <vector>
#include <algorithm>
#include <functional>

class Solution {
 public:
  /**
   * @brief Calculates the minimum cost to cut a board into 1x1 squares.
   * * @param n The number of rows in the final grid (board height).
   * @param m The number of columns in the final grid (board width).
   * @param x A vector of costs for vertical cuts.
   * @param y A vector of costs for horizontal cuts.
   * @return The minimum total cost.
   */
  int minCost(int n, int m, std::vector<int>& x, std::vector<int>& y) {
    // The core idea is a greedy one: always perform the most expensive
    // cut available. This is because expensive cuts should be made when
    // the number of pieces they have to cut through is minimal.
    
    // Sort both cost arrays in descending order to easily access
    // the most expensive cuts.
    std::sort(x.begin(), x.end(), std::greater<int>());
    std::sort(y.begin(), y.end(), std::greater<int>());

    int h_pieces = 1; // Initially, the board is one horizontal piece.
    int v_pieces = 1; // Initially, the board is one vertical piece.
    
    int total_cost = 0;
    
    int i = 0; // Pointer for vertical costs (x, size m-1)
    int j = 0; // Pointer for horizontal costs (y, size n-1)

    // Loop while there are still cuts of both types to consider.
    while (i < m - 1 && j < n - 1) {
      // If the current vertical cut is more expensive than the horizontal one,
      // perform the vertical cut.
      if (x[i] > y[j]) {
        // The cost is the cut's value times the number of horizontal pieces
        // it must cut through.
        total_cost += x[i] * h_pieces;
        
        // A vertical cut increases the number of vertical pieces.
        v_pieces++;
        i++;
      } else {
        // Otherwise (horizontal cut is more expensive or they are equal),
        // perform the horizontal cut.
        total_cost += y[j] * v_pieces;

        // A horizontal cut increases the number of horizontal pieces.
        h_pieces++;
        j++;
      }
    }

    // After the main loop, one of the arrays might be exhausted.
    // Process the remaining cuts from the other array.

    // If there are any remaining vertical cuts, add their costs.
    while (i < m - 1) {
      total_cost += x[i] * h_pieces;
      i++;
    }

    // If there are any remaining horizontal cuts, add their costs.
    while (j < n - 1) {
      total_cost += y[j] * v_pieces;
      j++;
    }

    return total_cost;
  }
};