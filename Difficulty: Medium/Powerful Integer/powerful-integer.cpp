class Solution {
 public:
  int powerfulInteger(std::vector<std::vector<int>>& intervals, int k) {
    std::map<int, int> timeline;
    for (const auto& interval : intervals) {
      timeline[interval[0]]++;
      timeline[interval[1] + 1]--;
    }

    int max_powerful_integer = -1;
    int current_overlap = 0;
    
    // Previous point is needed to define the interval
    int prev_point = timeline.begin()->first;

    for (const auto& [point, change] : timeline) {
      // The segment [prev_point, point - 1] had an overlap of `current_overlap`
      if (current_overlap >= k) {
        // The largest integer in this powerful segment is `point - 1`
        max_powerful_integer = point - 1;
      }
      
      // Update overlap for the next segment starting at `point`
      current_overlap += change;
      prev_point = point;
    }

    return max_powerful_integer;
  }
};