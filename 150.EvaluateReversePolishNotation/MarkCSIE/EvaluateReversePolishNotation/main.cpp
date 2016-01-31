#include <iostream>
#include <string>
#include <vector>
#include <stack>

class Solution {
public:

    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> num_stack;
        for (std::string s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int num1 = num_stack.top();
                num_stack.pop();
                int num2 = num_stack.top();
                num_stack.pop();

                if (s == "+") {
                    num_stack.push(num2 + num1);
                } else if (s == "-") {
                    num_stack.push(num2 - num1);
                } else if (s == "*") {
                    num_stack.push(num2 * num1);
                } else if (s == "/") {
                    num_stack.push(num2 / num1);
                }
            } else {
                num_stack.push(std::stoi(s));
            }
        }
        return num_stack.top();
    }
};

int main() {
    Solution solution;
    std::vector<std::string> test{"4", "13", "5", "/", "+"};
    std::cout << solution.evalRPN(test) << std::endl;
    return 0;
}

