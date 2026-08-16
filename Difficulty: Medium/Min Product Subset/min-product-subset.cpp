#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
  public:
    int minProd(vector<int>& arr) {
        // If there's only one element, that's our only subset
        if (arr.size() == 1) return arr[0];

        int cnt_neg = 0, cnt_zero = 0, cnt_pos = 0;
        int max_neg = INT_MIN;
        int min_pos = INT_MAX;
        long long prod = 1;

        for (int x : arr) {
            if (x == 0) {
                cnt_zero++;
                continue;
            }
            if (x < 0) {
                cnt_neg++;
                max_neg = max(max_neg, x);
            } else {
                cnt_pos++;
                min_pos = min(min_pos, x);
            }
            prod *= x;
        }

        // Case 1: No negative numbers present
        if (cnt_neg == 0) {
            if (cnt_zero > 0) return 0;
            return min_pos;
        }

        // Case 2: Even count of negative numbers 
        // Exclude the largest negative number (closest to 0) to make the product negative
        if (cnt_neg % 2 == 0 && cnt_neg > 0) {
            prod /= max_neg;
        }

        // Return the casted int (as constrained fits limit logically based on return type)
        return static_cast<int>(prod);
    }
};