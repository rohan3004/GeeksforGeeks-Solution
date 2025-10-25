#include <vector>
#include <queue>
#include <numeric> // Not strictly needed, but provides std::accumulate
#include <iostream>

// Using std namespace for brevity as in the problem template
using namespace std;

class Solution {
  public:
    /**
     * Finds the minimum number of operations to make the array sum
     * less than or equal to half of its original sum.
     *
     * In one operation, any element can be replaced by its half.
     *
     * @param arr The input vector of integers.
     * @return The minimum number of operations required.
     */
    int minOperations(vector<int>& arr) {
        // Use a priority_queue to act as a max-heap.
        // We must use 'double' to handle fractional values.
        priority_queue<double> max_heap;

        double original_sum = 0.0;

        // 1. Calculate the original sum and populate the max-heap.
        for (int val : arr) {
            original_sum += (double)val;
            max_heap.push((double)val);
        }

        // 2. Define the target sum.
        double target_sum = original_sum / 2.0;

        double current_sum = original_sum;
        int operations_count = 0;

        // 3. Greedily reduce the sum.
        // Keep going as long as our current sum is greater than the target.
        while (current_sum > target_sum) {
            // Count this operation
            operations_count++;

            // Get the largest element from the heap
            double max_val = max_heap.top();
            
            // Remove it
            max_heap.pop();

            // The amount we reduce the sum by is half of the max element
            double reduction = max_val / 2.0;

            // Update the current sum
            current_sum -= reduction;

            // Add the new, halved value back into the heap
            max_heap.push(reduction); 
        }

        // 4. Return the total count
        return operations_count;
    }
};
