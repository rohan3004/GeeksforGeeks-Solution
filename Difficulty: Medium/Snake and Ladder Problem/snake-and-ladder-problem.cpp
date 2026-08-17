#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minThrows(int n, vector<int>& lad, vector<int>& sn) {
        int target = n * n;
        
        // jump array stores the destination if a snake or ladder starts at index i
        vector<int> jump(target + 1, -1);
        
        // Populate ladders
        for (size_t i = 0; i < lad.size(); i += 2) {
            jump[lad[i]] = lad[i + 1];
        }
        
        // Populate snakes
        for (size_t i = 0; i < sn.size(); i += 2) {
            jump[sn[i]] = sn[i + 1];
        }
        
        // dist array to keep track of the minimum throws to reach each cell
        vector<int> dist(target + 1, -1);
        queue<int> q;
        
        q.push(1);
        dist[1] = 0;
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            // If we've reached the final cell, return the distance
            if (curr == target) {
                return dist[curr];
            }
            
            // Try all possible dice throws
            for (int dice = 1; dice <= 6; ++dice) {
                int next_pos = curr + dice;
                
                if (next_pos > target) {
                    break;
                }
                
                // If there's a snake or ladder, immediately jump to its end
                int final_pos = (jump[next_pos] != -1) ? jump[next_pos] : next_pos;
                
                // If the final destination hasn't been visited yet, process it
                if (dist[final_pos] == -1) {
                    dist[final_pos] = dist[curr] + 1;
                    q.push(final_pos);
                }
            }
        }
        
        // If the queue empties and we never hit target, it's unreachable
        return -1;
    }
};