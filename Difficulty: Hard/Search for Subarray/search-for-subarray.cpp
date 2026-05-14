#include <vector>

using namespace std;

class Solution {
public:
    vector<int> search(vector<int> &a, vector<int> &b) {
        int n = a.size();
        int m = b.size();
        vector<int> res;
        
        // Edge cases
        if (m == 0 || m > n) return res;

        // Step 1: Preprocess the pattern to create the LPS (Longest Prefix Suffix) array
        vector<int> lps(m, 0);
        int len = 0;
        int i = 1;
        
        while (i < m) {
            if (b[i] == b[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        // Step 2: Search for the pattern b in text a
        i = 0; // index for a
        int j = 0; // index for b
        
        while (i < n) {
            if (a[i] == b[j]) {
                i++;
                j++;
            }
            
            if (j == m) {
                // Match found, record the starting index
                res.push_back(i - j);
                // Reset j using LPS to find overlapping subarrays if they exist
                j = lps[j - 1]; 
            } else if (i < n && a[i] != b[j]) {
                // Mismatch after j matches
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        return res;
    }
};