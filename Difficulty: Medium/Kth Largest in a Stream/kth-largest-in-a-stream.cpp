#include <vector>
#include <queue>

using namespace std;

class Solution {
  public:
    vector<int> kthLargest(vector<int>& arr, int k) {
        vector<int> result;
        // Min-heap to maintain the 'k' largest elements seen so far
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for (int i = 0; i < arr.size(); i++) {
            // If we have less than k elements, simply push the current element
            if (minHeap.size() < k) {
                minHeap.push(arr[i]);
            } 
            // If the heap is full (size k) and the current element is larger than 
            // the smallest element in our heap, we swap them out.
            else if (arr[i] > minHeap.top()) {
                minHeap.pop();
                minHeap.push(arr[i]);
            }
            
            // If we still don't have k elements, the kth largest doesn't exist yet
            if (minHeap.size() < k) {
                result.push_back(-1);
            } 
            // Otherwise, the root of the min-heap is the kth largest element
            else {
                result.push_back(minHeap.top());
            }
        }
        
        return result;
    }
};