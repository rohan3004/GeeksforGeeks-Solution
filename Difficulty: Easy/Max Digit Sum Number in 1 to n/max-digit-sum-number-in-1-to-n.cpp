class Solution {
private:
    // Helper function to calculate the sum of the digits of a number
    int sumDigits(long long x) {
        int sum = 0;
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }

public:
    int findMax(int n) {
        int ans = n;
        int max_sum = sumDigits(n);

        long long b = 10;

        // Loop through powers of 10 to turn the last few digits into 9s
        while (b <= n) {
            // Subtracting the remainder and 1 gives us numbers ending in 9s
            long long cand = n - (n % b) - 1;

            if (cand > 0) {
                int cur_sum = sumDigits(cand);

                // Update the answer if we found a strictly greater sum
                if (cur_sum > max_sum) {
                    max_sum = cur_sum;
                    ans = cand;
                } 
                // If the sum is the same, keep the largest candidate
                else if (cur_sum == max_sum) {
                    if (cand > ans) {
                        ans = cand;
                    }
                }
            }
            b *= 10;
        }

        return ans;
    }
};