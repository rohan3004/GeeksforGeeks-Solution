#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        int start = 0, end = 0;
        int n = arr.size();
        int count = 0;
        unordered_map<int, int> freq;

        for (end = 0; end < n; ++end) {
            // Add current element to the frequency map
            freq[arr[end]]++;

            // Shrink window if we have more than k distinct elements
            while (freq.size() > k) {
                freq[arr[start]]--;
                if (freq[arr[start]] == 0) {
                    freq.erase(arr[start]);
                }
                start++;
            }

            // Count subarrays ending at 'end' with at most k distinct elements
            count += (end - start + 1);
        }

        return count;
    }
};
