class Solution {
public:
    long long sumXOR(vector<int> &arr) {
        long long totalSum = 0;
        int n = arr.size();
        
        // Iterate through all 32 bits of an integer
        for (int i = 0; i < 32; i++) {
            long long count0 = 0, count1 = 0;
            
            // Count how many elements have the i-th bit set to 0 or 1
            for (int j = 0; j < n; j++) {
                if (arr[j] & (1 << i)) {
                    count1++;
                } else {
                    count0++;
                }
            }
            
            // The contribution of this bit to the total sum is 
            // the number of valid pairs (count0 * count1) multiplied by 2^i
            // We use 1LL to ensure the shift operation results in a long long
            totalSum += (count0 * count1) * (1LL << i);
        }
        
        return totalSum;
    }
};