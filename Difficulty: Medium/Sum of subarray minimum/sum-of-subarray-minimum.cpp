class Solution {
  public:
    int sumSubMins(vector<int> &arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;

        vector<int> ple(n), nle(n);
        stack<int> st;

        // PLE: previous less element (strictly greater for stack)
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            ple[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // NLE: next less element (strictly less)
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
            nle[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long res = 0;
        for (int i = 0; i < n; ++i) {
            long long left = i - ple[i];
            long long right = nle[i] - i;
            res = (res + (arr[i] * left % MOD) * right % MOD) % MOD;
        }

        return res;
    }
};
