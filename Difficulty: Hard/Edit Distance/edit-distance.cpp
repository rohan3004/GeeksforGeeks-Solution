//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to compute the edit distance between two strings
    int editDistance(string& s1, string& s2) {
        // code here
        vector<vector<int>> dp(s1.size(),vector<int>(s2.size(),-1));
        return func(s1.size()-1,s2.size()-1,s1,s2,dp);
    }
    int func(int i,int j,string& s1, string& s2,vector<vector<int>> &dp){
        if(i<0)return j+1;
        if(j<0)return i+1;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s2[j])return dp[i][j]=func(i-1,j-1,s1,s2,dp);
        return dp[i][j]= 1 + min(func(i-1,j-1,s1,s2,dp),min(func(i,j-1,s1,s2,dp),func(i-1,j,s1,s2,dp)));
        //insert, remove and replace operations on dp
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s1;
        getline(cin, s1);
        string s2;
        getline(cin, s2);
        Solution ob;
        int ans = ob.editDistance(s1, s2);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends