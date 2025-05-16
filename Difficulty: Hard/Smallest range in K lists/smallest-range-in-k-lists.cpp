//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


#include <vector>
#include <queue>
#include <tuple>
#include <limits>
using namespace std;

class Solution {
public:
    vector<int> findSmallestRange(vector<vector<int>>& arr) {
        int k = arr.size();
        typedef tuple<int, int, int> T; // value, row, col

        struct Compare {
            bool operator()(const T& a, const T& b) {
                return get<0>(a) > get<0>(b);
            }
        };

        priority_queue<T, vector<T>, Compare> minHeap;

        int currentMax = numeric_limits<int>::min();

        // Initialize heap with first element from each row
        for (int i = 0; i < k; ++i) {
            if (!arr[i].empty()) {
                minHeap.push(make_tuple(arr[i][0], i, 0));
                currentMax = max(currentMax, arr[i][0]);
            }
        }

        int bestStart = 0;
        int bestEnd = numeric_limits<int>::max();

        while (!minHeap.empty()) {
            T current = minHeap.top();
            minHeap.pop();

            int val = get<0>(current);
            int row = get<1>(current);
            int col = get<2>(current);

            if (currentMax - val < bestEnd - bestStart) {
                bestStart = val;
                bestEnd = currentMax;
            }

            if (col + 1 < arr[row].size()) {
                int nextVal = arr[row][col + 1];
                minHeap.push(make_tuple(nextVal, row, col + 1));
                currentMax = max(currentMax, nextVal);
            } else {
                break; // One list exhausted
            }
        }

        return {bestStart, bestEnd};
    }
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> arr(k, vector<int>(n));

        for (int i = 0; i < k; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];

        Solution obj;
        vector<int> range = obj.findSmallestRange(arr);
        cout << range[0] << " " << range[1] << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends