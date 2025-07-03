#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestKSubstr(string &s, int k) {
        unordered_map<char,int> freq;
        int distinct = 0;
        int maxLen = -1;
        int left = 0;
        
        for (int right = 0; right < (int)s.size(); ++right) {
            char c = s[right];
            if (freq[c] == 0) 
                ++distinct;
            ++freq[c];
            
            // If too many distinct, shrink from the left
            while (distinct > k) {
                char d = s[left++];
                if (--freq[d] == 0) {
                    freq.erase(d);
                    --distinct;
                }
            }
            
            // If exactly k distinct, update answer
            if (distinct == k) {
                maxLen = max(maxLen, right - left + 1);
            }
        }
        
        return maxLen;
    }
};
