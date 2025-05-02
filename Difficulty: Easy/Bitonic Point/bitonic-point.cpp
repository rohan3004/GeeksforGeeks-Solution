//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findMaximum(vector<int> &arr) {
        int low = 0, high = arr.size() - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Handle edges to avoid out-of-bound errors
            if ((mid == 0 || arr[mid] > arr[mid - 1]) &&
                (mid == arr.size() - 1 || arr[mid] > arr[mid + 1])) {
                return arr[mid];
            }
            else if (mid > 0 && arr[mid] > arr[mid - 1]) {
                // We are in the increasing part
                low = mid + 1;
            }
            else {
                // We are in the decreasing part
                high = mid - 1;
            }
        }
        
        return -1; // This should never be reached given the constraints
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        int value;

        // Read the entire line of integers
        string line;
        // cin.ignore(); // Ignore the newline after the test case input
        getline(cin, line);
        stringstream ss(line);

        // Parse integers and add them to the vector
        while (ss >> value) {
            arr.push_back(value);
        }

        Solution ob;
        auto ans = ob.findMaximum(arr);
        cout << ans << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends