class Solution {
  long long segmentsNeeded(const vector<int>& arr, long long maxSum) {
    long long curr = 0;
    long long count = 1;            // start with one segment
    for (int x : arr) {
      if (curr + x <= maxSum) {
        curr += x;
      } else {
        // start a new segment
        count++;
        curr = x;
      }
    }
    return count;
  }

public:
  int splitArray(vector<int>& arr, int k) {
    long long low = 0, high = 0;
    for (int x : arr) {
      low = max(low, (long long)x);
      high += x;
    }

    long long ans = high;
    while (low <= high) {
      long long mid = low + (high - low) / 2;
      // how many segments if no segment may exceed mid?
      long long needed = segmentsNeeded(arr, mid);

      if (needed > k) {
        // too many segments → mid is too small
        low = mid + 1;
      } else {
        // can do it in ≤ k segments → try lowering mid
        ans = mid;
        high = mid - 1;
      }
    }

    return (int)ans;
  }
};
