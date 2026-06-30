#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minInsAndDel(vector<int> &a, vector<int> &b) {
        vector<int> filtered_a;
        
        // Step 1: Keep only elements in 'a' that are also present in 'b'
        // Since 'b' is sorted, we can use binary search.
        for (int num : a) {
            if (binary_search(b.begin(), b.end(), num)) {
                filtered_a.push_back(num);
            }
        }
        
        // Step 2: Find the Longest Increasing Subsequence (LIS) of filtered_a
        vector<int> lis;
        for (int num : filtered_a) {
            // Find the first element in lis that is >= num
            auto it = lower_bound(lis.begin(), lis.end(), num);
            
            // If num is greater than all elements, append it
            if (it == lis.end()) {
                lis.push_back(num);
            } 
            // Otherwise, replace the found element to maintain the smallest possible tail
            else {
                *it = num;
            }
        }
        
        // The length of the LIS is our Longest Common Subsequence length
        int lcs_len = lis.size();
        
        // Step 3: Calculate minimum operations
        // Deletions from a = a.size() - lcs_len
        // Insertions into a = b.size() - lcs_len
        return a.size() + b.size() - (2 * lcs_len);
    }
};