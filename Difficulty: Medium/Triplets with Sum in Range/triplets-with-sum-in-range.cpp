#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    // Helper function to count triplets with sum less than or equal to a target value
    int countTripletsLessThanOrEqual(vector<int>& arr, int target) {
        int n = arr.size();
        int count = 0;

        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                // If the sum of the triplet is valid
                if (arr[i] + arr[left] + arr[right] <= target) {
                    // Since the array is sorted, if arr[right] forms a valid sum, 
                    // then any element between left and right will also form a valid sum with arr[i] and arr[left].
                    count += (right - left);
                    left++; // Move the left pointer forward to check new combinations
                } else {
                    // The sum is too large, move the right pointer backward to decrease the sum
                    right--;
                }
            }
        }

        return count;
    }

public:
    int countTriplets(vector<int> &arr, int l, int r) {
        // Sort the array first to enable the two-pointer approach
        sort(arr.begin(), arr.end());

        // Return the difference between triplets <= r and triplets <= l - 1
        return countTripletsLessThanOrEqual(arr, r) - countTripletsLessThanOrEqual(arr, l - 1);
    }
};