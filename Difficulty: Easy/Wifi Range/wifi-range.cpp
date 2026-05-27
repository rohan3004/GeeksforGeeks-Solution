class Solution {
public:
    bool wifiRange(string &s, int x) {
        int n = s.length();
        
        // Tracks the maximum index covered by WiFi so far.
        // Initialized to -1 because no rooms are covered initially.
        int max_covered = -1; 
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                // The current router covers from (i - x) to (i + x).
                // If its left reach leaves a gap from the previous coverage, return false.
                if (i - x > max_covered + 1) {
                    return false;
                }
                
                // Update the furthest covered room.
                max_covered = max(max_covered, i + x);
            }
        }
        
        // Check if the coverage reaches the very last room.
        return max_covered >= n - 1;
    }
};