#include <iostream>

class Solution {
public:

    int numTrees(int n) {
        int *answerArray = new int[n + 1];
        answerArray[0] = 1;
        answerArray[1] = 1;
        for (int i = 2; i <= n; i++) {
            answerArray[i] = 0;
            for (int j = 0; j < i; j++) {
                answerArray[i] += answerArray[j] * answerArray[i - j - 1];
            }
        }
        int answer = answerArray[n];
        delete [] answerArray;
        return answer;
    }
};

int main() {
    Solution solution;
    std::cout << solution.numTrees(19) << std::endl;
    
    return 0;
}

