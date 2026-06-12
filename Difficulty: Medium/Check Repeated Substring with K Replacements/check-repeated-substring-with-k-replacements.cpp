#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool kSubstr(string &s, int k) {
        int n = s.length();
        
        // If the string length is not a multiple of k, we can't form k-length repetitions
        if (n % k != 0) {
            return false;
        }
        
        // Use a hash map to count occurrences of each k-length substring
        unordered_map<string, int> freq;
        for (int i = 0; i < n; i += k) {
            freq[s.substr(i, k)]++;
        }
        
        // If all substrings are already the same
        if (freq.size() == 1) {
            return true;
        }
        
        // If there are exactly two different substrings
        if (freq.size() == 2) {
            auto it = freq.begin();
            int count1 = it->second;
            it++;
            int count2 = it->second;
            
            // We can only fix the string if one of the substrings appears exactly once
            if (count1 == 1 || count2 == 1) {
                return true;
            }
        }
        
        // In any other case, one replacement isn't enough
        return false;
    }
};