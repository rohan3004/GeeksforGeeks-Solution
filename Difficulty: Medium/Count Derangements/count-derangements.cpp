class Solution {
  public:
    int derangeCount(int n) {
        // Base cases
        if (n == 1) return 0;
        if (n == 2) return 1;
        
        // a represents D(i-2)
        // b represents D(i-1)
        int a = 0; 
        int b = 1; 
        
        // Calculate derangements from 3 to n
        for (int i = 3; i <= n; i++) {
            int current = (i - 1) * (a + b);
            a = b;
            b = current;
        }
        
        return b;
    }
};