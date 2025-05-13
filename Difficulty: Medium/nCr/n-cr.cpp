//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int nCr(int n, int r) {
        // If r is more than n, no valid combinations
        if (r > n) return 0;
        
        // Take advantage of symmetry: C(n, r) == C(n, n-r)
        if (r > n - r) r = n - r;
        
        long long result = 1;
        
        // Compute result iteratively to avoid large factorials
        for (int i = 1; i <= r; ++i) {
            result = result * (n - r + i) / i;
        }
        
        return static_cast<int>(result);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, r;
        cin >> n >> r;

        Solution ob;
        cout << ob.nCr(n, r) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends