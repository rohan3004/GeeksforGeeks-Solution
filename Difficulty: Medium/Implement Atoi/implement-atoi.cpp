#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    int myAtoi(string &s) {
        int i = 0;
        int n = s.length();
        int sign = 1;
        int result = 0;

        // 1. Ignore leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // 2. Check for optional sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // 3. Read digits and ignore leading zeros inherently
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';

            // 4. Handle Overflow and Underflow
            // INT_MAX is 2147483647. INT_MAX / 10 is 214748364.
            // If result > 214748364, multiplying by 10 will overflow.
            // If result == 214748364, appending a digit > 7 will overflow.
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        // 5. Apply sign and return
        return result * sign;
    }
};