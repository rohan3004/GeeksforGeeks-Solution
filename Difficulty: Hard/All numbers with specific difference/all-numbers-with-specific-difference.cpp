class Solution {
public:
    
    long long digitSum(long long x) {
        long long sum = 0;
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }
    
    int getCount(int n, int d) {
        long long low = 1, high = n;
        long long ans = -1;
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            
            if (mid - digitSum(mid) >= d) {
                ans = mid;
                high = mid - 1;  // search smaller valid
            } else {
                low = mid + 1;
            }
        }
        
        if (ans == -1) return 0;
        
        return n - ans + 1;
    }
};
