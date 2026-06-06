class Solution {
public:
    int numOfWays(int n, int m) {
        // Total number of squares on the board
        long long total_cells = 1LL * n * m;
        
        // Total ways to place two distinct knights anywhere on the board
        long long total_ways = total_cells * (total_cells - 1);
        
        long long attacking_ways = 0;
        
        // Count attacking configurations in 2x3 bounding boxes
        if (n >= 2 && m >= 3) {
            attacking_ways += 4LL * (n - 1) * (m - 2);
        }
        
        // Count attacking configurations in 3x2 bounding boxes
        if (n >= 3 && m >= 2) {
            attacking_ways += 4LL * (n - 2) * (m - 1);
        }
        
        // Return the safe ways
        return static_cast<int>(total_ways - attacking_ways);
    }
};