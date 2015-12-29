#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> answer;
        if (k == 0) {
            std::vector<int> temp2;
            answer.push_back(temp2);
            return answer;
        }
        if (n == k) {
            std::vector<int> temp2;
            for (int i = 1; i <= n; i++) {
                temp2.push_back(i);
            }
            answer.push_back(temp2);
            return answer;
        }
        
        for (int i = n; i >= 1; i--) {
            std::vector<std::vector<int>> subAnswer = combine(i-1, k-1);
            for (int j = 0; j < subAnswer.size(); j++) {
                subAnswer[j].push_back(i);
            }
            answer.insert(std::end(answer), std::begin(subAnswer), std::end(subAnswer));
        }
        return answer;
    }
};

int main() {
    Solution solution;
    solution.combine(10, 7);
    return 0;
}