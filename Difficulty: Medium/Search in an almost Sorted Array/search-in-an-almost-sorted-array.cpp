//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
public:
    // Searches for target in an "almost sorted" array where each element
    // may be displaced by at most one position from its sorted order.
    // Returns the index of target if found, or -1 otherwise.
    int findTarget(vector<int>& arr, int target) {
        int n = arr.size();
        int low = 0, high = n - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Check mid and its immediate neighbors for the target
            if (arr[mid] == target) {
                return mid;
            }
            if (mid - 1 >= low && arr[mid - 1] == target) {
                return mid - 1;
            }
            if (mid + 1 <= high && arr[mid + 1] == target) {
                return mid + 1;
            }

            // Adjust the search range by skipping the checked neighbors
            if (arr[mid] > target) {
                high = mid - 2;
            } else {
                low = mid + 2;
            }
        }
        
        // Target not found
        return -1;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        int target;
        cin >> target;
        cin.ignore();
        Solution sln;
        int ans = sln.findTarget(arr, target);
        cout << ans << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends