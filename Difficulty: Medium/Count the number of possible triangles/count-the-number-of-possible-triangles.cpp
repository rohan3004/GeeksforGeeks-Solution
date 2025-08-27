#include <vector>
#include <algorithm>

class Solution {
  public:
    int countTriangles(std::vector<int>& arr) {
        // Get the size of the array.
        int n = arr.size();

        // A triangle requires 3 sides. If there are fewer than 3 elements,
        // no triangles can be formed.
        if (n < 3) {
            return 0;
        }

        // Sort the array. This is the key to the optimized O(n^2) approach.
        // If a <= b <= c, we only need to check if a + b > c.
        std::sort(arr.begin(), arr.end());

        int count = 0;

        // Iterate through the array to fix the largest side of a potential triangle.
        // We start from the end because the array is sorted, so arr[i] will be the largest side 'c'.
        // The loop goes down to index 2, as we need at least two other elements for sides 'a' and 'b'.
        for (int i = n - 1; i >= 2; --i) {
            // Use a two-pointer approach to find pairs (a, b) in the subarray arr[0...i-1]
            // such that a + b > arr[i].
            int left = 0;      // Pointer to the smallest element in the subarray
            int right = i - 1; // Pointer to the largest element in the subarray

            while (left < right) {
                // Check if the current pair (arr[left], arr[right]) can form a triangle with arr[i].
                if (arr[left] + arr[right] > arr[i]) {
                    // If arr[left] + arr[right] > arr[i], it means that arr[right]
                    // can be paired with any element from arr[left] to arr[right-1]
                    // to form a valid triangle with arr[i].
                    // The number of such valid pairs is (right - left).
                    count += (right - left);

                    // We've counted all triangles with arr[right] as the second largest side.
                    // Now, let's try a smaller second largest side by moving the right pointer.
                    --right;
                } else {
                    // If arr[left] + arr[right] <= arr[i], the sum is too small.
                    // To increase the sum, we need to move the left pointer to a larger element.
                    ++left;
                }
            }
        }

        return count;
    }
};