#include <vector>
#include <algorithm> // for sort
#include <cmath>     // for abs

using namespace std;

class Solution {
  public:
    int findMoves(vector<int>& chairs, vector<int>& passengers) {
        // Sort both arrays to align the ith passenger with the ith chair
        sort(chairs.begin(), chairs.end());
        sort(passengers.begin(), passengers.end());
        
        int totalMoves = 0;
        int n = chairs.size();
        
        // Calculate the distance for each pair
        for(int i = 0; i < n; i++) {
            totalMoves += abs(chairs[i] - passengers[i]);
        }
        
        return totalMoves;
    }
};