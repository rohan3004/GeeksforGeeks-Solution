#include <numeric>
#include <algorithm>

class Solution {
private:
    // Helper function to simulate pouring from one jug to another
    int pour(int fromCap, int toCap, int d) {
        int from = fromCap;
        int to = 0;
        int step = 1; // Step 1: Initially fill the 'from' jug
        
        while (from != d && to != d) {
            // Find the maximum amount we can pour
            int temp = std::min(from, toCap - to);
            
            // Pour the water
            to += temp;
            from -= temp;
            step++;
            
            // If either jug has reached the target amount, stop
            if (from == d || to == d) {
                break;
            }
            
            // If the 'from' jug is empty, refill it
            if (from == 0) {
                from = fromCap;
                step++;
            }
            
            // If the 'to' jug is full, empty it
            if (to == toCap) {
                to = 0;
                step++;
            }
        }
        return step;
    }

public:
    int minSteps(int m, int n, int d) {
        // Base case: If d is greater than both jug capacities, it's impossible
        if (d > std::max(m, n)) {
            return -1;
        }
        
        // Base case: d must be divisible by the greatest common divisor of m and n
        if (d % std::gcd(m, n) != 0) {
            return -1;
        }
        
        // Return the minimum steps between the two possible pouring sequences
        return std::min(pour(m, n, d), pour(n, m, d));
    }
};