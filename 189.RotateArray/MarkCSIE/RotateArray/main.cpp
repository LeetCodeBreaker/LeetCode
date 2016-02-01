#include <iostream>
#include <vector>

class Solution {
public:

    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void subRotate(std::vector<int>& nums, const int &i, const int &k) {
        int curr_index = i;
        int next_index = (i + k) % nums.size();
        int curr_temp = nums[i];
        while (next_index != i) {
            int next_temp = nums[next_index];
            nums[next_index] = curr_temp;
            curr_temp = next_temp;
            curr_index = next_index;
            next_index = (next_index + k) % nums.size();
        }
        nums[next_index] = curr_temp;
    }

    void rotate(std::vector<int>& nums, int k) {
        k %= nums.size();
        if (k == 0) {
            return;
        }
        int g = gcd(nums.size(), k);
        for (int i = 0; i < g; i++) {
            subRotate(nums, i, k);
        }
    }
};

int main() {
    Solution solution;
    std::vector<int> test{1, 2, 3, 4, 5, 6, 7};
    solution.rotate(test, 3);
    for (int i : test) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}

