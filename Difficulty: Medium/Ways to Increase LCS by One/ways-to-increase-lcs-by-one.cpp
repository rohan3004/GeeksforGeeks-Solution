class Solution {
public:
    int waysToIncreaseLCSBy1(string &s1, string &s2) {
        int n = s1.length();
        int m = s2.length();
        
        // pref[i][j] = LCS of s1[0..i-1] and s2[0..j-1]
        vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    pref[i][j] = pref[i - 1][j - 1] + 1;
                } else {
                    pref[i][j] = max(pref[i - 1][j], pref[i][j - 1]);
                }
            }
        }
        
        // suff[i][j] = LCS of s1[i..n-1] and s2[j..m-1]
        vector<vector<int>> suff(n + 1, vector<int>(m + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (s1[i] == s2[j]) {
                    suff[i][j] = suff[i + 1][j + 1] + 1;
                } else {
                    suff[i][j] = max(suff[i + 1][j], suff[i][j + 1]);
                }
            }
        }
        
        int L = pref[n][m]; // Original LCS length
        int ans = 0;
        
        // For each possible insertion position i in s1 (0 to n)
        for (int i = 0; i <= n; i++) {
            vector<bool> validChar(26, false);
            
            // Try matching the newly inserted character with s2[j]
            for (int j = 0; j < m; j++) {
                // If prefix LCS + suffix LCS == Total LCS, inserting s2[j] here increases LCS by 1
                if (pref[i][j] + suff[i][j + 1] == L) {
                    validChar[s2[j] - 'a'] = true;
                }
            }
            
            // Count all unique valid characters that can be inserted specifically at position i
            for (int c = 0; c < 26; c++) {
                if (validChar[c]) {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};