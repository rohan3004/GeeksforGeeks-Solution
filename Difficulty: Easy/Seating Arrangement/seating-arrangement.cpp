#include <vector>

using namespace std;

class Solution {
public:
    bool canSeatAllPeople(int k, vector<int>& seats) {
        int n = seats.size();
        
        for (int i = 0; i < n; ++i) {
            // Check for adjacent occupied seats in the initial or modified array
            if (seats[i] == 1) {
                if (i > 0 && seats[i - 1] == 1) {
                    return false;
                }
            } 
            // If the seat is empty and we still need to seat people
            else if (k > 0) {
                bool left_empty = (i == 0 || seats[i - 1] == 0);
                bool right_empty = (i == n - 1 || seats[i + 1] == 0);
                
                if (left_empty && right_empty) {
                    seats[i] = 1; // Seat the person
                    k--;          // Decrement the remaining count
                }
            }
        }
        
        // Return true if we successfully seated all k people
        return k == 0;
    }
};