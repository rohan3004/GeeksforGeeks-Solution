#include <vector>
#include <algorithm>

class Solution {
 public:
  /**
   * @brief Inserts a new interval into a sorted list of non-overlapping intervals, merging if necessary.
   * * @param intervals A sorted list of non-overlapping intervals.
   * @param newInterval The new interval to be inserted.
   * @return A new list of sorted, non-overlapping intervals.
   */
  std::vector<std::vector<int>> insertInterval(std::vector<std::vector<int>> &intervals,
                                               std::vector<int> &newInterval) {
    // This vector will store the final list of merged intervals.
    std::vector<std::vector<int>> result;
    int i = 0;
    int n = intervals.size();

    // 1. Add all intervals that come before the newInterval and do not overlap.
    // An interval [start, end] comes before if its `end` is less than `newInterval`'s start.
    while (i < n && intervals[i][1] < newInterval[0]) {
      result.push_back(intervals[i]);
      i++;
    }

    // 2. Merge all overlapping intervals.
    // An interval [start, end] overlaps if its `start` is less than or equal to `newInterval`'s end.
    while (i < n && intervals[i][0] <= newInterval[1]) {
      // Update newInterval to be the union of itself and the current interval.
      newInterval[0] = std::min(newInterval[0], intervals[i][0]);
      newInterval[1] = std::max(newInterval[1], intervals[i][1]);
      i++;
    }
    
    // 3. Add the merged newInterval to the result.
    result.push_back(newInterval);

    // 4. Add all the remaining intervals that come after the newInterval.
    while (i < n) {
      result.push_back(intervals[i]);
      i++;
    }

    return result;
  }
};