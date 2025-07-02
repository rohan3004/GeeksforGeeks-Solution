#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int totalElements(vector<int> &arr) {
        int n = arr.size();
        int left = 0, best = 0;
        unordered_map<int,int> cnt;
        
        for (int right = 0; right < n; ++right) {
            // include arr[right] in the window
            ++cnt[arr[right]];
            
            // if more than two distinct, shrink from left
            while (cnt.size() > 2) {
                if (--cnt[arr[left]] == 0) {
                    cnt.erase(arr[left]);
                }
                ++left;
            }
            
            // window [left..right] has at most 2 distinct
            best = max(best, right - left + 1);
        }
        
        return best;
    }
};
