//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
  unordered_map<string, int> memo;
  int countWaysUtil(string &s, int i, int j, bool isTrue) {
        if (i > j) return 0;
        if (i == j) {
            if (isTrue) return s[i] == 'T';
            else return s[i] == 'F';
        }
        
        string key = to_string(i) + "_" + to_string(j) + "_" + to_string(isTrue);
        if (memo.find(key) != memo.end()) return memo[key];
        
        int ways = 0;
        for (int k = i + 1; k < j; k += 2) {
            int leftTrue = countWaysUtil(s, i, k - 1, true);
            int leftFalse = countWaysUtil(s, i, k - 1, false);
            int rightTrue = countWaysUtil(s, k + 1, j, true);
            int rightFalse = countWaysUtil(s, k + 1, j, false);
            
            if (s[k] == '&') {
                if (isTrue) ways += leftTrue * rightTrue;
                else ways += leftFalse * rightFalse + leftTrue * rightFalse + leftFalse * rightTrue;
            } 
            else if (s[k] == '|') {
                if (isTrue) ways += leftTrue * rightTrue + leftTrue * rightFalse + leftFalse * rightTrue;
                else ways += leftFalse * rightFalse;
            } 
            else if (s[k] == '^') {
                if (isTrue) ways += leftTrue * rightFalse + leftFalse * rightTrue;
                else ways += leftTrue * rightTrue + leftFalse * rightFalse;
            }
        }
        
        return memo[key] = ways;
    }
    int countWays(string &s) {
        // code here
         memo.clear();
        return countWaysUtil(s, 0, s.size() - 1, true);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        int ans = ob.countWays(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends