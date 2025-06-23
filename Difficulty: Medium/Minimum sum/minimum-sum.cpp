#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // Helper to add two non-negative integer strings
    string addStrings(const string &a, const string &b) {
        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        string res;
        while (i >= 0 || j >= 0 || carry) {
            int x = i >= 0 ? a[i--] - '0' : 0;
            int y = j >= 0 ? b[j--] - '0' : 0;
            int sum = x + y + carry;
            res.push_back(char('0' + (sum % 10)));
            carry = sum / 10;
        }
        reverse(res.begin(), res.end());
        // strip leading zeros, but leave one if all zeros
        int pos = 0;
        while (pos + 1 < (int)res.size() && res[pos] == '0') 
            ++pos;
        return res.substr(pos);
    }
    
    string minSum(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        // build two numbers with balanced lengths
        string s1, s2;
        s1.reserve(arr.size()/2 + 1);
        s2.reserve(arr.size()/2 + 1);
        for (int d : arr) {
            if (s1.size() <= s2.size())
                s1.push_back(char('0' + d));
            else
                s2.push_back(char('0' + d));
        }
        return addStrings(s1, s2);
    }
};
