//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findMissing(vector<int> &arr) {
        int n = arr.size();
        if (n < 2) 
            return 0;  // undefined for fewer than 2 elements

        // 1) true common difference: choose the end-gap with smaller |gap|
        int diff1 = arr[1] - arr[0];
        int diff2 = arr[n-1] - arr[n-2];
        int d     = (abs(diff1) < abs(diff2) ? diff1 : diff2);

        // 2) binary search for the first mismatch
        int low = 0, high = n - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            int expected = arr[0] + mid * d;
            if (arr[mid] == expected)
                low = mid + 1;
            else
                high = mid;
        }

        // 3) if no mismatch internally, return next element; otherwise return the gap‑filler
        if (low == n - 1 && arr[low] == arr[0] + low * d)
            return arr.back() + d;
        return arr[0] + low * d;
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
        cout << ob.findMissing(arr) << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends