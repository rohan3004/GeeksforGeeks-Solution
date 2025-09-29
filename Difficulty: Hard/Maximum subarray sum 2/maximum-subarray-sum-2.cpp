#include <vector>
#include <deque>
#include <algorithm>
#include <climits> // Required for LLONG_MIN

using namespace std;

class Solution {
  public:
    // Note: The return type is changed to long long to handle potential overflow
    // based on the problem constraints (n <= 10^5, arr[i] <= 10^5).
    // The maximum sum could be 10^5 * 10^5 = 10^10, which exceeds INT_MAX.
    long long maxSubarrSum(vector<int>& arr, int a, int b) {
        int n = arr.size();

        // Step 1: Compute prefix sums. Use long long to prevent overflow.
        vector<long long> prefixSum(n + 1, 0LL);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + arr[i];
        }

        // Initialize maxSum to the minimum possible long long value.
        long long maxSum = LLONG_MIN;

        // Deque to store indices j of the prefixSum array.
        // It will efficiently find the minimum prefixSum in a sliding window.
        deque<int> dq;

        // Step 2: Iterate through all possible end points of the prefix sum.
        // 'i' corresponds to prefixSum[i], where the subarray ends at arr[i-1].
        for (int i = a; i <= n; ++i) {
            
            // For a subarray ending at arr[i-1], the start prefix sum index 'j'
            // must be in the window [i-b, i-a].
            
            // As 'i' increments, the window slides. The new candidate index entering
            // the window from the right is 'i-a'.
            
            // Add the new candidate index to the deque.
            // To maintain the property that dq.front() is the minimum, we remove
            // indices from the back whose prefixSum values are >= the new one.
            int candidate_idx = i - a;
            while (!dq.empty() && prefixSum[dq.back()] >= prefixSum[candidate_idx]) {
                dq.pop_back();
            }
            dq.push_back(candidate_idx);

            // Remove indices from the front that are now outside the window's left boundary.
            if (dq.front() < i - b) {
                dq.pop_front();
            }

            // The front of the deque now holds the index of the minimum prefix sum
            // within the valid window for the current endpoint 'i'.
            long long min_prefix_in_window = prefixSum[dq.front()];
            
            // Calculate the sum of the best subarray ending at arr[i-1]
            // and update the overall maximum sum.
            maxSum = max(maxSum, prefixSum[i] - min_prefix_in_window);
        }

        return maxSum;
    }
};