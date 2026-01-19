class Solution {
public:
    string removeKdig(string &s, int k) {
        string st;               // acts as a stack
        st.reserve(s.size());    // optimization for large input

        for (char c : s) {
            while (!st.empty() && k > 0 && st.back() > c) {
                st.pop_back();
                k--;
            }
            st.push_back(c);
        }

        // If removals still left, remove from the end
        while (k > 0 && !st.empty()) {
            st.pop_back();
            k--;
        }

        // Remove leading zeros
        int i = 0;
        while (i < (int)st.size() && st[i] == '0') i++;

        string result = st.substr(i);

        return result.empty() ? "0" : result;
    }
};
