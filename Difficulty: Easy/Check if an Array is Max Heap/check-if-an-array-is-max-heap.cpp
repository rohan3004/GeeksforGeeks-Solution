#include <vector>

using namespace std;

class Solution {
  public:
    bool isMaxHeap(vector<int> &arr) {
        int n = arr.size();
        
        // We only need to check nodes that have at least one child.
        // The last non-leaf node is at index (n - 2) / 2.
        for (int i = 0; i <= (n - 2) / 2; ++i) {
            
            // Check if the left child exists and if it's strictly greater than the parent
            if (2 * i + 1 < n && arr[2 * i + 1] > arr[i]) {
                return false;
            }
            
            // Check if the right child exists and if it's strictly greater than the parent
            if (2 * i + 2 < n && arr[2 * i + 2] > arr[i]) {
                return false;
            }
        }
        
        // If no parent was smaller than its children, it is a valid max heap.
        return true;
    }
};