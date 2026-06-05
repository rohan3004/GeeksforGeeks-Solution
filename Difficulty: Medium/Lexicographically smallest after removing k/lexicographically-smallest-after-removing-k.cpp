class Solution {
  public:
    string lexicographicallySmallest(string &s, int k) {
        int n = s.length();
        
        // Step 1: Adjust k based on whether n is a power of 2
        if ((n & (n - 1)) == 0) {
            k /= 2;
        } else {
            k *= 2;
        }
        
        // Step 2: If we need to remove all characters or more than available
        if (k >= n) {
            return "-1";
        }
        
        string res = "";
        
        // Step 3: Build the lexicographically smallest sequence
        for (char c : s) {
            // While the result string has characters, we still need to remove characters (k > 0),
            // and the last character in result is strictly greater than the current one
            while (!res.empty() && k > 0 && res.back() > c) {
                res.pop_back();
                k--;
            }
            res.push_back(c);
        }
        
        // If we still need to remove characters, remove from the end
        while (k > 0) {
            res.pop_back();
            k--;
        }
        
        // Fallback safety check for an empty string
        return res.empty() ? "-1" : res;
    }
};