#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        vector<int> result;
        sort(b.begin(), b.end());  // Step 1: sort b

        for (int x : a) {
            // Step 2: count how many elements in b are <= x using upper_bound
            int count = upper_bound(b.begin(), b.end(), x) - b.begin();
            result.push_back(count);
        }
        return result;
    }
};
