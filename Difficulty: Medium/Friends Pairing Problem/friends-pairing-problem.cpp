class Solution {
  public:
    int countFriendsPairings(int n) {
        // Base cases for n = 1 or n = 2
        if (n <= 2) {
            return n;
        }
        
        int prev2 = 1; // Represents f(n-2), starting at f(1)
        int prev1 = 2; // Represents f(n-1), starting at f(2)
        int current = 0;
        
        for (int i = 3; i <= n; i++) {
            // f(i) = f(i-1) + (i-1) * f(i-2)
            current = prev1 + (i - 1) * prev2;
            
            // Shift values for the next iteration
            prev2 = prev1;
            prev1 = current;
        }
        
        return current;
    }
};
