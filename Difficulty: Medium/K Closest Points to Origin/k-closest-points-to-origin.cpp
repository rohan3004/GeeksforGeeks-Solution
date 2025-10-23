#include <vector>
#include <queue>
#include <cmath> // Not needed if we use squared distance

using namespace std;

class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    
    // Create a max-heap. It will store pairs of {squared_distance, point}
    // By default, priority_queue sorts by the first element (distance)
    // and creates a max-heap (largest element at the top).
    priority_queue<pair<int, vector<int>>> maxHeap;

    for (const auto& point : points) {
      // Calculate the squared Euclidean distance
      // Using 'long' for distSq is safer to prevent overflow, 
      // though for this problem's constraints, 'int' works.
      long distSq = (long)point[0] * point[0] + (long)point[1] * point[1];

      // Add the point to the heap
      maxHeap.push({distSq, point});

      // If the heap size is now greater than k, remove the
      // element with the largest distance (the top element)
      if (maxHeap.size() > k) {
        maxHeap.pop();
      }
    }

    // Now, the max-heap contains the k closest points.
    // We just need to extract them into the result vector.
    vector<vector<int>> result;
    while (!maxHeap.empty()) {
      // .top() gives the pair, .second gives the vector<int> (the point)
      result.push_back(maxHeap.top().second);
      maxHeap.pop();
    }
    
    // The order doesn't matter per the problem description.
    return result;
  }
};