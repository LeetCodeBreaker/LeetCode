#include <iostream>
#include <vector>

class Solution {
public:

    void gameOfLife(std::vector<std::vector<int>> &board) {
        const int m = board.size();
        const int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                check(board, i, j);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] > 1) {
                    board[i][j] = 0;
                } else if (board[i][j] < 0) {
                    board[i][j] = 1;
                }
            }
        }

    }
private:

    void check(std::vector<std::vector<int>> &board, const int &i, const int &j) {
        const int m = board.size();
        const int n = board[0].size();

        unsigned int count = 0;
        for (int a = -1; a <= 1; a++) {
            int index_i = i + a;
            if (index_i >= 0 && index_i < m) {
                for (int b = -1; b <= 1; b++) {
                    if (a == 0 && b == 0) {
                        continue;
                    }
                    int index_j = j + b;
                    if (index_j >= 0 && index_j < n) {
                        if (board[index_i][index_j] > 0) {
                            count++;
                        }
                    }

                }
            }
        }

        if (board[i][j] == 1 && (count < 2 || count > 3)) {
            board[i][j] = 2;
        } else if (board[i][j] == 0 && count == 3) {
            board[i][j] = -1;
        }
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<int>> test = {
        {1, 1},
        {1, 0}
    };

    solution.gameOfLife(test);

    for (const auto &v : test) {
        for (const auto &i : v) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}

