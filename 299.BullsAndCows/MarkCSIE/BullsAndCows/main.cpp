#include <iostream>
#include <vector>

class Solution {
public:

    std::string getHint(const std::string &secret, const std::string &guess) {
        unsigned int A = 0;
        unsigned int B = 0;

        std::vector<unsigned int> secret_digits(10, 0);
        std::vector<unsigned int> guess_digits(10, 0);

        for (unsigned int i = 0; i < secret.length(); i++) {
            if (secret[i] == guess[i]) {
                A++;
            } else {
                secret_digits[secret[i] - '0']++;
                guess_digits[guess[i] - '0']++;
            }
        }
        for (unsigned int i = 0; i < 10; i++) {
            B += std::min(secret_digits[i], guess_digits[i]);
        }

        return std::to_string(A) + "A" + std::to_string(B) + "B";
    }
};

int main() {
    Solution solution;
    std::cout << solution.getHint("1807", "7810") << std::endl;
    return 0;
}

