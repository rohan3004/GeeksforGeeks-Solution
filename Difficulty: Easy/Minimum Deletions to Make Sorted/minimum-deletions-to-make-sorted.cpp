#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int minDeletions(vector<int>& arr) {
        vector<int> lis;
        
        for (int num : arr) {
            // Find the first element in 'lis' that is >= num
            auto it = lower_bound(lis.begin(), lis.end(), num);
            
            // If num is greater than all elements, extend the sequence
            if (it == lis.end()) {
                lis.push_back(num);
            } 
            // Otherwise, replace the found element to maintain the smallest 
            // possible sequence endpoints
            else {
                *it = num;
            }
        }
        
        // The minimum deletions required is the total elements minus the elements we keep
        return arr.size() - lis.size();
    }
};