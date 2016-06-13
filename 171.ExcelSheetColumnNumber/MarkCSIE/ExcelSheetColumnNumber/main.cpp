#include <iostream>
#include <string>
#include <cmath>

class Solution {
public:

    int titleToNumber(const std::string &s) {
        int answer = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            answer += std::pow(26, s.length() - i - 1) * (s[i] - 'A' + 1);
        }
        return answer;
    }
};

int main() {
    Solution solution;
    std::cout << solution.titleToNumber("AB") << std::endl;
    return 0;
}

