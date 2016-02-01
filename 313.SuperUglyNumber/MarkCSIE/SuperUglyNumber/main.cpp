#include <iostream>
#include <vector>

class Solution {
public:

    int nthSuperUglyNumber(const int &n, const std::vector<int> &primes) {
        std::vector<int> ugly_numbers;
        std::vector<int> prime_index(primes.size(), 0);

        ugly_numbers.push_back(1);
        while (ugly_numbers.size() < n) {
            int min = -1;
            int index = 0;
            for (int i = 0; i < primes.size(); i++) {
                if (ugly_numbers[prime_index[i]] * primes[i] < min || min == -1) {
                    index = i;
                    min = ugly_numbers[prime_index[i]] * primes[i];
                }
            }
            if (min > ugly_numbers.back()) {
                ugly_numbers.push_back(min);
            }
            prime_index[index]++;
        }
        return ugly_numbers.back();
    }
};

int main() {
    Solution solution;
    std::vector<int> test{2, 7, 13, 19};
    solution.nthSuperUglyNumber(10, test);
    return 0;
}

