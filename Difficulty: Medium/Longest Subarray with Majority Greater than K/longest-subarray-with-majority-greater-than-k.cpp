//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> diff(n);
        
        // Transform the array based on condition
        for (int i = 0; i < n; i++) {
            diff[i] = (arr[i] > k) ? 1 : -1;
        }

        // Map to store first occurrence of prefix sum
        unordered_map<int, int> prefixMap;
        prefixMap[0] = -1;  // to handle cases where subarray starts from index 0

        int maxLen = 0;
        int prefixSum = 0;
        
        for (int i = 0; i < n; i++) {
            prefixSum += diff[i];

            // We need sum > 0, so if prefixSum > 0, then subarray from 0 to i is valid
            if (prefixSum > 0) {
                maxLen = i + 1;
            } else {
                // Check if prefixSum - 1 was seen before
                if (prefixMap.find(prefixSum - 1) != prefixMap.end()) {
                    maxLen = max(maxLen, i - prefixMap[prefixSum - 1]);
                }
            }

            // Store first occurrence of this prefixSum
            if (prefixMap.find(prefixSum) == prefixMap.end()) {
                prefixMap[prefixSum] = i;
            }
        }

        return maxLen;
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
        getline(cin, input);
        int k = stoi(input);

        Solution ob;
        cout << ob.longestSubarray(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends