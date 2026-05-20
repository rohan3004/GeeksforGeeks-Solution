#include <vector>
#include <unordered_set>

class Solution {
public:
    bool isProduct(std::vector<int>& arr, long long target) {
        std::unordered_set<long long> seen;
        
        for (int x : arr) {
            // Handle the case where the current element is 0
            if (x == 0) {
                if (target == 0) {
                    return true;
                }
            } 
            // Handle non-zero elements
            else {
                if (target % x == 0) {
                    long long required = target / x;
                    if (seen.count(required)) {
                        return true;
                    }
                }
            }
            
            // Add the current element to our seen set
            seen.insert(x);
        }
        
        return false;
    }
};