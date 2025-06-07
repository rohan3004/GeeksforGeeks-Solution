class Solution {
public:
    int longestCommonSum(vector<int> &a1, vector<int> &a2) {
        int n = a1.size();
        unordered_map<int,int> firstIndex;
        firstIndex.reserve(n*2);
        
        int maxLen = 0;
        int ps = 0;  // prefix sum of (a1[k]-a2[k])
        
        for (int k = 0; k < n; ++k) {
            ps += (a1[k] - a2[k]);
            
            if (ps == 0) {
                // sum zero from 0..k
                maxLen = max(maxLen, k + 1);
            }
            else {
                auto it = firstIndex.find(ps);
                if (it != firstIndex.end()) {
                    // seen this prefix sum before at it->second
                    int len = k - it->second;
                    maxLen = max(maxLen, len);
                } else {
                    // first time we see this sum, record index
                    firstIndex[ps] = k;
                }
            }
        }
        
        return maxLen;
    }
};
