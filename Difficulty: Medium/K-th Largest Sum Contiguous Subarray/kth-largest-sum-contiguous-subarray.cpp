//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
public:
    int kthLargest(vector<int> &arr, int k) {
        int n = arr.size();
        // Compute prefix sums
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + arr[i];
        }
        
        // Min-heap to store the k largest sums
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        
        // Consider all subarrays
        for (int start = 0; start < n; ++start) {
            for (int end = start; end < n; ++end) {
                long long sum = prefix[end + 1] - prefix[start];
                if ((int)minHeap.size() < k) {
                    minHeap.push(sum);
                } else if (sum > minHeap.top()) {
                    minHeap.pop();
                    minHeap.push(sum);
                }
            }
        }
        
        // The root of min-heap is the k-th largest sum
        return (int)minHeap.top();
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        int res = obj.kthLargest(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends