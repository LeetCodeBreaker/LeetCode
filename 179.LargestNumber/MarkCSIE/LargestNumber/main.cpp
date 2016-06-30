#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
private:

    static bool compare(const int &i, const int &j) {
        std::string s1 = std::to_string(i);
        std::string s2 = std::to_string(j);
        unsigned int index1 = 0;
        unsigned int index2 = 0;
        while (true) {
            if (s1[index1] > s2[index2]) {
                return true;
            } else if (s2[index2] > s1[index1]) {
                return false;
            } else {
                index1++;
                index2++;
            }

            if (index1 == s1.length() && index2 == s2.length()) {
                return false;
            }

            if (index1 == s1.length()) {
                index1 = 0;
            }
            if (index2 == s2.length()) {
                index2 = 0;
            }
        }
    }
public:

    std::string largestNumber(const std::vector<int>& nums) {
        std::vector<int> sorted_nums = nums;
        std::sort(sorted_nums.begin(), sorted_nums.end(), compare);

        std::string answer;
        for (unsigned int i = 0; i < sorted_nums.size(); i++) {
            if (sorted_nums[i] != 0 || i == sorted_nums.size() - 1 || answer.length() > 0) {
                answer += std::to_string(sorted_nums[i]);
            }
        }
        return answer;

    }
};

int main() {
    Solution solution;
    std::vector<int> test = {3, 30, 34, 5, 9};
    std::cout << solution.largestNumber(test) << std::endl;
    return 0;
}

