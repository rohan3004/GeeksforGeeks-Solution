class Solution {
public:
    int subarrayRanges(vector<int>& arr) {
        int n = arr.size();
        long long sumMax = 0, sumMin = 0;
        vector<int> st;

        // --------- Contribution as Maximum ----------
        // Previous Greater Element
        vector<int> pge(n), nge(n);

        st.clear();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.back()] <= arr[i])
                st.pop_back();
            pge[i] = st.empty() ? -1 : st.back();
            st.push_back(i);
        }

        // Next Greater Element
        st.clear();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.back()] < arr[i])
                st.pop_back();
            nge[i] = st.empty() ? n : st.back();
            st.push_back(i);
        }

        for (int i = 0; i < n; i++) {
            long long left = i - pge[i];
            long long right = nge[i] - i;
            sumMax += arr[i] * left * right;
        }

        // --------- Contribution as Minimum ----------
        vector<int> pse(n), nse(n);

        // Previous Smaller Element
        st.clear();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.back()] >= arr[i])
                st.pop_back();
            pse[i] = st.empty() ? -1 : st.back();
            st.push_back(i);
        }

        // Next Smaller Element
        st.clear();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.back()] > arr[i])
                st.pop_back();
            nse[i] = st.empty() ? n : st.back();
            st.push_back(i);
        }

        for (int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            sumMin += arr[i] * left * right;
        }

        return (int)(sumMax - sumMin);
    }
};
