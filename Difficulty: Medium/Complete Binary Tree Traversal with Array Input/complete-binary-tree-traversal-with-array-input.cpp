#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    vector<vector<int>> levelSort(vector<int>& arr) {
        vector<vector<int>> result;
        int n = arr.size();
        int current_index = 0;
        int level_size = 1; // Number of nodes at the current level (1, 2, 4, 8...)
        
        while (current_index < n) {
            vector<int> current_level;
            
            // The last level might have fewer nodes than level_size
            int elements_to_take = min(level_size, n - current_index);
            
            // Extract the nodes for the current level
            for (int i = 0; i < elements_to_take; ++i) {
                current_level.push_back(arr[current_index + i]);
            }
            
            // Sort the extracted nodes independently
            sort(current_level.begin(), current_level.end());
            
            // Store it in the final result
            result.push_back(current_level);
            
            // Advance the pointer and double the expected level size for the next iteration
            current_index += elements_to_take;
            level_size *= 2; 
        }
        
        return result;
    }
};