//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int findSubString(string& str) {
        int n = str.size();
        // Count distinct characters in the string
        unordered_set<char> distinct(str.begin(), str.end());
        int required = distinct.size();

        // Frequency map for characters in current window
        vector<int> freq(256, 0);
        int formed = 0;      // Number of distinct characters currently in the window
        int minLen = n + 1;  // Initialize with a large value
        int left = 0;

        for (int right = 0; right < n; ++right) {
            char c = str[right];
            freq[c]++;
            if (freq[c] == 1) {
                // First occurrence of this char in window
                formed++;
            }

            // Try to shrink the window from the left while it still contains all required chars
            while (formed == required) {
                // Update minimum length
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                }
                // Remove the leftmost char from window
                char lc = str[left];
                freq[lc]--;
                if (freq[lc] == 0) {
                    // Lost one distinct char
                    formed--;
                }
                left++;
            }
        }

        // If minLen was not updated, no valid window found (return 0 or appropriate value)
        return (minLen == n + 1) ? 0 : minLen;
    }
};


//{ Driver Code Starts.
//      Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends