class Solution {
  public:
    int maxPeople(vector<int> &arr) {
        int n = arr.size();
        vector<int> L(n), R(n);
        stack<int> st;

        // Nearest greater or equal to the left
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            L[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // Clear stack for right pass
        while (!st.empty()) st.pop();

        // Nearest greater or equal to the right
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            R[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int visible = (i - L[i] - 1) + (R[i] - i - 1) + 1;
            ans = max(ans, visible);
        }

        return ans;
    }
};
