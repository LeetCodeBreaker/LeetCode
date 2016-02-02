#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    void solve(std::vector<std::vector<char>>&board) {
        if (board.size() == 0) {
            return;
        }

        // Top row
        for (int j = 0; j < board[0].size(); j++) {
            if (board[0][j] == 'O') {
                explore(board, 0, j);
            }
        }

        // Bottom row
        for (int j = 0; j < board[board.size() - 1].size(); j++) {
            if (board[board.size() - 1][j] == 'O') {
                explore(board, board.size() - 1, j);
            }
        }

        // Left column
        for (int i = 0; i < board.size(); i++) {
            if (board[i][0] == 'O') {
                explore(board, i, 0);
            }
        }

        // Right column
        for (int i = 0; i < board.size(); i++) {
            if (board[i][board[0].size() - 1] == 'O') {
                explore(board, i, board[0].size() - 1);
            }
        }

        // Relabeling
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == 'P') {
                    board[i][j] = 'O';
                } else {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void explore(std::vector<std::vector<char>>&board, int i, int j) {
        std::queue<std::pair<int, int>> q;
        q.push(std::pair<int, int>(i, j));
        board[i][j] = 'P';
        while (!q.empty()) {
            std::pair<int, int> p = q.front();
            q.pop();
            if (p.first + 1 < board.size() && board[p.first + 1][p.second] == 'O') {
                q.push(std::pair<int, int>(p.first + 1, p.second));
                board[p.first + 1][p.second] = 'P';
            }
            if (p.first - 1 >= 0 && board[p.first - 1][p.second] == 'O') {
                q.push(std::pair<int, int>(p.first - 1, p.second));
                board[p.first - 1][p.second] = 'P';
            }
            if (p.second + 1 < board[p.first].size() && board[p.first][p.second + 1] == 'O') {
                q.push(std::pair<int, int>(p.first, p.second + 1));
                board[p.first][p.second + 1] = 'P';
            }
            if (p.second - 1 >= 0 && board[p.first][p.second - 1] == 'O') {
                q.push(std::pair<int, int>(p.first, p.second - 1));
                board[p.first][p.second - 1] = 'P';
            }
        }
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<char>> test
    {
        {
            'O', 'X', 'X', 'X'
        },
        {
            'X', 'O', 'O', 'X'
        },
        {
            'X', 'X', 'O', 'X'
        },
        {
            'X', 'O', 'X', 'X'
        }
    };

    solution.solve(test);
    for (int i = 0; i < test.size(); i++) {
        for (int j = 0; j < test[i].size(); j++) {
            std::cout << test[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

