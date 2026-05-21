class Solution {
  public:
    bool isBitSet(int n) {
        // 0 has no set bits, so we return false immediately.
        if (n == 0) return false;
        
        // If all bits are 1, adding 1 to n flips all 1s to 0s and adds a new MSB.
        // Therefore, n & (n + 1) will be 0.
        return (n & (n + 1)) == 0;
    }
};