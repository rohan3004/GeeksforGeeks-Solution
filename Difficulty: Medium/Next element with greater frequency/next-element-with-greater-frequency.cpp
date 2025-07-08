#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, -1);
        unordered_map<int, int> freq;

        // Step 1: Count frequencies
        for (int num : arr) {
            freq[num]++;
        }

        stack<int> st; // stack will store element values

        // Step 2: Traverse from right to left
        for (int i = n - 1; i >= 0; --i) {
            // Pop elements with frequency <= current
            while (!st.empty() && freq[st.top()] <= freq[arr[i]]) {
                st.pop();
            }

            // If stack not empty, top is the answer
            if (!st.empty()) {
                res[i] = st.top();
            }

            // Push current element as a candidate for left elements
            st.push(arr[i]);
        }

        return res;
    }
};
