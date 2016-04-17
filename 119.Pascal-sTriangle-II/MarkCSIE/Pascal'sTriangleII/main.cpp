#include <iostream>
#include <vector>

class Solution {
public:

    std::vector<int> getRow(const int &rowIndex) {
        std::vector<int> answer(rowIndex + 1, 1);
        int mul = rowIndex;
        int div = 1;
        for (int i = 1; i <= answer.size() / 2; i++) {
            int value = static_cast<unsigned long long int> (answer[i - 1]) * mul / div;
            answer[i] = value;
            answer[answer.size() - i - 1] = value;

            mul--;
            div++;
        }
        return answer;
    }
};

int main() {
    Solution solution;

    for (const auto &i : solution.getRow(3)) {
        std::cout << i << std::endl;
    }

    return 0;
}

