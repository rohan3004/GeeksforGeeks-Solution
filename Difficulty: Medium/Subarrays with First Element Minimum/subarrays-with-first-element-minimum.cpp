class Solution {
  public:
    int countSubarrays(vector<int> &arr) {
        int n = arr.size();
        int count = 0; 
        stack<int> st;

        for (int i = 0; i < n; i++) {
            // When we find an element smaller than the top of the stack,
            // we've found the boundary for subarrays starting at st.top()
            while (!st.empty() && arr[st.top()] > arr[i]) {
                int start_idx = st.top();
                st.pop();
                count += (i - start_idx);
            }
            st.push(i);
        }

        // For remaining elements in the stack, there was no smaller element 
        // to their right. They can extend all the way to the end of the array.
        while (!st.empty()) {
            int start_idx = st.top();
            st.pop();
            count += (n - start_idx);
        }

        return count;
    }
};