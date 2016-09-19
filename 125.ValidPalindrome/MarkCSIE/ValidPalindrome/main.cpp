#include <iostream>
#include <string>

class Solution {
public:

    bool isPalindrome(const std::string &s) {
        if (s.length() == 0) {
            return true;
        }

        int front = 0;
        int end = s.length() - 1;
        while (true) {
            while (!std::isalnum(s[front])) {
                front++;
            }
            while (!std::isalnum(s[end])) {
                end--;
            }
            if (front > end) {
                break;
            }
            if (std::tolower(s[front]) != std::tolower(s[end])) {
                return false;
            }
            front++;
            end--;
        }
        return true;
    }
};

int main() {
    Solution solution;
    std::cout << solution.isPalindrome("A man, a plan, a canal: Panama") << std::endl;
    return 0;
}

