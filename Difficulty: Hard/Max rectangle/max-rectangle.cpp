#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
 public:
  /**
   * @brief Helper function to calculate the largest rectangular area in a histogram.
   * This is a standard algorithm that uses a monotonic stack.
   * Time Complexity: O(N), where N is the number of bars (heights.size()).
   * Space Complexity: O(N) for the stack.
   * @param heights A vector of integers representing the heights of histogram bars.
   * @return The largest area of a rectangle in the histogram.
   */
  int largestRectangleArea(vector<int>& heights) {
    stack<int> s;
    int max_area = 0;
    int n = heights.size();

    for (int i = 0; i <= n; ++i) {
      // Use a sentinel value (height 0) at the end to process all remaining bars in the stack.
      int h = (i == n) ? 0 : heights[i];
      
      // If the current bar is shorter than the bar at the stack's top,
      // it means the bar at the top can't extend further to the right.
      // So, we calculate the area with the stack's top bar as the height.
      while (!s.empty() && heights[s.top()] >= h) {
        int height = heights[s.top()];
        s.pop();
        
        // Calculate the width. The right boundary is the current index 'i'.
        // The left boundary is the index of the element now at the top of the stack.
        int width = s.empty() ? i : i - s.top() - 1;
        
        max_area = max(max_area, height * width);
      }
      
      // Push the current bar's index onto the stack.
      s.push(i);
    }
    
    return max_area;
  }
  
  /**
   * @brief Finds the maximum area of a rectangle of 1's in a binary matrix.
   * @param mat The 2D binary matrix.
   * @return The maximum area.
   */
  int maxArea(vector<vector<int>>& mat) {
    if (mat.empty() || mat[0].empty()) {
      return 0;
    }

    int rows = mat.size();
    int cols = mat[0].size();
    
    // This vector will store the heights of the histogram for the current row.
    vector<int> heights(cols, 0);
    int max_area = 0;

    // Iterate through each row of the matrix.
    for (int i = 0; i < rows; ++i) {
      // Update the heights vector based on the current row.
      // If mat[i][j] is 1, the height increases. If it's 0, the height resets.
      for (int j = 0; j < cols; ++j) {
        if (mat[i][j] == 1) {
          heights[j]++;
        } else {
          heights[j] = 0;
        }
      }
      
      // Calculate the max area for the histogram represented by the current heights
      // and update the overall maximum area.
      max_area = max(max_area, largestRectangleArea(heights));
    }

    return max_area;
  }
};