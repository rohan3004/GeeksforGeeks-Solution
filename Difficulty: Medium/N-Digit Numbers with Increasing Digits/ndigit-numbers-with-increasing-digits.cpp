#include <vector>

using namespace std;

class Solution {
private:
    void dfs(int length, int current_num, vector<int>& res, int n) {
        // Base condition: If the number has reached the required length, add it to the result
        if (length == n) {
            res.push_back(current_num);
            return;
        }
        
        // Extract the last digit of the current number to ensure strictly increasing order
        int last_digit = current_num % 10;
        
        // Append next possible digits strictly greater than the last digit
        for (int i = last_digit + 1; i <= 9; ++i) {
            dfs(length + 1, current_num * 10 + i, res, n);
        }
    }

public:
    vector<int> increasingNumbers(int n) {
        vector<int> res;
        
        // Edge case: single digit numbers
        if (n == 1) {
            for (int i = 0; i <= 9; ++i) {
                res.push_back(i);
            }
            return res;
        }
        
        // Edge case: impossible to have strictly increasing numbers with more than 9 digits
        if (n > 9) {
            return res;
        }
        
        // Start DFS with numbers 1 through 9 (leading zero is not allowed for length > 1)
        for (int i = 1; i <= 9; ++i) {
            dfs(1, i, res, n);
        }
        
        return res;
    }
};