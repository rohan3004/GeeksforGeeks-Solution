class Solution {
  public:
    int andInRange(int l, int r) {
        int shiftCount = 0;
        
        // Keep shifting right until the numbers are equal
        // This isolates the Most Significant Bits (common prefix)
        while (l != r) {
            l = l >> 1;
            r = r >> 1;
            shiftCount++;
        }
        
        // Shift back to the left to restore the value with trailing zeros
        return l << shiftCount;
    }
};