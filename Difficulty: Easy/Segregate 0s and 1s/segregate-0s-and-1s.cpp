class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        int left = 0;
        int right = arr.size() - 1;
        
        while (left < right) {
            // Move left pointer forward while we see 0s
            while (left < right && arr[left] == 0) {
                left++;
            }
            
            // Move right pointer backward while we see 1s
            while (left < right && arr[right] == 1) {
                right--;
            }
            
            // If left is strictly less than right, swap the elements
            if (left < right) {
                swap(arr[left], arr[right]);
                left++;
                right--;
            }
        }
    }
};