class Solution {
  public:
    // Helper function to find the largest power of 2 (x) such that 2^x <= n
    int largestPowerOf2(int n) {
        int x = 0;
        // Shift 1 to the left (1 << x) is equivalent to 2^x
        while ((1 << (x + 1)) <= n) {
            x++;
        }
        return x;
    }

    int countSetBits(int n) {
        // Base case: if n is 0, no bits are set
        if (n == 0) return 0;

        // Step 1: Find largest power of 2 less than or equal to n
        int x = largestPowerOf2(n);

        // Step 2: Calculate bits for the full range [0 to 2^x - 1]
        // Formula: x * 2^(x-1)
        int bitsInFullRange = x * (1 << (x - 1));

        // Step 3: Calculate the MSB for the remaining numbers [2^x to n]
        int msbFromRest = n - (1 << x) + 1;

        // Step 4: Recursively calculate bits for the remaining pattern
        int rest = countSetBits(n - (1 << x));

        return bitsInFullRange + msbFromRest + rest;
    }
};