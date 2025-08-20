#include <vector>

class Solution {
 public:
  bool searchMatrix(std::vector<std::vector<int>> &mat, int x) {
    // Get the dimensions of the matrix
    int n = mat.size();
    if (n == 0) {
      return false; // Handle empty matrix
    }
    int m = mat[0].size();
    if (m == 0) {
      return false; // Handle matrix with empty rows
    }

    // Total number of elements, acts as the size of our virtual 1D array
    int totalElements = n * m;

    // Initialize pointers for binary search
    int low = 0;
    int high = totalElements - 1;

    while (low <= high) {
      int mid = low + (high - low) / 2;

      // Convert the 1D middle index to 2D matrix coordinates
      int row = mid / m;
      int col = mid % m;
      int mid_val = mat[row][col];

      // If the middle element is the target, we found it
      if (mid_val == x) {
        return true;
      }

      // Determine which half of the array is sorted
      int low_val = mat[low / m][low % m];

      // Case 1: The left half (from low to mid) is sorted
      if (low_val <= mid_val) {
        // Check if the target is in this sorted left half
        if (x >= low_val && x < mid_val) {
          high = mid - 1; // Search left
        } else {
          low = mid + 1; // Search right
        }
      }
      // Case 2: The right half (from mid to high) is sorted
      else {
        // Check if the target is in this sorted right half
        if (x > mid_val && x <= mat[high / m][high % m]) {
          low = mid + 1; // Search right
        } else {
          high = mid - 1; // Search left
        }
      }
    }

    // If the loop completes, the target was not found
    return false;
  }
};