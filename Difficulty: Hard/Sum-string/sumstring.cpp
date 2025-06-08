class Solution {
  public:
    // Helper function to check if str starts with the given sum of a and b
    bool check(string s, string a, string b) {
        if ((a.size() > 1 && a[0] == '0') || (b.size() > 1 && b[0] == '0'))
            return false;

        string sum = addStrings(a, b);
        int len = sum.size();

        if (s.substr(0, len) != sum)
            return false;
        if (s == sum)
            return true;

        // Recurse on remaining string
        return check(s.substr(len), b, sum);
    }

    // Function to add two numeric strings
    string addStrings(string num1, string num2) {
        string result;
        int carry = 0, i = num1.size() - 1, j = num2.size() - 1;

        while (i >= 0 || j >= 0 || carry) {
            int n1 = i >= 0 ? num1[i--] - '0' : 0;
            int n2 = j >= 0 ? num2[j--] - '0' : 0;
            int sum = n1 + n2 + carry;
            carry = sum / 10;
            result.push_back(sum % 10 + '0');
        }

        reverse(result.begin(), result.end());
        return result;
    }

    bool isSumString(string &s) {
        int n = s.size();

        // Try all combinations for first and second number
        for (int i = 1; i <= n / 2; ++i) {
            for (int j = 1; i + j < n; ++j) {
                string a = s.substr(0, i);
                string b = s.substr(i, j);
                string rest = s.substr(i + j);
                if (check(rest, a, b))
                    return true;
            }
        }

        return false;
    }
};
