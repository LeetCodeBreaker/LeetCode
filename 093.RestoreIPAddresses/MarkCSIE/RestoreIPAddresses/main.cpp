#include <string>
#include <vector>
#include <iostream>

class Solution {
public:

    std::vector<std::string> restoreIpAddresses(std::string s) {
        std::vector<std::string> answer_vector_s;
        if (s.length() > 12) {
            return answer_vector_s;
        }
        answer_vector_s = recursive(s, 3);
        return answer_vector_s;
    }

private:

    bool ValidNumber(std::string s) {
        if (s.length() == 0 || s.length() > 3 || (s[0] == '0' && s.length() != 1)) {
            return false;
        }
        if (std::stoi(s) > 255) {
            return false;
        }
        return true;
    }

    std::vector<std::string> recursive(std::string s, int num_dots) {
        std::vector<std::string> answer_vector_s;
        if (num_dots == 0 || s == "") {
            if (ValidNumber(s)) {
                answer_vector_s.push_back(s);
                return answer_vector_s;
            } else {
                return answer_vector_s;
            }
        }

        for (int i = 1; i <= s.length(); i++) {
            std::string segment = s.substr(0, i);
            if (ValidNumber(segment)) {
                std::vector<std::string> vector_s = recursive(s.substr(i), num_dots - 1);
                if (!vector_s.empty()) {
                    for (int j = 0; j < vector_s.size(); j++) {
                        vector_s[j] = segment + "." + vector_s[j];
                    }
                    answer_vector_s.insert(std::end(answer_vector_s), std::begin(vector_s), std::end(vector_s));
                }
            }
        }
        return answer_vector_s;
    }
};

int main() {
    Solution solution;
    std::vector<std::string> answer = solution.restoreIpAddresses("010010");
    for (std::string s : answer) {
        std::cout << s << std::endl;
    }

    return 0;
}

