class Solution {
  public:
    void sort012(vector<int>& arr) {
        int n = arr.size();
        int low = 0;
        int mid = 0;
        int high = n - 1;

        while (mid <= high) {
            if (arr[mid] == 0) {
                // Case 0: Move to the 'low' region
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            } else if (arr[mid] == 1) {
                // Case 1: Keep in the 'mid' region
                mid++;
            } else {
                // Case 2: Move to the 'high' region
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }
};