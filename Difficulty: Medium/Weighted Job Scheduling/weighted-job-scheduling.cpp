#include <vector>
#include <algorithm> // For sort()
#include <map>       // We can also use map for DP, but vector is faster here
#include <iostream>

using namespace std;

class Solution {
private:
    /**
     * @brief Finds the index of the first job that starts at or after targetStartTime.
     * @param jobs The sorted list of jobs.
     * @param targetStartTime The end time of the current job (i.e., the earliest start time for the next job).
     * @param left The starting index (in the jobs array) for the binary search.
     * @return The index of the next compatible job, or n if no compatible job is found.
     */
    int findNextJob(vector<vector<int>>& jobs, int targetStartTime, int left) {
        int n = jobs.size();
        int right = n - 1;
        int result = n; // If no job is found, point to the base case dp[n]

        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // If this job's start time is valid
            if (jobs[mid][0] >= targetStartTime) {
                result = mid;      // This is a potential answer
                right = mid - 1; // Try to find an even earlier valid job
            } else {
                // This job starts too early, search in the right half
                left = mid + 1;
            }
        }
        return result;
    }

public:
    int maxProfit(vector<vector<int>> &jobs) {
        int n = jobs.size();
        if (n == 0) return 0;

        // Step 1: Sort jobs based on their start time.
        // The default sort for vector<vector<int>> works because it sorts
        // lexicographically, and the first element is the start time.
        sort(jobs.begin(), jobs.end());

        // Step 2: Initialize DP array.
        // dp[i] = max profit from considering jobs i...n-1
        // Size n+1 for a clean base case: dp[n] = 0 (no jobs = 0 profit)
        vector<int> dp(n + 1, 0);

        // Step 3: Iterate backwards from the last job.
        for (int i = n - 1; i >= 0; i--) {
            
            // Find the index of the next job that doesn't overlap.
            // Its start time must be >= the current job's end time (jobs[i][1]).
            // We only need to search from index i+1 onwards.
            int next_index = findNextJob(jobs, jobs[i][1], i + 1);

            // Choice 1: Take the current job (job i)
            // Profit = current profit + max profit from the next compatible job onwards
            int profit_take = jobs[i][2] + dp[next_index];

            // Choice 2: Skip the current job (job i)
            // Profit = max profit from the very next job (i+1) onwards
            int profit_skip = dp[i + 1];

            // Store the maximum of the two choices
            dp[i] = max(profit_take, profit_skip);
        }

        // Step 4: The answer is the max profit when considering all jobs (from index 0).
        return dp[0];
    }
};