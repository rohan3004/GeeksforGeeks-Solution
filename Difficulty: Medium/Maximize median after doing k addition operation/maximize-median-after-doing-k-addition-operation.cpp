class Solution {
public:
    long long maximizeMedian(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        long long iniMedian;

        if (n % 2 == 1) {
            iniMedian = arr[n / 2];
        } else {
            iniMedian = (arr[n / 2] + arr[n / 2 - 1]) / 2;
        }

        long long low = iniMedian, high = iniMedian + k, best = iniMedian;

        while (low <= high) {
            long long mid = (low + high) / 2;
            if (isPossible(arr, mid, k)) {
                best = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return best;
    }

private:
    bool isPossible(vector<int>& arr, int target,int k) {
        int n = arr.size();

        if (n % 2 == 1) {
            for (int i = n / 2; i < n; i++) {
                if (arr[i] < target) k -= (target - arr[i]);
                if (k < 0) return false;
            }
        } else {
            int left = arr[n / 2 - 1];
            int right = arr[n / 2];
            long long need = max(0LL, 2 * target - (long long)(left + right));
            k -= need;
            if (k < 0) return false;

            for (int i = n / 2 + 1; i < n; i++) {
                if (arr[i] < target) k -= (target - arr[i]);
                if (k < 0) return false;
            }
        }
        return true;
    }
};