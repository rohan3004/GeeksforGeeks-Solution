#include <vector>
#include <algorithm>

class Solution {
  public:
    int hIndex(std::vector<int>& citations) {
        int n = citations.size();
        if (n == 0) {
            return 0;
        }

        // Step 1: Counting Papers
        // Create a count array of size n+1.
        // counts[i] stores the number of papers with 'i' citations.
        // Any paper with more than 'n' citations is counted as having 'n'.
        std::vector<int> counts(n + 1, 0);
        for (int c : citations) {
            counts[std::min(c, n)]++;
        }

        // Step 2 & 3: Find the H-Index
        // Iterate from n down to 0.
        // 'papers' is the cumulative count of papers with at least h citations.
        int papers = 0;
        for (int h = n; h >= 0; --h) {
            papers += counts[h];
            
            // If the number of papers with at least 'h' citations
            // is greater than or equal to 'h', then 'h' is the H-index.
            // Since we are iterating downwards, the first 'h' that
            // satisfies this is the maximum possible value.
            if (papers >= h) {
                return h;
            }
        }

        // This line is technically unreachable because the condition will always
        // be met for h=0 (since papers will equal n, and n >= 0).
        return 0;
    }
};