class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        int n = arr.size();
        int idx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();

        // Exclude x if it exists
        if (idx < n && arr[idx] == x)
            idx++;

        int left = idx - 1, right = idx;
        vector<pair<int, int>> temp; // Pair of (diff, value)

        while (k--) {
            if (left >= 0 && right < n) {
                int ldiff = abs(arr[left] - x);
                int rdiff = abs(arr[right] - x);
                if (ldiff < rdiff || (ldiff == rdiff && arr[left] > arr[right])) {
                    temp.push_back({ldiff, arr[left--]});
                } else {
                    temp.push_back({rdiff, arr[right++]});
                }
            } else if (left >= 0) {
                temp.push_back({abs(arr[left] - x), arr[left--]});
            } else {
                temp.push_back({abs(arr[right] - x), arr[right++]});
            }
        }

        // Sort by distance first, then by value descending
        sort(temp.begin(), temp.end(), [](pair<int, int>& a, pair<int, int>& b) {
            if (a.first != b.first) return a.first < b.first;
            return a.second > b.second;
        });

        vector<int> result;
        for (auto& p : temp)
            result.push_back(p.second);
        return result;
    }
};
