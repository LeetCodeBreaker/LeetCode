#include <iostream>
#include <vector>

class Solution {
private:

    enum Direction {
        right,
        down,
        left,
        up,
    };

public:

    std::vector<std::vector<int>> generateMatrix(const int &n) {
        std::vector<std::vector<int>> answer(n, std::vector<int>(n));

        int index_i = 0;
        int index_j = 0;
        Direction direction = right;
        int loop = 0;

        for (int count = 1; count <= n * n; count++) {
            answer[index_i][index_j] = count;

            if (direction == right && index_j == n - 1 - loop) {
                direction = down;
            } else if (direction == down && index_i == n - 1 - loop) {
                direction = left;
            } else if (direction == left && index_j == loop) {
                direction = up;
            } else if (direction == up && index_i == loop + 1) {
                direction = right;
                loop++;
            }

            switch (direction) {
                case right: index_j++;
                    break;
                case down: index_i++;
                    break;
                case left: index_j--;
                    break;
                case up: index_i--;
                    break;
            }

        }
        return answer;
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<int>> answer = solution.generateMatrix(3);
    for (const auto & v : answer) {
        for (const auto & i : v) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

