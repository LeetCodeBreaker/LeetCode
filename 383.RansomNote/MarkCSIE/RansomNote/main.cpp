#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:

    bool canConstruct(const std::string &ransomNote, const std::string &magazine) {
        std::unordered_map<char, int> letter_map;
        for (const auto &c : magazine) {
            if (letter_map.find(c) == letter_map.end()) {
                letter_map[c] = 1;
            } else {
                letter_map[c]++;
            }
        }

        for (const auto &c : ransomNote) {
            if (letter_map.find(c) == letter_map.end() || letter_map[c] == 0) {
                return false;
            } else {
                letter_map[c]--;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    std::cout << solution.canConstruct("aa", "aab") << std::endl;
    return 0;
}

