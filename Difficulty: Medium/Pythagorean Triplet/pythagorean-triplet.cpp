class Solution {
public:
    bool pythagoreanTriplet(vector<int>& arr) {
        const int MAXV = 1000;
        // 1) Build frequency table
        vector<int> freq(MAXV+1, 0);
        for (int v : arr) {
            freq[v]++;
        }
        // 2) Extract sorted list of distinct values
        vector<int> vals;
        for (int v = 1; v <= MAXV; v++)
            if (freq[v] > 0)
                vals.push_back(v);
        
        int m = vals.size();
        // 3) Check every pair (a, b) among distinct values
        for (int i = 0; i < m; i++) {
            int a = vals[i];
            for (int j = i; j < m; j++) {
                int b = vals[j];
                long long c2 = 1LL*a*a + 1LL*b*b;
                int c = int(std::llround(std::sqrt(c2)));
                // must be perfect square and in range
                if (c <= MAXV && 1LL*c*c == c2 && freq[c] > 0) {
                    // Now ensure we have enough distinct indices:
                    if (a == b && b == c) {
                        if (freq[a] >= 3) return true;
                    }
                    else if (a == b) {
                        if (freq[a] >= 2) return true;
                    }
                    else if (b == c) {
                        if (freq[b] >= 2) return true;
                    }
                    else if (a == c) {
                        if (freq[a] >= 2) return true;
                    }
                    else {
                        // all three distinct
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};
