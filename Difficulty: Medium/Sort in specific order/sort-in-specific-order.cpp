class Solution {
  public:
    void sortIt(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {
            // Check parity (using bitwise AND is slightly faster than modulo)
            bool aIsOdd = (a & 1);
            bool bIsOdd = (b & 1);
            
            // Case 1: One is odd and the other is even
            if (aIsOdd != bIsOdd) {
                return aIsOdd; // If a is odd, it comes first
            }
            
            // Case 2: Both are odd -> Sort Descending
            if (aIsOdd) {
                return a > b;
            }
            
            // Case 3: Both are even -> Sort Ascending
            return a < b;
        });
    }
};