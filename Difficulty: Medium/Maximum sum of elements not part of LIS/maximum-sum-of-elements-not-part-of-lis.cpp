class Solution {
  public:
    int nonLisMaxSum(vector<int>& arr) {
        int n = arr.size();
        struct Node { long sum; int len; };
        vector<Node> dp(n);
        long total = 0;

        for (int i = 0; i < n; i++) {
            dp[i] = {arr[i], 1};
            total += arr[i];
            for (int j = 0; j < i; j++) {
                if (arr[j] < arr[i]) {
                    int newLen = dp[j].len + 1;
                    long newSum = dp[j].sum + arr[i];
                    if (newLen > dp[i].len) {
                        dp[i].len = newLen;
                        dp[i].sum = newSum;
                    } else if (newLen == dp[i].len && newSum < dp[i].sum) {
                        dp[i].sum = newSum;
                    }
                }
            }
        }

        int maxLen = 0;
        long minLisSum = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            if (dp[i].len > maxLen) {
                maxLen = dp[i].len;
                minLisSum = dp[i].sum;
            } else if (dp[i].len == maxLen && dp[i].sum < minLisSum) {
                minLisSum = dp[i].sum;
            }
        }

        return total - minLisSum;
    }
};
