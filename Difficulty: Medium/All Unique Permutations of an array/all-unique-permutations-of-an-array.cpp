#include <vector>
#include <algorithm>
#include <vector>

class Solution {
  public:
    vector<vector<int>> uniquePerms(vector<int>& arr) {
        // Create a vector of vectors to store the unique permutations.
        vector<vector<int>> result;

        // Sort the input array. This is essential for std::next_permutation
        // to work correctly and to generate permutations in sorted order.
        sort(arr.begin(), arr.end());

        // Use a do-while loop to generate all unique permutations.
        do {
            // Add the current permutation to our result vector.
            result.push_back(arr);
        } while (next_permutation(arr.begin(), arr.end()));

        // Return the final list of permutations.
        return result;
    }
};