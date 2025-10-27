#include <vector>
#include <queue>
#include <utility> // For std::pair

using namespace std;

class Solution {
public:
    /**
     * Finds the k pairs with the smallest sums from two sorted arrays.
     *
     * This problem can be efficiently solved using a min-heap (priority queue).
     * The core idea is similar to "merging k sorted lists".
     *
     * Imagine we have 'n' sorted lists, where n = arr1.size().
     * List 0: [arr1[0]+arr2[0], arr1[0]+arr2[1], arr1[0]+arr2[2], ...]
     * List 1: [arr1[1]+arr2[0], arr1[1]+arr2[1], arr1[1]+arr2[2], ...]
     * ...
     * List n-1: [arr1[n-1]+arr2[0], arr1[n-1]+arr2[1], ...]
     *
     * We want to find the k smallest elements from all these lists combined.
     *
     * 1. We create a min-heap that stores tuples of: {sum, {index_in_arr1, index_in_arr2}}.
     * 2. We initialize the heap with the first element from each of the 'n' conceptual lists.
     * These are (arr1[0], arr2[0]), (arr1[1], arr2[0]), ..., (arr1[n-1], arr2[0]).
     * Optimization: Since we only need k pairs, if n > k, we only need to
     * consider the first k elements of arr1. Any pair starting with arr1[k]
     * will be larger than k pairs we can already form with arr1[0...k-1].
     * So, we push {arr1[i] + arr2[0], {i, 0}} for i from 0 to min(n, k).
     *
     * 3. We then loop k times (or until the heap is empty):
     * a. Extract the smallest pair (sum, {i, j}) from the min-heap.
     * b. Add this pair {arr1[i], arr2[j]} to our result.
     * c. Add the *next* element from the *same list* (list 'i') to the heap.
     * This next element is {arr1[i] + arr2[j+1], {i, j+1}}.
     * d. We only do this if 'j+1' is a valid index in arr2.
     *
     * This process ensures that we always have the smallest available candidates
     * in the heap and efficiently find the k smallest pairs without generating
     * all n*m combinations.
     *
     * Complexity:
     * - Let n = arr1.size(), m = arr2.size()
     * - Let H = min(n, k).
     * - Time:
     * - Initialization: O(H * log(H)) to build the initial heap.
     * - Loop: We extract k times. Each extraction (pop + push) takes O(log(H)).
     * - Total Time: O(H * log(H) + k * log(H)) = O((k + H) * log(H))
     * - Since H <= k, this is bounded by O(k * log(k)).
     * - Space: O(H) = O(min(n, k)) for storing elements in the priority queue.
     */
    vector<vector<int>> kSmallestPair(vector<int>& arr1, vector<int>& arr2, int k) {
        vector<vector<int>> result;
        int n = arr1.size();
        int m = arr2.size();

        // Handle empty input or k=0
        if (n == 0 || m == 0 || k == 0) {
            return result;
        }

        // Define a type alias for our heap element: {sum, {index1, index2}}
        using T = pair<int, pair<int, int>>;

        // Create a min-heap using `greater`
        // It stores {sum, {i, j}}
        priority_queue<T, vector<T>, greater<T>> pq;

        // Initialize the heap with the first element of arr2 paired with
        // the first min(n, k) elements of arr1.
        for (int i = 0; i < n && i < k; ++i) {
            pq.push({arr1[i] + arr2[0], {i, 0}});
        }

        // Extract the k smallest pairs
        // The loop runs k times or until the heap is empty
        while (k-- > 0 && !pq.empty()) {
            // Get the pair with the smallest sum
            auto top = pq.top();
            pq.pop();

            int i = top.second.first;  // Index from arr1
            int j = top.second.second; // Index from arr2

            // Add the pair [arr1[i], arr2[j]] to the result
            result.push_back({arr1[i], arr2[j]});

            // If there's a next element in arr2 for the current arr1[i],
            // push the next pair from this "list" into the heap.
            if (j + 1 < m) {
                pq.push({arr1[i] + arr2[j + 1], {i, j + 1}});
            }
        }

        return result;
    }
};