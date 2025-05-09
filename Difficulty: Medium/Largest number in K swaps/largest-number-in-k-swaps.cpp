//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
    string maxNum;
    
    // idx: current position to consider swapping
    // k:    remaining swaps
    void dfs(string &s, int k, int idx) {
        if (k == 0 || idx >= s.size()) return;
        
        // find the largest digit in s[idx+1..end]
        char best = s[idx];
        for (int i = idx + 1; i < s.size(); ++i)
            if (s[i] > best) best = s[i];
        
        // if there is a larger digit later, try swapping it into idx
        if (best != s[idx]) {
            // iterate from the end so that we swap with the rightmost occurrences first
            for (int j = s.size() - 1; j > idx; --j) {
                if (s[j] == best) {
                    swap(s[idx], s[j]);
                    // update global maximum if needed
                    if (s > maxNum) maxNum = s;
                    // recurse for next position with one fewer swap
                    dfs(s, k - 1, idx + 1);
                    // backtrack
                    swap(s[idx], s[j]);
                }
            }
        } else {
            // no better digit to swap here: move on without consuming a swap
            dfs(s, k, idx + 1);
        }
    }
    
public:
    string findMaximumNum(string &s, int k) {
        maxNum = s;            // initialize with the original
        dfs(s, k, 0);          // start at position 0
        return maxNum;
    }
};



//{ Driver Code Starts.

int main() {
    int t, k;
    string str;

    cin >> t;
    while (t--) {
        cin >> k >> str;
        Solution ob;
        cout << ob.findMaximumNum(str, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends