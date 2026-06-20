class Solution {
public:
    int getLastDigit(string& a, string& b) {
        // Edge case: Anything to the power of 0 is 1
        if (b == "0") return 1;
        
        // Edge case: 0 to the power of anything (> 0) is 0
        if (a == "0") return 0;
        
        // The last digit of the answer depends ONLY on the last digit of 'a'
        int base = a.back() - '0';
        
        // To find the exponent mod 4, we only need the last two digits of 'b'
        int exp = 0;
        int b_len = b.length();
        
        if (b_len == 1) {
            exp = b[0] - '0';
        } else {
            exp = (b[b_len - 2] - '0') * 10 + (b[b_len - 1] - '0');
        }
        
        // Power cycles repeat every 4th time
        exp = exp % 4;
        
        // If exp % 4 is 0, it means it's the 4th power in the cycle (e.g., 4, 8, 12...)
        if (exp == 0) {
            exp = 4;
        }
        
        // Calculate (base^exp) % 10
        int result = 1;
        for (int i = 0; i < exp; ++i) {
            result = (result * base) % 10;
        }
        
        return result;
    }
};