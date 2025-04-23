//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    vector<int> singleNum(vector<int>& arr) {
        int xor_all = 0;
        // 1) XOR all numbers — pairs cancel, leaving a ^ b
        for (int x : arr) {
            xor_all ^= x;
        }
        // 2) Find a bit that's set in xor_all (rightmost set bit)
        int diffBit = xor_all & -xor_all;
        
        // 3) Partition numbers by that bit and XOR within each group
        int a = 0, b = 0;
        for (int x : arr) {
            if (x & diffBit)
                a ^= x;   // group 1
            else
                b ^= x;   // group 2
        }
        
        // 4) Return in sorted order
        if (a < b)
            return {a, b};
        else
            return {b, a};
    }
};



//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
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
        vector<int> ans = ob.singleNum(arr);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends