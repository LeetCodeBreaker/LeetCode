#include <iostream>
#include <vector>

class Solution {
public:

    std::vector<std::string> summaryRanges(const std::vector<int> &nums) {
        std::vector<std::string> answer;
        if (nums.size() == 0) {
            return answer;
        }

        int count = 1;
        int head = nums[0];
        int tail = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > head + count) {
                if (head != tail) {
                    answer.push_back(std::to_string(head) + "->" + std::to_string(tail));
                } else {
                    answer.push_back(std::to_string(head));
                }
                head = nums[i];
                count = 0;
            }
            tail = nums[i];
            count++;
        }
        if (head != tail) {
            answer.push_back(std::to_string(head) + "->" + std::to_string(tail));
        } else {
            answer.push_back(std::to_string(head));
        }
        return answer;
    }
};

int main() {
    Solution solution;
    std::vector<int> test{0, 1, 2, 4, 5, 7};
    std::vector<std::string> answer = solution.summaryRanges(test);
    for (const auto &s : answer) {
        std::cout << s << std::endl;
    }
    return 0;
}

