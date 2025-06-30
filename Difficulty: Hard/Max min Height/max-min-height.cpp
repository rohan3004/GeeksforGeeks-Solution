class Solution {
  public:
    int maxMinHeight(vector<int> &arr, int k, int w) {
        int n = arr.size();
        
        auto isPossible = [&](int h) {
            vector<int> water(n + 1, 0);
            long long ops = 0, curr = 0;
            
            for (int i = 0; i < n; ++i) {
                curr += water[i];
                int height = arr[i] + curr;
                if (height < h) {
                    int need = h - height;
                    ops += need;
                    if (ops > k) return false;
                    curr += need;
                    if (i + w < n) water[i + w] -= need;
                }
            }
            return true;
        };
        
        int low = *min_element(arr.begin(), arr.end());
        int high = low + k, ans = low;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
