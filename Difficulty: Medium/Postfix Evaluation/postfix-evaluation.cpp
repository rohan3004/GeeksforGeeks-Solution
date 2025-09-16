#include <vector>
#include <string>
#include <stack>
#include <cmath> // Required for pow() and floor()

class Solution {
public:
    /**
     * @brief Evaluates an arithmetic expression in Reverse Polish Notation.
     * @param arr A vector of strings representing the postfix expression.
     * @return An integer representing the evaluated value of the expression.
     */
    int evaluatePostfix(std::vector<std::string>& arr) {
        // Use a stack to hold the operands. 🥞
        std::stack<int> operandStack;

        for (const std::string& token : arr) {
            // Check if the token is an operator.
            if (token == "+" || token == "-" || token == "*" || token == "/" || token == "^") {
                // An operator requires two operands.
                // Pop operand 2 first, then operand 1.
                int operand2 = operandStack.top();
                operandStack.pop();
                int operand1 = operandStack.top();
                operandStack.pop();

                // Perform the corresponding operation.
                if (token == "+") {
                    operandStack.push(operand1 + operand2);
                } else if (token == "-") {
                    operandStack.push(operand1 - operand2);
                } else if (token == "*") {
                    operandStack.push(operand1 * operand2);
                } else if (token == "/") {
                    // Note: The problem specifies floor division.
                    // C++ integer division truncates towards zero.
                    // We can achieve floor division by using floating-point arithmetic.
                    double result = static_cast<double>(operand1) / operand2;
                    operandStack.push(static_cast<int>(floor(result)));
                } else if (token == "^") {
                    operandStack.push(static_cast<int>(pow(operand1, operand2)));
                }
            } else {
                // If the token is not an operator, it must be an operand.
                // Convert string to integer and push onto the stack.
                operandStack.push(stoi(token));
            }
        }

        // The final result is the last remaining element on the stack.
        return operandStack.top();
    }
};