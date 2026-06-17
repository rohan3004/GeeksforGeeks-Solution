class Solution {
public:
    int maxProduct(int n) {
        // Base cases where we are forced to make a cut that reduces the total value
        if (n == 2) return 1;
        if (n == 3) return 2;

        int product = 1;

        // Keep cutting off pieces of length 3 as long as the remaining length is greater than 4
        while (n > 4) {
            product *= 3;
            n -= 3;
        }

        // Multiply whatever is left (will be exactly 2, 3, or 4)
        product *= n;

        return product;
    }
};