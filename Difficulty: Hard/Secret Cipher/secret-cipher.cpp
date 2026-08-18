#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    // Helper function to build the Z-array in O(N) time
    vector<int> getZArray(const string& s) {
        int n = s.length();
        vector<int> Z(n, 0);
        int L = 0, R = 0;
        for (int i = 1; i < n; i++) {
            if (i > R) {
                L = R = i;
                while (R < n && s[R - L] == s[R]) {
                    R++;
                }
                Z[i] = R - L;
                R--;
            } else {
                int k = i - L;
                if (Z[k] < R - i + 1) {
                    Z[i] = Z[k];
                } else {
                    L = i;
                    while (R < n && s[R - L] == s[R]) {
                        R++;
                    }
                    Z[i] = R - L;
                    R--;
                }
            }
        }
        return Z;
    }

public:
    string compress(string &s) {
        int n = s.length();
        if (n == 0) return "";

        // Compute the Z-array for string s
        vector<int> Z = getZArray(s);

        string res = "";
        int i = n;

        // Backtrack greedily from right to left
        while (i > 0) {
            // If the current length is even and both halves match perfectly
            if (i % 2 == 0 && Z[i / 2] >= i / 2) {
                res += '*';
                i /= 2;
            } else {
                res += s[i - 1];
                i--;
            }
        }

        // As we have backtracked, we need to reverse our result at the end 
        reverse(res.begin(), res.end());
        return res;
    }
};