#include <vector>
#include <deque>

using namespace std;

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        vector<int> result;
        deque<int> dq; // Stores indices of useful elements

        for (int i = 0; i < arr.size(); ++i) {
            // 1. Remove indices that are out of the current window
            // The window is [i - k + 1, i]. Any index < i - k + 1 is invalid.
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // 2. Maintain decreasing order of values in the deque
            // Remove elements from the back that are smaller than or equal to the current element
            // because they will never be the maximum as long as the current element exists.
            while (!dq.empty() && arr[dq.back()] <= arr[i]) {
                dq.pop_back();
            }

            // 3. Add the current element's index
            dq.push_back(i);

            // 4. Add the maximum element of the current window to the result
            // The first window ends at index k-1.
            if (i >= k - 1) {
                result.push_back(arr[dq.front()]);
            }
        }

        return result;
    }
};