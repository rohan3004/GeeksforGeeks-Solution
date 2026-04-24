#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int visibleBuildings(vector<int>& arr) {
        if (arr.empty()) return 0;
        
        int count = 0;
        int max_height = 0;
        
        for (int height : arr) {
            // If the current building is taller than or equal to the tallest 
            // building seen so far, it receives sunlight.
            if (height >= max_height) {
                count++;
                max_height = height; // Update the new maximum height blocking the sun
            }
        }
        
        return count;
    }
};