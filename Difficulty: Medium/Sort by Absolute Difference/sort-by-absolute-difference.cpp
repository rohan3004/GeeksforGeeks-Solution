#include <vector>
#include <cmath>      // For std::abs
#include <algorithm>  // For std::stable_sort

class Solution {
  public:
    /**
     * @brief Rearranges the array elements based on their absolute difference with a given number x.
     * * @param arr The vector of integers to be rearranged (passed by reference).
     * @param x The reference number for calculating the absolute difference.
     */
    void rearrange(std::vector<int> &arr, int x) {
        // Use std::stable_sort to sort the array in-place.
        // It's crucial to use a stable sort to maintain the original relative order
        // of elements that have the same absolute difference from x.
        std::stable_sort(arr.begin(), arr.end(), [x](int a, int b) {
            // The lambda function [x](int a, int b) is our custom comparator.
            // It captures 'x' by value to use it inside the comparison logic.
            
            // It returns 'true' if element 'a' should come before element 'b'.
            // This condition is met if the absolute difference of 'a' from 'x'
            // is less than the absolute difference of 'b' from 'x'.
            return std::abs(a - x) < std::abs(b - x);
        });
    }
};