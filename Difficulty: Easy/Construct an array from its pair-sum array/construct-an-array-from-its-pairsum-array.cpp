#include <vector>
#include <cmath>

using namespace std;

class Solution {
  public:
    vector<int> constructArr(vector<int>& arr) {
        long long S = arr.size();
        
        // Calculate n using the quadratic formula: n^2 - n - 2S = 0
        long long n = (1 + sqrt(1 + 8 * S)) / 2;

        vector<int> res(n);

        // Edge case: If n=2 (arr size is 1), there are infinite solutions.
        // We pick one valid pair (1, arr[0]-1).
        if (n == 2) {
            res[0] = 1;
            res[1] = arr[0] - 1;
            return res;
        }

        // General case for n >= 3
        // We use the first three meaningful interactions to solve for res[0]
        // arr[0]   = res[0] + res[1]
        // arr[1]   = res[0] + res[2]
        // arr[n-1] = res[1] + res[2]
        
        long long sum_01 = arr[0];
        long long sum_02 = arr[1];
        long long sum_12 = arr[n - 1];

        // Sum of (res[0] + res[1] + res[2])
        long long sum_012 = (sum_01 + sum_02 + sum_12) / 2;

        // res[0] = (res[0] + res[1] + res[2]) - (res[1] + res[2])
        res[0] = sum_012 - sum_12;

        // Fill the rest of the array using the first n-1 elements of arr
        // arr[i] corresponds to res[0] + res[i+1]
        for (int i = 0; i < n - 1; ++i) {
            res[i + 1] = arr[i] - res[0];
        }

        return res;
    }
};