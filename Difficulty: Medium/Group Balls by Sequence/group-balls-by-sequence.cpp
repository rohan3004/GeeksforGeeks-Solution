#include <vector>
#include <map>
using namespace std;

class Solution {
  public:
    bool validgroup(vector<int> &arr, int k) {
        int n = arr.size();
        if (n % k != 0) return false;

        map<int, int> freq;
        for (int num : arr) {
            freq[num]++;
        }

        for (auto it = freq.begin(); it != freq.end(); ++it) {
            int num = it->first;
            int count = it->second;

            if (count > 0) {
                for (int i = 1; i < k; ++i) {
                    if (freq[num + i] < count) {
                        return false;
                    }
                    freq[num + i] -= count;
                }
            }
        }

        return true;
    }
};
