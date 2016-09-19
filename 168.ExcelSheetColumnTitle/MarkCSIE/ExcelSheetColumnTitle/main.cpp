#include <iostream>
#include <string>

class Solution {
public:

    std::string convertToTitle(int n) {
        std::string answer;
        while (n > 0) {
            char digit;
            if (n % 26 == 0) {
                digit = 'Z';
            } else {
                digit = 'A' + n % 26 - 1;
            }

            answer = digit + answer;
            n = n / 26;
            if (digit == 'Z') {
                n -= 1;
            }
        }

        return answer;
    }
};

int main() {
    Solution solution;
    std::cout << solution.convertToTitle(28) << std::endl;
    return 0;
}

