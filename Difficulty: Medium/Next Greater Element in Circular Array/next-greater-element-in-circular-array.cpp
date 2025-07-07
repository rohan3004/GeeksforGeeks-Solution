class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
        int n = arr.size();
        vector<int> res(n, -1);  // Initialize result with -1
        stack<int> st;           // Monotonic decreasing stack (stores indices)

        for (int i = 0; i < 2 * n; ++i) {
            int num = arr[i % n];
            while (!st.empty() && arr[st.top()] < num) {
                res[st.top()] = num;
                st.pop();
            }
            if (i < n) {
                st.push(i);
            }
        }
        return res;
    }
};
