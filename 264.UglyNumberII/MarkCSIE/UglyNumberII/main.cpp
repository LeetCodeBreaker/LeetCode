#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:

    int nthUglyNumber(const int &n) {
        std::vector<int> ugly_numbers;
        std::vector<int> primes = {2, 3, 5};
        std::vector<int> prime_index(primes.size(), 0);
        std::vector<int> candidates = primes;

        ugly_numbers.push_back(1);
        while (ugly_numbers.size() < n) {
            std::vector<int>::iterator min_iterator = std::min_element(candidates.begin(), candidates.end());
            if (*min_iterator > ugly_numbers.back()) {
                ugly_numbers.push_back(*min_iterator);
            }

            int min_index = std::distance(candidates.begin(), min_iterator);
            candidates[min_index] = ugly_numbers[prime_index[min_index]] * primes[min_index];
            prime_index[min_index]++;
        }
        return ugly_numbers.back();
    }
};

int main() {
    Solution solution;
    std::cout << solution.nthUglyNumber(10) << std::endl;
    return 0;
}

