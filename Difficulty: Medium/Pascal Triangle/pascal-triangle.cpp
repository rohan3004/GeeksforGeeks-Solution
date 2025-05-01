//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    vector<int> nthRowOfPascalTriangle(int n) {
        // Convert to zero-based row index
        int rowIndex = n - 1;
        vector<int> row(rowIndex + 1);
        long long val = 1;
        row[0] = 1;
        
        // Compute values using the direct combinatorial formula
        for (int k = 1; k <= rowIndex; ++k) {
            // C(rowIndex, k) = C(rowIndex, k-1) * (rowIndex - k + 1) / k
            val = val * (rowIndex - k + 1) / k;
            row[k] = static_cast<int>(val);
        }
        
        return row;
    }
};



//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);

        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends