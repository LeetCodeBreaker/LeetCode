#include <iostream>
#include <vector>
#include <string>
#include <bitset>

class Solution {
public:

    int maxProduct(const std::vector<std::string> &words) {
        // Convert words into bitsets
        std::vector<std::bitset < 26 >> word_bits(words.size());
        for (int i = 0; i < words.size(); i++) {
            for (const auto &word : words[i]) {
                word_bits[i].set(word - 'a');
            }
        }

        int max = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if ((word_bits[i] & word_bits[j]).any() == false && words[i].length() * words[j].length() > max) {
                    max = words[i].length() * words[j].length();
                }
            }
        }
        return max;
    }
};

int main() {
    Solution solution;
    std::vector<std::string> test{"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
    std::cout << solution.maxProduct(test) << std::endl;
    return 0;
}

