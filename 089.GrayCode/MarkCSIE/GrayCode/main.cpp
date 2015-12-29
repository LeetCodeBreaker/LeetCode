#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>

class Solution {
public:
    std::vector<int> grayCode(int n) {
        std::vector<int> answer;
        answer.push_back(0);
        for (int i = 0; i < n; i++) {
            for (int j = answer.size() - 1; j >=0 ; j--) {
                answer.push_back(answer[j] + std::pow(2, i));
            }
        }
        return answer;
    }
};

int main() {
    Solution solution;
    std::vector<int> answer = solution.grayCode(3);
    for (int num : answer) {
        std::cout << std::bitset<8>(num) << std::endl;
    }
    return 0;
}