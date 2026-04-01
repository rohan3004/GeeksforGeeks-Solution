class Solution {
public:
    int countStrings(int n) {
        // Base cases
        if (n == 1) return 2;
        if (n == 2) return 3;

        // Iterative approach to find the nth value (space optimized)
        int a = 2; // S(n-2)
        int b = 3; // S(n-1)
        int result = 0;

        for (int i = 3; i <= n; i++) {
            result = a + b;
            a = b;
            b = result;
        }

        return b;
    }
};