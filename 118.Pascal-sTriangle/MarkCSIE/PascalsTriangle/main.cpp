#include <iostream>
#include <vector>

class Solution {
public:

    std::vector<std::vector<int>> generate(const int &numRows) {
        std::vector<std::vector<int>> answer(numRows);
        for (int i = 0; i < numRows; i++) {
            int count = 1;
            for (int j = 0; j < i + 1; j++) {
                answer[i].push_back(count);
                count = count * (i - j) / (j + 1);
            }
        }
        return answer;
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<int>> answer = solution.generate(5);
    for (const auto &v : answer) {
        for (const auto &i : v) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

