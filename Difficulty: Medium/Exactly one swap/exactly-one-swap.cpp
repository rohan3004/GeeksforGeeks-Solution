#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    int countStrings(string &s) {
        int n = s.size();
        unordered_map<char, int> freq;

        // Count frequency of each character
        for (int i = 0; i < n; ++i) {
            freq[s[i]]++;
        }

        // If all characters are the same, any swap yields the same string
        if (freq.size() == 1) {
            return 1;
        }

        // Total number of (i<j) swaps
        long long totalSwaps = (1LL * n * (n - 1)) / 2;

        // Count swaps that swap equal characters (produce the original string)
        long long sameCharSwaps = 0;
        for (unordered_map<char, int>::iterator it = freq.begin(); it != freq.end(); ++it) {
            long long c = it->second;
            sameCharSwaps += (c * (c - 1)) / 2;
        }

        // Distinct strings = 
        //   all swaps that change the string +
        //   1 copy of the original (if any identical-character swap exists)
        long long distinct = totalSwaps - sameCharSwaps;
        if (sameCharSwaps > 0) {
            distinct += 1;
        }
        return (int)distinct;
    }
};

// Optional test driver
/*
int main() {
    Solution sol;
    vector<string> tests = {"geek", "aaaa", "qvn"};
    for (auto &t : tests) {
        cout << t << " -> " << sol.countStrings(t) << "\n";
    }
    // Expected:
    // geek -> 6
    // aaaa -> 1
    // qvn  -> 3
    return 0;
}
*/
