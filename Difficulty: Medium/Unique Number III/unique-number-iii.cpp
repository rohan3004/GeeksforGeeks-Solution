//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int getSingle(vector<int> &arr) {
        int ones = 0, twos = 0;
        for (int x : arr) {
            // First incorporate x into 'ones'; any bit already in 'twos' must be masked out
            ones = (ones ^ x) & ~twos;
            // Now incorporate x into 'twos'; any bit now in 'ones' must be masked out
            twos = (twos ^ x) & ~ones;
        }
        // 'ones' now holds the unique element
        return ones;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.getSingle(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends