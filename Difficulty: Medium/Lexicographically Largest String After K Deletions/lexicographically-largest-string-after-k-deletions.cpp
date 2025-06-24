class Solution {
public:
    string maxSubseq(string& s, int k) {
        int n = s.size();
        int keep = n - k;           // number of chars to keep
        vector<char> st;            // acts like a stack

        int k_rem = k;              // how many we still need to remove
        for (char c : s) {
            // greedily remove previous smaller chars if it helps
            while (!st.empty() && k_rem > 0 && st.back() < c) {
                st.pop_back();
                --k_rem;
            }
            st.push_back(c);
        }
        // If we still haven't removed k characters, remove from the end
        while (k_rem > 0) {
            st.pop_back();
            --k_rem;
        }
        // Build result of length exactly keep
        return string(st.begin(), st.begin() + keep);
    }
};
