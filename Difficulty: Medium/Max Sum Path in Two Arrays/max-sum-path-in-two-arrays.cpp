#include <vector>
#include <algorithm>

class Solution {
  public:
    int maxPathSum(std::vector<int> &a, std::vector<int> &b) {
        int i = 0, j = 0;
        int n = a.size(), m = b.size();
        int sum1 = 0, sum2 = 0;
        int result = 0;

        // Traverse both arrays
        while (i < n && j < m) {
            if (a[i] < b[j]) {
                sum1 += a[i++];
            } else if (a[i] > b[j]) {
                sum2 += b[j++];
            } else {
                // Common element found, calculate max path up to this point
                result += std::max(sum1, sum2) + a[i];
                
                // Reset running sums
                sum1 = 0;
                sum2 = 0;
                
                // Move both pointers
                i++;
                j++;
            }
        }

        // Add remaining elements of array a (if any)
        while (i < n) {
            sum1 += a[i++];
        }

        // Add remaining elements of array b (if any)
        while (j < m) {
            sum2 += b[j++];
        }

        // Add the maximum of the final remaining sums
        result += std::max(sum1, sum2);

        return result;
    }
};