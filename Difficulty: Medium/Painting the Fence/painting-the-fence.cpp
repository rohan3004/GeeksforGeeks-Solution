class Solution {
public:
    int countWays(int n, int k) {
        // Base case: only one post
        if (n == 1) return k;
        
        // Base case: two posts
        // Posts can be same (k ways) or different (k * (k-1) ways)
        // Total = k + k*k - k = k*k
        long long prev2 = k;            // Represents Total(i-2)
        long long prev1 = (long long)k * k; // Represents Total(i-1)
        
        if (n == 2) return (int)prev1;

        long long current;
        for (int i = 3; i <= n; i++) {
            // Apply the recurrence formula
            current = (prev1 + prev2) * (k - 1);
            
            // Shift values for the next iteration
            prev2 = prev1;
            prev1 = current;
        }

        return (int)prev1;
    }
};