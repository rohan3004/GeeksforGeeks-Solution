class Solution {
  public:
    int kokoEat(vector<int>& arr, int k) {
        int low = 1;
        int high = *max_element(arr.begin(), arr.end());
        int result = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long totalHours = 0;

            // Calculate hours needed at eating speed = mid
            for (int bananas : arr) {
                totalHours += (bananas + mid - 1) / mid;  // ceil(bananas / mid)
            }

            if (totalHours <= k) {
                result = mid;       // feasible, try smaller speed
                high = mid - 1;
            } else {
                low = mid + 1;      // not enough, increase speed
            }
        }

        return result;
    }
};
