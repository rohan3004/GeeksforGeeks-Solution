//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        for(int seq = 2; seq <= n; ++seq) {
            string next;
            int count = 1;
            // iterate through result, grouping identical digits
            for(int i = 1; i < (int)result.size(); ++i) {
                if(result[i] == result[i-1]) {
                    ++count;
                } else {
                    // flush the previous run
                    next += char('0' + count);
                    next += result[i-1];
                    count = 1;
                }
            }
            // flush the final run
            next += char('0' + count);
            next += result.back();
            result.swap(next);
        }
        return result;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.countAndSay(n) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends