#include <queue>      // For std::priority_queue
#include <vector>     // For std::vector
#include <functional> // For std::greater

class Solution {
 public:
  /**
   * @brief Finds the minimum cost to connect all ropes.
   *
   * @param arr A vector of integers representing the lengths of the ropes.
   * @return The minimum total cost to connect all ropes.
   */
  int minCost(vector<int>& arr) {
    // We need a min-heap to efficiently get the two smallest ropes.
    // In C++, std::priority_queue is a max-heap by default.
    // We use std::greater<long long> to make it a min-heap.
    
    // We use 'long long' because the intermediate rope lengths and
    // the total cost can easily overflow a 32-bit integer,
    // given the problem constraints (N=10^5, len=10^4).
    std::priority_queue<long long, std::vector<long long>, std::greater<long long>> pq;

    // 1. Insert all rope lengths into the min-heap.
    for (int length : arr) {
      pq.push((long long)length);
    }

    long long total_cost = 0;

    // 2. Loop while there is more than one rope in the heap.
    while (pq.size() > 1) {
      // 3. Extract the two smallest ropes from the heap.
      long long rope1 = pq.top();
      pq.pop();

      long long rope2 = pq.top();
      pq.pop();

      // 4. Calculate the cost of connecting them.
      long long current_cost = rope1 + rope2;

      // 5. Add this cost to the total cost.
      total_cost += current_cost;

      // 6. Push the new, combined rope back into the heap.
      pq.push(current_cost);
    }

    // If the initial array had 0 or 1 rope, the loop
    // never runs, and total_cost remains 0, which is correct.
    
    // The problem signature asks for an 'int' return, which might
    // cause overflow if the total cost exceeds 2^31 - 1.
    // The correct solution for the given constraints requires a
    // 'long long' return type. We cast here to match the signature.
    return (int)total_cost;
  }
};