class Solution {
public:
    int maxAmount(vector<int>& arr, int k) {
        long long max_val = 0;
        for (int x : arr) {
            if (x > max_val) max_val = x;
        }
        
        // Binary search to find the minimum threshold price P
        // where the total tickets sold >= P is less than or equal to k
        long long L = 1, R = max_val + 1;
        long long P = R; 
        
        while (L <= R) {
            long long M = L + (R - L) / 2;
            long long count = 0;
            
            for (int x : arr) {
                if (x >= M) {
                    count += (x - M + 1);
                }
            }
            
            if (count <= k) {
                P = M;       // M is a valid threshold, record it
                R = M - 1;   // Try to lower the threshold to get closer to k
            } else {
                L = M + 1;   // Threshold is too low, we are taking more than k tickets
            }
        }
        
        long long profit = 0;
        long long tickets_taken = 0;
        long long MOD = 1000000007;
        
        // Step 2: Sum up all prices >= P
        for (int x : arr) {
            if (x >= P) {
                long long cnt = x - P + 1;
                tickets_taken += cnt;
                
                // Sum of arithmetic progression from x down to P
                long long sum = (long long)(x + P) * cnt / 2;
                profit = (profit + sum) % MOD;
            }
        }
        
        // Step 3: We might need to take some more tickets at price (P - 1)
        // to exactly reach k tickets
        if (tickets_taken < k && P > 1) {
            long long rem = k - tickets_taken;
            long long rem_profit = (rem * (P - 1)) % MOD;
            profit = (profit + rem_profit) % MOD;
        }
        
        return profit;
    }
};
