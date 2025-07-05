#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSum(const vector<int>& arr) {
        int n = arr.size();
        vector<int> L(n), R(n);
        stack<int> st;

        // 1) L[j] = index of previous element <OR= arr[j]
        while (!st.empty()) st.pop();
        for (int j = 0; j < n; ++j) {
            while (!st.empty() && arr[st.top()] > arr[j])
                st.pop();
            L[j] = st.empty() ? -1 : st.top();
            st.push(j);
        }

        // 2) R[j] = index of next element <OR= arr[j]
        while (!st.empty()) st.pop();
        for (int j = n - 1; j >= 0; --j) {
            while (!st.empty() && arr[st.top()] > arr[j])
                st.pop();
            R[j] = st.empty() ? -1 : st.top();
            st.push(j);
        }

        // 3) For each j, only pairs (L[j],j) and (j,R[j]) can be the two minima
        int ans = 0;
        for (int j = 0; j < n; ++j) {
            if (L[j] != -1)
                ans = max(ans, arr[j] + arr[L[j]]);
            if (R[j] != -1)
                ans = max(ans, arr[j] + arr[R[j]]);
        }
        return ans;
    }
};