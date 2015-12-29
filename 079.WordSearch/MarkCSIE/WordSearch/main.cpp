#include <iostream>
#include <vector>
#include <string>

class Solution {
public:

    bool exist(std::vector<std::vector<char>>&board, std::string word) {
        int m = board.size();
        int n = board[0].size();
        bool **visited = new bool*[m];
        for (int i = 0; i < m; i++) {
            visited[i] = new bool[n] {
                false
            };
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    visited[i][j] = true;
                    if (recursive(board, visited, i, j, word, 1)) {
                        return true;
                    }
                    visited[i][j] = false;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            delete [] visited[i];
        }
        delete [] visited;
        return false;
    }

    bool recursive(const std::vector<std::vector<char>>&board, bool **visited, const int i, const int j, const std::string word, const int index) {
        if (index >= word.length()) {
            return true;
        }

        int m = board.size();
        int n = board[0].size();

        // up
        if (i - 1 >= 0 && i - 1 < m && j >= 0 && j < n && board[i - 1][j] == word[index] && !visited[i - 1][j]) {
            visited[i - 1][j] = true;
            if (recursive(board, visited, i - 1, j, word, index + 1)) {
                return true;
            }
            visited[i - 1][j] = false;
        }

        // down
        if (i + 1 >= 0 && i + 1 < m && j >= 0 && j < n && board[i + 1][j] == word[index] && !visited[i + 1][j]) {
            visited[i + 1][j] = true;
            if (recursive(board, visited, i + 1, j, word, index + 1)) {
                return true;
            }
            visited[i + 1][j] = false;
        }

        // left
        if (i >= 0 && i < m && j - 1 >= 0 && j - 1 < n && board[i][j - 1] == word[index] && !visited[i][j - 1]) {
            visited[i][j - 1] = true;
            if (recursive(board, visited, i, j - 1, word, index + 1)) {
                return true;
            }
            visited[i][j - 1] = false;
        }

        // right
        if (i >= 0 && i < m && j + 1 >= 0 && j + 1 < n && board[i][j + 1] == word[index] && !visited[i][j + 1]) {
            visited[i][j + 1] = true;
            if (recursive(board, visited, i, j + 1, word, index + 1)) {
                return true;
            }
            visited[i][j + 1] = false;
        }

        return false;
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<char>> board;
    std::vector<char> line1{'A', 'B', 'C', 'E'};
    std::vector<char> line2{'S', 'F', 'E', 'S'};
    std::vector<char> line3{'A', 'D', 'E', 'E'};
    board.push_back(line1);
    board.push_back(line2);
    board.push_back(line3);
    std::cout << solution.exist(board, "ABCESEEEFS") << std::endl;
    return 0;
}