class Solution {
public:
    bool isBinaryPalindrome(int n) {
        std::string binary = "";
        
        // Step 1: Extract bits to form the binary representation
        while (n > 0) {
            binary += (n % 2 == 0 ? '0' : '1');
            n /= 2;
        }
        
        // Step 2: Use two pointers to check for palindrome
        int left = 0;
        int right = binary.length() - 1;
        
        while (left < right) {
            if (binary[left] != binary[right]) {
                return false; // Mismatch found, not a palindrome
            }
            left++;
            right--;
        }
        
        return true; // All corresponding bits matched
    }
};