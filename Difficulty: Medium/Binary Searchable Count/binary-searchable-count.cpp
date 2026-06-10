#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
    int countBinarySearchable(const vector<int>& arr, int l, int r, int min_val, int max_val) {
        if (l > r) return 0;
        
        int mid = l + (r - l) / 2;
        int count = 0;
        
        // If the current element strictly respects the boundaries 
        // established by its ancestors, it is searchable.
        if (arr[mid] > min_val && arr[mid] < max_val) {
            count = 1;
        }
        
        // Traverse the left subarray
        // Going left means the target must be smaller than arr[mid]
        int left_count = countBinarySearchable(arr, l, mid - 1, min_val, min(max_val, arr[mid]));
        
        // Traverse the right subarray
        // Going right means the target must be larger than arr[mid]
        int right_count = countBinarySearchable(arr, mid + 1, r, max(min_val, arr[mid]), max_val);
        
        return count + left_count + right_count;
    }

public:
    int binarySearchable(vector<int>& arr) {
        return countBinarySearchable(arr, 0, arr.size() - 1, INT_MIN, INT_MAX);
    }
};