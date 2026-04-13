class Solution {
public:
    vector<int> nextPalindrome(vector<int>& num) {
        int n = num.size();
        
        // Step 1: Check if all digits are 9
        bool allNines = true;
        for (int digit : num) {
            if (digit != 9) {
                allNines = false;
                break;
            }
        }
        
        // If all 9s, the next palindrome is 10...01
        if (allNines) {
            vector<int> res(n + 1, 0);
            res[0] = 1;
            res[n] = 1;
            return res;
        }
        
        // Step 2: Find the first mismatch radiating from the center
        int i = (n - 1) / 2;
        int j = n / 2;
        
        while (i >= 0 && num[i] == num[j]) {
            i--;
            j++;
        }
        
        // Step 3: Determine if mirroring makes the number smaller or if it was already a palindrome
        bool leftSmaller = (i < 0 || num[i] < num[j]);
        
        // Step 4: Mirror the left half to the right half
        for (int k = 0; k <= (n - 1) / 2; k++) {
            num[n - 1 - k] = num[k];
        }
        
        // Step 5: If the mirrored number is not strictly greater, increment the middle and propagate carry
        if (leftSmaller) {
            int carry = 1;
            i = (n - 1) / 2;
            
            while (i >= 0 && carry > 0) {
                num[i] += carry;
                carry = num[i] / 10;
                num[i] %= 10;
                
                // Keep the right half mirrored
                num[n - 1 - i] = num[i]; 
                i--;
            }
        }
        
        return num;
    }
};