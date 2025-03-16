//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        int n = arr.size();
    if (n <= 1) return 0;
    if (arr[0] == 0) return -1;
    
    int maxReach = arr[0]; // The farthest index that can be reached
    int steps = arr[0];    // Steps we can still take
    int jumps = 1;         // Number of jumps made
    
    for (int i = 1; i < n; i++) {
        if (i == n - 1) return jumps; // If we reached the end
        
        maxReach = max(maxReach, i + arr[i]); // Update the farthest reachable index
        steps--; // Use a step to move forward
        
        if (steps == 0) { // If no steps are left
            jumps++; // Make another jump
            if (i >= maxReach) return -1; // If we can't move further, return -1
            steps = maxReach - i; // Reset steps to the number of steps in the new jump
        }
    }
    return -1;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends