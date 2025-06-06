#include <vector>
#include <string>
using namespace std;

class Solution {
  public:
    vector<int> search(string &pat, string &txt) {
        int m = pat.size();
        int n = txt.size();
        vector<int> lps(m, 0);

        // 1) Precompute LPS array for pattern in O(m)
        // lps[i] = length of the longest proper prefix of pat[0..i] which is also a suffix of pat[0..i].
        {
            int len = 0;  // length of previous longest prefix suffix
            int i = 1;    // we start computing lps[1]
            while (i < m) {
                if (pat[i] == pat[len]) {
                    len++;
                    lps[i] = len;
                    i++;
                } else {
                    if (len != 0) {
                        // fallback to the previous longest prefix
                        len = lps[len - 1];
                        // do not increment i here
                    } else {
                        // no proper prefix matches
                        lps[i] = 0;
                        i++;
                    }
                }
            }
        }

        // 2) Scan txt with two pointers: i over txt, j over pat
        vector<int> result;
        int i = 0; // index for txt
        int j = 0; // index for pat
        while (i < n) {
            if (txt[i] == pat[j]) {
                i++;
                j++;
                if (j == m) {
                    // full match of pat ends at i-1, so start position is (i - m)
                    // convert to 1-based index:
                    result.push_back((i - m) + 1);
                    // continue searching for next possible match
                    j = lps[j - 1];
                }
            } else {
                if (j != 0) {
                    // fallback in the pattern
                    j = lps[j - 1];
                } else {
                    // no partial match, advance in text
                    i++;
                }
            }
        }

        return result;
    }
};