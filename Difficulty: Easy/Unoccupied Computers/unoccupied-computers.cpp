class Solution {
  public:
    int solve(int n, string s) {
        // status array tracks each customer's state: 
        // 0 = unvisited, 1 = using a computer, 2 = rejected
        int status[26] = {0}; 
        int available = n;
        int rejected = 0;

        for (char c : s) {
            int idx = c - 'A';

            if (status[idx] == 0) { 
                // Customer's arrival
                if (available > 0) {
                    available--; // Assign a computer
                    status[idx] = 1;
                } else {
                    rejected++; // No computer available, reject customer
                    status[idx] = 2;
                }
            } else if (status[idx] == 1) { 
                // Customer's departure and they were using a computer
                available++; // Free up the computer
            }
            // If status is 2, the customer was already rejected upon arrival, 
            // so we do nothing on their departure event.
        }

        return rejected;
    }
};