#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minSteps(vector<int>& arr, int start, int end) {
        // If we are already at the target, 0 steps are needed.
        if (start == end) return 0;
        
        // Queue stores pairs of {current_value, steps_taken}
        queue<pair<int, int>> q;
        
        // Visited array to prevent infinite loops and redundant processing.
        // Size is 1000 because the modulo operation limits our values to 0-999.
        vector<bool> visited(1000, false);
        
        // Initialize BFS
        q.push({start, 0});
        visited[start] = true;
        
        while (!q.empty()) {
            int curr = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            // Try multiplying the current value by every element in the array
            for (int num : arr) {
                int next_val = (curr * num) % 1000;
                
                // If we reach the target, return the current steps + 1
                if (next_val == end) {
                    return steps + 1;
                }
                
                // If the new value hasn't been visited yet, add it to the queue
                if (!visited[next_val]) {
                    visited[next_val] = true;
                    q.push({next_val, steps + 1});
                }
            }
        }
        
        // If the queue becomes empty and we haven't found the end, it's impossible.
        return -1;
    }
};