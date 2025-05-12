//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        // Sort meetings by start time
        sort(meetings.begin(), meetings.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        
        // Min-heap of available rooms (by room number)
        priority_queue<int, vector<int>, greater<int>> free_rooms;
        for (int i = 0; i < n; ++i) free_rooms.push(i);
        
        // Min-heap of busy rooms: pairs of (free_time, room_number)
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> busy_rooms;
        
        vector<int> count(n, 0);
        
        for (auto &meet : meetings) {
            long long start = meet[0];
            long long end = meet[1];
            long long duration = end - start;
            
            // Free up rooms that have become available by this meeting's start
            while (!busy_rooms.empty() && busy_rooms.top().first <= start) {
                free_rooms.push(busy_rooms.top().second);
                busy_rooms.pop();
            }
            
            if (free_rooms.empty()) {
                // No free room: delay until the earliest room frees
                auto earliest = busy_rooms.top();
                busy_rooms.pop();
                long long free_time = earliest.first;
                int room = earliest.second;
                busy_rooms.push({free_time + duration, room});
                count[room]++;
            } else {
                // Assign to smallest-numbered free room
                int room = free_rooms.top();
                free_rooms.pop();
                busy_rooms.push({start + duration, room});
                count[room]++;
            }
        }
        
        // Find room with maximum count (and smallest index on tie)
        int best_room = 0;
        for (int i = 1; i < n; ++i) {
            if (count[i] > count[best_room]) {
                best_room = i;
            }
        }
        return best_room;
    }
};


//{ Driver Code Starts.

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> m;
        vector<vector<int>> meetings(m, vector<int>(2));
        for (int i = 0; i < m; i++) {
            cin >> meetings[i][0] >> meetings[i][1];
        }
        Solution ob;
        cout << ob.mostBooked(n, meetings) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends