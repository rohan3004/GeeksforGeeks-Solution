#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        vector<int> result;
        
        for (int x : arr) {
            // If the stack is empty, just push the current element
            if (result.empty()) {
                result.push_back(x);
            } else {
                int top = result.back();
                
                // Determine if both elements are non-negative or negative
                bool topIsNonNegative = (top >= 0);
                bool xIsNonNegative = (x >= 0);
                
                // If they have opposite signs, they destroy each other
                if (topIsNonNegative != xIsNonNegative) {
                    result.pop_back();
                } 
                // If they have the same sign, push the new element
                else {
                    result.push_back(x);
                }
            }
        }
        
        return result;
    }
};