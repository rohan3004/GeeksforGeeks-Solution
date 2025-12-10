#include <vector>
#include <numeric>

using namespace std;

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        long long n = arr.size();

        // Expected Sum and Sum of Squares for 1 to n
        long long SN = (n * (n + 1)) / 2;
        long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

        // Actual Sum and Sum of Squares from the array
        long long S = 0, S2 = 0;
        for (int x : arr) {
            S += x;
            S2 += (long long)x * x;
        }

        // val1 = X - Y (Difference of sums)
        long long val1 = S - SN;

        // val2 = X^2 - Y^2 (Difference of square sums)
        long long val2 = S2 - S2N;

        // val2 now becomes X + Y because (X^2 - Y^2) / (X - Y) = X + Y
        val2 = val2 / val1;

        // We now have:
        // val1 = X - Y
        // val2 = X + Y
        
        // Adding them: 2X = val1 + val2  => X = (val1 + val2) / 2
        long long x = (val1 + val2) / 2;
        
        // Subtracting X from (X + Y) gives Y
        long long y = val2 - x;

        return {(int)x, (int)y};
    }
};