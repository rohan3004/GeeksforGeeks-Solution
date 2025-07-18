class Solution {
  public:
    int lcmTriplets(int n) {
        // For n <= 2, the max LCM is n itself.
        if (n <= 2) {
            return n;
        }

        // To avoid potential overflow during multiplication, it's safer
        // to perform calculations using a 64-bit integer type (long long).
        // The final result will fit in a 32-bit int for n <= 1000.

        // Case 1: n is odd.
        // The triplet {n, n-1, n-2} is pairwise coprime.
        if (n % 2 != 0) {
            return (int)((long long)n * (n - 1) * (n - 2));
        }
        
        // Case 2: n is even.
        else {
            // Subcase 2a: n is even and a multiple of 3.
            // The triplet {n-1, n-2, n-3} gives the maximum LCM.
            if (n % 3 == 0) {
                return (int)((long long)(n - 1) * (n - 2) * (n - 3));
            }
            // Subcase 2b: n is even but not a multiple of 3.
            // The triplet {n, n-1, n-3} is pairwise coprime and gives the max LCM.
            else {
                return (int)((long long)n * (n - 1) * (n - 3));
            }
        }
    }
};