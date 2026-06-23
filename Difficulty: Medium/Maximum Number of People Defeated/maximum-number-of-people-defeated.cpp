class Solution {
  public:
    int maxPeopleDefeated(int p) {
        int count = 0;
        long long i = 1; // Using long long to prevent any potential overflow during i * i
        
        while (p >= i * i) {
            p -= (i * i);
            count++;
            i++;
        }
        
        return count;
    }
};