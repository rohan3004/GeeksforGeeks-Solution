#include <vector>
#include <queue>      // For std::priority_queue
#include <algorithm>  // For std::min

using namespace std;

class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        int n = arr.size();
        
        // A min-heap (smallest element on top)
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // 1. Add the first k+1 elements to the heap
        // We use min(n, k + 1) to handle cases where the array
        // is smaller than k+1 elements.
        int initialSize = min(n, k + 1);
        for (int i = 0; i < initialSize; ++i) {
            minHeap.push(arr[i]);
        }

        int writeIndex = 0;

        // 2. Process the rest of the array (from index k+1 to n-1)
        for (int i = k + 1; i < n; ++i) {
            // The smallest element in the heap's "window" is
            // the correct element for the current writeIndex
            arr[writeIndex] = minHeap.top();
            minHeap.pop();
            
            // Add the next element from the array into the heap
            minHeap.push(arr[i]);
            
            writeIndex++;
        }

        // 3. Drain the remaining elements from the heap
        // These are the largest elements, now sorted.
        while (!minHeap.empty()) {
            arr[writeIndex] = minHeap.top();
            minHeap.pop();
            writeIndex++;
        }
    }
};