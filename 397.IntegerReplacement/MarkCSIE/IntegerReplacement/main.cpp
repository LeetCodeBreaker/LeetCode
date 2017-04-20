#include <iostream>
#include <unordered_map>

class Solution
{
private:
    std::unordered_map<int, int> memo;
public:
    int integerReplacement(const int &n)
    {
        // DP
        // std::vector<int> O(n + 1, -1);
        // O[1] = 0;
        // for (int i = 2; i <= n; ++i)
        // {
        //     if (i % 2 == 0)
        //     {
        //         O[i] = 1 + O[i/2];
        //     }
        //     else
        //     {
        //         O[i] = 1 + std::min(O[i-1], 1 + O[(i+1)/2]);
        //     }
        // }
        // return O[n];

        if (n == 1)
        {
            return 0;
        }

        if (memo.find(n) != memo.end())
        {
            return memo[n];
        }
        int answer = 0;
        if (n % 2 == 0)
        {
            answer = 1 + integerReplacement(n/2);
        }
        else
        {
            unsigned int more = n+1;
            answer = 1 + std::min(integerReplacement(more / 2) + 1, integerReplacement((n-1) / 2) + 1);
        }
        memo[n] = answer;
        return answer;
    }
};

int main()
{
    Solution solution;
    std::cout << solution.integerReplacement(8) << std::endl;
    return 0;
}

