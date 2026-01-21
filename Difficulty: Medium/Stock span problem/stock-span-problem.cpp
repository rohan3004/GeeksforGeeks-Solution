class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n = arr.size();
        vector<int> span(n);
        stack<int> st; // stores indices

        for (int i = 0; i < n; i++) {
            // Pop while current price is higher or equal
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }

            // If stack empty, span is i+1 else difference of indices
            span[i] = st.empty() ? (i + 1) : (i - st.top());

            // Push current index
            st.push(i);
        }

        return span;
    }
};
