#include <iostream>
#include <string>

class Solution {
public:

    int compareVersion(const std::string &version1, const std::string &version2) {
        std::string rest_string1 = version1;
        std::string rest_string2 = version2;

        while (true) {
            int v1 = 0;
            if (!rest_string1.empty()) {
                std::size_t found1 = rest_string1.find('.');
                v1 = std::stoi(rest_string1.substr(0, found1));
                if (found1 != std::string::npos) {
                    rest_string1 = rest_string1.substr(found1 + 1);
                } else {
                    rest_string1 = "";
                }
            }

            int v2 = 0;
            if (!rest_string2.empty()) {
                std::size_t found2 = rest_string2.find('.');
                v2 = std::stoi(rest_string2.substr(0, found2));
                if (found2 != std::string::npos) {
                    rest_string2 = rest_string2.substr(found2 + 1);
                } else {
                    rest_string2 = "";
                }
            }

            if (v1 > v2) {
                return 1;
            } else if (v1 < v2) {
                return -1;
            } else if (rest_string1.empty() && rest_string2.empty()) {
                return 0;
            }

        }
    }
};

int main() {
    Solution solution;
    std::cout << solution.compareVersion("1.0.1", "1") << std::endl;
    return 0;
}

