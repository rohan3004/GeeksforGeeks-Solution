class Solution {
public:
    int findMax(int n, vector<int>& a, vector<int>& b, vector<int>& k) {
        // Using long long for the difference array to prevent integer overflow
        // since 10^6 operations adding up to 10^6 can exceed the 32-bit int limit.
        vector<long long> diff(n + 1, 0);
        
        // Step 1 & 2: Process all queries in O(1) time per query
        for (int i = 0; i < a.size(); i++) {
            diff[a[i]] += k[i];
            
            // Only subtract if b[i] + 1 is within the array bounds
            if (b[i] + 1 < n) {
                diff[b[i] + 1] -= k[i];
            }
        }
        
        // Step 3: Compute prefix sum to find the max value in O(n) time
        long long max_val = 0;
        long long current_val = 0;
        
        for (int i = 0; i < n; i++) {
            current_val += diff[i];
            if (current_val > max_val) {
                max_val = current_val;
            }
        }
        
        // Returning max_val. Note: The problem template requests an 'int' return type.
        // It's cast automatically, assuming the platform's test cases fit inside an int.
        return max_val; 
    }
};