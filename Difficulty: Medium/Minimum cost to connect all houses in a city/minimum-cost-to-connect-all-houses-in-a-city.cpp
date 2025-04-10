//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
     int minCost(vector<vector<int>>& houses) {
        int n = houses.size();
        vector<bool> inMST(n, false); // Track nodes in the MST
        vector<int> minDist(n, numeric_limits<int>::max()); // Min distance to MST
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // Min-heap for distances
        
        minDist[0] = 0; // Start from the first house
        pq.push({0, 0}); // {distance, house index}
        int totalCost = 0;

        while (!pq.empty()) {
            pair<int, int> current = pq.top();
            pq.pop();

            int cost = current.first;
            int u = current.second;

            if (inMST[u]) continue; // Skip if already in MST
            inMST[u] = true;
            totalCost += cost;

            for (int v = 0; v < n; v++) {
                if (!inMST[v]) {
                    int dist = abs(houses[u][0] - houses[v][0]) + abs(houses[u][1] - houses[v][1]);
                    if (dist < minDist[v]) {
                        minDist[v] = dist;
                        pq.push({dist, v});
                    }
                }
            }
        }

        return totalCost;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> edges;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;

        cout << obj.minCost(edges);
        cout << "\n";
        cout << "~" << endl;
    }
}

// } Driver Code Ends