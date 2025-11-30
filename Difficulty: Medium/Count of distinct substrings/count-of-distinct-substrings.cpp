#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countSubs(string& s) {
        int n = s.length();
        
        // 1. Create a list of all suffixes
        vector<string> suffixes;
        suffixes.reserve(n);
        for (int i = 0; i < n; i++) {
            suffixes.push_back(s.substr(i));
        }
        
        // 2. Sort the suffixes lexicographically
        // This brings suffixes with common prefixes next to each other
        sort(suffixes.begin(), suffixes.end());
        
        // 3. Initialize count with the length of the first suffix
        // (The first suffix has no predecessor to share a prefix with)
        int count = suffixes[0].length();
        
        // 4. Iterate through the rest of the suffixes
        for (int i = 1; i < n; i++) {
            // Find the length of the Longest Common Prefix (LCP)
            // between the current suffix and the previous one
            int j = 0;
            int limit = min(suffixes[i].length(), suffixes[i-1].length());
            
            while (j < limit && suffixes[i][j] == suffixes[i-1][j]) {
                j++;
            }
            
            // Add the number of new substrings contributed by this suffix
            // Formula: Length of Suffix - Length of Overlap (LCP)
            count += (suffixes[i].length() - j);
        }
        
        return count;
    }
};