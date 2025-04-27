//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /*You are required to complete below function */
    string multiplyStrings(string& s1, string& s2) {
        // Determine sign of the result
        bool negative = false;
        if (!s1.empty() && s1[0] == '-') {
            negative = !negative;
            s1.erase(s1.begin());
        }
        if (!s2.empty() && s2[0] == '-') {
            negative = !negative;
            s2.erase(s2.begin());
        }
        
        // Remove leading zeros
        auto stripZeros = [](const string &s) {
            size_t i = 0;
            while (i < s.size() && s[i] == '0') i++;
            return i == s.size() ? string("0") : s.substr(i);
        };
        s1 = stripZeros(s1);
        s2 = stripZeros(s2);
        
        // If either is "0", result is "0"
        if (s1 == "0" || s2 == "0") {
            return "0";
        }
        
        int n1 = s1.size(), n2 = s2.size();
        vector<int> result(n1 + n2, 0);
        
        // Multiply each digit
        for (int i = n1 - 1; i >= 0; --i) {
            int d1 = s1[i] - '0';
            for (int j = n2 - 1; j >= 0; --j) {
                int d2 = s2[j] - '0';
                int sum = result[i + j + 1] + d1 * d2;
                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }
        
        // Convert result vector to string, skipping leading zeros
        string product;
        product.reserve(result.size());
        size_t pos = 0;
        while (pos < result.size() && result[pos] == 0) pos++;
        for (; pos < result.size(); ++pos) {
            product.push_back(char('0' + result[pos]));
        }
        
        // Prepend sign if negative
        if (negative) {
            product.insert(product.begin(), '-');
        }
        return product;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string a;
        string b;
        cin >> a >> b;
        Solution obj;
        cout << obj.multiplyStrings(a, b) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends