#include <vector>
#include <unordered_set>

class Solution {
  public:
    std::vector<int> findUnion(std::vector<int>& a, std::vector<int>& b) {
        // Initialize an unordered_set with the elements of the first array
        std::unordered_set<int> unionSet(a.begin(), a.end());
        
        // Insert elements of the second array into the set
        unionSet.insert(b.begin(), b.end());
        
        // Convert the set back into a vector and return
        return std::vector<int>(unionSet.begin(), unionSet.end());
    }
};