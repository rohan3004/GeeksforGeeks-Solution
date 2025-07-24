#include <vector>
#include <algorithm> // Required for std::max_element and std::min_element
#include <iostream>

class Solution {
 public:
  int getLastMoment(int n, std::vector<int>& left, std::vector<int>& right) {
    // This variable will store the maximum time found so far.
    int lastMoment = 0;
    
    // Calculate the time for the last ant moving left to fall.
    // This is the ant that starts at the highest position, as it has the farthest to travel.
    if (!left.empty()) {
      // The time taken is equal to the position itself (e.g., from position p to 0 takes p seconds).
      int max_left_time = *std::max_element(left.begin(), left.end());
      lastMoment = std::max(lastMoment, max_left_time);
    }
    
    // Calculate the time for the last ant moving right to fall.
    // This is the ant that starts at the lowest position, as it has the farthest to travel to reach n.
    if (!right.empty()) {
      // The time taken is n minus the position (e.g., from position p to n takes n-p seconds).
      int max_right_time = n - *std::min_element(right.begin(), right.end());
      lastMoment = std::max(lastMoment, max_right_time);
    }
    
    return lastMoment;
  }
};