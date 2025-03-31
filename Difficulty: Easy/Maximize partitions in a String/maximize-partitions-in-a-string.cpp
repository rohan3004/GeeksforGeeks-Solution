//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxPartitions(string &s) {
        // code here
        unordered_map<char, int> last_occurrence;
        int count = 0, partition_end = 0, last_partition = -1;
        
        // Store last occurrence index of each character
        for (int i = 0; i < s.size(); ++i) {
            last_occurrence[s[i]] = i;
        }
        
        for (int i = 0; i < s.size(); ++i) {
            partition_end = max(partition_end, last_occurrence[s[i]]);
            
            if (i == partition_end) {  // If we reach the end of a partition
                count++;
                last_partition = i;
            }
        }
        
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends