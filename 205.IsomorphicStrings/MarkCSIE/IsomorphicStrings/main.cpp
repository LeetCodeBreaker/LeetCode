#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:

    bool isIsomorphic(const std::string s, const std::string t) {
        std::unordered_map<char, char> char_map1;
        std::unordered_map<char, char> char_map2;
        for (int i = 0; i < s.length(); i++) {
            auto pair1 = char_map1.find(s[i]);
            auto pair2 = char_map2.find(t[i]);
            if (pair1 != char_map1.end() && pair1->second != t[i] || pair2 != char_map2.end() && pair2->second != s[i]) {
                return false;
            } else {
                char_map1.insert(std::make_pair(s[i], t[i]));
                char_map2.insert(std::make_pair(t[i], s[i]));
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    std::cout << solution.isIsomorphic("egg", "add") << std::endl;
    return 0;
}

