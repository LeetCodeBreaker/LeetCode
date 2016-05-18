#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <vector>

class Solution {
public:

    void reverseWords(std::string &s) {
        while (s[0] == ' ') {
            s.erase(0, 1);
        }

        if (s.length() == 0) {
            return;
        }
        std::istringstream iss(s);
        std::vector<std::string> tokens{std::istream_iterator<std::string>
            {iss}, std::istream_iterator<std::string>
            {}};

        s = "";
        for (int i = tokens.size() - 1; i >= 0; i--) {
            s += tokens[i] + " ";
        }
        s.erase(s.length() - 1, 1);
    }
};

int main() {
    Solution solution;
    std::string test = "the sky is blue";
    solution.reverseWords(test);
    std::cout << test << std::endl;
    return 0;
}

