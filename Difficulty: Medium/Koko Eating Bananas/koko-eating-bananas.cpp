class Solution {
  public:
    int kokoEat(vector<int>& arr, int k) {
        int low = 1;
        int high = *max_element(arr.begin(), arr.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long hours = 0;

            for (int bananas : arr) {
                hours += (bananas + mid - 1) / mid; // ceil(bananas / mid)
            }

            if (hours <= k) {
                high = mid - 1;   // try smaller speed
            } else {
                low = mid + 1;    // need faster speed
            }
        }
        return low;
    }
};
