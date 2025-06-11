class Solution {
  public:
    int findLength(vector<int> &color, vector<int> &radius) {
        stack<pair<int, int>> st;

        for (int i = 0; i < color.size(); ++i) {
            pair<int, int> current = {color[i], radius[i]};
            if (!st.empty() && st.top() == current) {
                st.pop(); // Remove the matching pair
            } else {
                st.push(current); // Push current ball
            }
        }

        return st.size(); // Remaining balls
    }
};
