//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxValue(vector<int>& arr) {
        // your code here
        auto robLinear = [](const vector<int>& houses) {
            int prevMax = 0, currMax = 0;
            for (int value : houses) {
                int temp = currMax;
                currMax = max(currMax, prevMax + value);
                prevMax = temp;
            }
            return currMax;
        };

        // Edge case: only one house
        if (arr.size() == 1) {
            return arr[0];
        }

        // Case 1: Exclude the first house
        int case1 = robLinear(vector<int>(arr.begin() + 1, arr.end()));
        // Case 2: Exclude the last house
        int case2 = robLinear(vector<int>(arr.begin(), arr.end() - 1));

        // Return the maximum of the two cases
        return max(case1, case2);
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends