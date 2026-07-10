class Solution {
  public:
    int getCount(int n) {
        int count = 0;
        
        // k represents the number of consecutive natural numbers
        for (long long k = 2; ; k++) {
            long long sum_of_first_k_minus_1 = (k * (k - 1)) / 2;
            
            // If the sum to subtract is greater than or equal to n, 
            // a would be 0 or negative, which breaks the rule of natural numbers.
            if (sum_of_first_k_minus_1 >= n) {
                break;
            }
            
            // Check if 'a' is a valid integer
            if ((n - sum_of_first_k_minus_1) % k == 0) {
                count++;
            }
        }
        
        return count;
    }
};