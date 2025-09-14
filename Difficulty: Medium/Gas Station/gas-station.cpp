#include <vector>
#include <numeric> // Required for std::accumulate in some compilers

class Solution {
  public:
    /**
     * @brief Finds the starting gas station index to complete a circular tour.
     * @param gas A vector of integers representing gas at each station.
     * @param cost A vector of integers representing the cost to travel to the next station.
     * @return The index of the starting station, or -1 if no solution exists.
     */
    int startStation(std::vector<int> &gas, std::vector<int> &cost) {
        int n = gas.size();
        
        // total_tank tracks the overall gas balance. If it's negative at the end,
        // the tour is impossible.
        int total_tank = 0;
        
        // current_tank tracks the gas for the current journey segment.
        int current_tank = 0;
        
        // start_station holds the potential starting station index.
        int start_station = 0;
        
        for (int i = 0; i < n; ++i) {
            int diff = gas[i] - cost[i];
            
            // Update the total and current tank levels.
            total_tank += diff;
            current_tank += diff;
            
            // If current_tank goes negative, it means we can't reach station i+1
            // from the current start_station.
            if (current_tank < 0) {
                // The next station becomes the new candidate for the start.
                start_station = i + 1;
                // Reset the tank for this new journey segment.
                current_tank = 0;
            }
        }
        
        // If the total_tank is non-negative, a solution exists, and it's the 
        // start_station we found. Otherwise, no solution exists.
        return (total_tank >= 0) ? start_station : -1;
    }
};