#include <vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        
        // count array to store the frequency of citations
        vector<int> count(n + 1, 0);
        
        // Populate the counts
        for (int c : citations) {
            if (c >= n) {
                count[n]++; // Cap maximum citations at n
            } else {
                count[c]++;
            }
        }
        
        int papers = 0;
        // Iterate backwards to find the maximum H-index
        for (int i = n; i >= 0; i--) {
            papers += count[i];
            
            // If the total number of papers with at least 'i' citations is >= 'i'
            if (papers >= i) {
                return i;
            }
        }
        
        return 0;
    }
};