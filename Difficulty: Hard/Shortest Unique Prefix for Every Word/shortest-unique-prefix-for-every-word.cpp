#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    vector<string> findPrefixes(vector<string>& arr) {
        int n = arr.size();
        if (n == 0) return {};
        if (n == 1) return {arr[0].substr(0, 1)};
        
        // 1. Create a sorted copy of the array
        vector<string> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        
        // 2. Map to store the shortest unique prefix for each string
        unordered_map<string, string> prefixMap;
        
        for (int i = 0; i < n; ++i) {
            int maxLcp = 0;
            
            // Compare with the previous string in the sorted array
            if (i > 0) {
                maxLcp = max(maxLcp, getLcp(sortedArr[i], sortedArr[i - 1]));
            }
            
            // Compare with the next string in the sorted array
            if (i < n - 1) {
                maxLcp = max(maxLcp, getLcp(sortedArr[i], sortedArr[i + 1]));
            }
            
            // The shortest unique prefix is 1 character longer than the max shared prefix.
            // (Because no string is a prefix of another, maxLcp + 1 will never exceed the string's length)
            prefixMap[sortedArr[i]] = sortedArr[i].substr(0, maxLcp + 1);
        }
        
        // 3. Build the result based on the original array's order
        vector<string> result;
        for (const string& s : arr) {
            result.push_back(prefixMap[s]);
        }
        
        return result;
    }
    
  private:
    // Helper function to find the length of the Longest Common Prefix (LCP)
    int getLcp(const string& a, const string& b) {
        int i = 0;
        int limit = min(a.length(), b.length());
        while (i < limit && a[i] == b[i]) {
            i++;
        }
        return i;
    }
};