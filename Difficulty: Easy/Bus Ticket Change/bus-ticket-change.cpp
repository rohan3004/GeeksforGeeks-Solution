class Solution {
  public:
    bool canServe(vector<int> &arr) {
        int count5 = 0;
        int count10 = 0;

        for (int bill : arr) {
            if (bill == 5) {
                // Just collect the bill
                count5++;
            } 
            else if (bill == 10) {
                // We need to give back one 5
                if (count5 > 0) {
                    count5--;
                    count10++;
                } else {
                    return false; // Cannot give change
                }
            } 
            else { // bill == 20
                // We need to give back 15. 
                // Strategy: Try to get rid of a 10 first (greedy), as 5s are more valuable for future change.
                if (count10 > 0 && count5 > 0) {
                    count10--;
                    count5--;
                } else if (count5 >= 3) {
                    count5 -= 3;
                } else {
                    return false; // Cannot give change
                }
            }
        }
        
        return true;
    }
};