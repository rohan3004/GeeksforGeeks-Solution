class Solution {
  public:
    vector<int> nextFreqGreater(vector<int>& arr) {
        int n = arr.size();
        
        // Step 1: Frequency count
        unordered_map<int, int> freq;
        for (int x : arr) {
            freq[x]++;
        }
        
        vector<int> ans(n, -1);
        stack<int> st;  // stores elements (not indices)
        
        // Step 2: Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {
            // Remove elements with frequency <= current
            while (!st.empty() && freq[st.top()] <= freq[arr[i]]) {
                st.pop();
            }
            
            // If stack not empty, top is the answer
            if (!st.empty()) {
                ans[i] = st.top();
            }
            
            // Push current element
            st.push(arr[i]);
        }
        
        return ans;
    }
};
