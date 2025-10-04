#include <vector>
#include <string>
#include <functional>

class Solution {
 public:
  vector<string> findExpr(string &s, int target) {
    vector<string> ans;
    if (s.empty()) {
      return ans;
    }
    
    // Recursive helper function (backtracking)
    // index: current position in the string s
    // path: the expression string built so far
    // eval: the evaluated value of the expression so far
    // prev_operand: the value of the last operand (needed for multiplication)
    function<void(int, string, long long, long long)> backtrack = 
        [&](int index, string path, long long eval, long long prev_operand) {
      
      // Base case: If we have reached the end of the string
      if (index == s.length()) {
        // If the expression evaluates to the target, add it to our results
        if (eval == target) {
          ans.push_back(path);
        }
        return;
      }
      
      string current_num_str;
      long long current_num = 0;
      
      // Iterate through the remaining part of the string to form the next number
      for (int j = index; j < s.length(); ++j) {
        current_num_str += s[j];
        current_num = current_num * 10 + (s[j] - '0');
        
        if (index == 0) {
          // This is the first number in the expression, no operator before it
          backtrack(j + 1, current_num_str, current_num, current_num);
        } else {
          // Addition
          backtrack(j + 1, path + "+" + current_num_str, eval + current_num, current_num);
          
          // Subtraction
          backtrack(j + 1, path + "-" + current_num_str, eval - current_num, -current_num);
          
          // Multiplication
          // This is the tricky part. Since '*' has higher precedence, we need to adjust
          // the evaluation. We "undo" the previous operation on prev_operand and apply
          // the multiplication first.
          // New eval: (eval - prev_operand) + (prev_operand * current_num)
          // New prev_operand: prev_operand * current_num
          backtrack(j + 1, path + "*" + current_num_str, eval - prev_operand + (prev_operand * current_num), prev_operand * current_num);
        }
        
        // If the current number starts with '0' and has more than one digit,
        // we must stop. For example, "05" is not a valid operand.
        // The number "0" itself is valid.
        if (s[index] == '0') {
          break;
        }
      }
    };
    
    backtrack(0, "", 0, 0);
    return ans;
  }
};