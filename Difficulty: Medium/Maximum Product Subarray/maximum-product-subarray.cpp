class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        int maxEndingHere = arr[0];
        int minEndingHere = arr[0];
        int ans = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            int x = arr[i];

            // If current element is negative, swap
            if (x < 0) {
                swap(maxEndingHere, minEndingHere);
            }

            maxEndingHere = max(x, maxEndingHere * x);
            minEndingHere = min(x, minEndingHere * x);

            ans = max(ans, maxEndingHere);
        }

        return ans;
    }
};
