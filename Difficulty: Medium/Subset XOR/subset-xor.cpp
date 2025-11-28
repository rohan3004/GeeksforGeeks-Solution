class Solution {
  public:
    vector<int> subsetXOR(int n) {
        // Step 1: Calculate the XOR sum of all elements from 1 to n
        int totalXor = 0;
        // Optimization: We could use the O(1) pattern for 1..n XOR, 
        // but O(N) is perfectly acceptable given we must iterate to fill the vector anyway.
        for (int i = 1; i <= n; i++) {
            totalXor ^= i;
        }
        
        // Step 2: Determine which number needs to be removed
        // If totalXor ^ K = n, then K = totalXor ^ n
        int k = totalXor ^ n;
        
        // Step 3: Construct the subset
        vector<int> result;
        for (int i = 1; i <= n; i++) {
            // If k is 0, we remove nothing.
            // If k > 0, we skip the specific number k.
            if (i == k) continue;
            result.push_back(i);
        }
        
        return result;
    }
};