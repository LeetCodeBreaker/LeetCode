#include <string>
#include <iostream>

class Solution {
public:

    int numDecodings(std::string s) {
        int length = s.length();
        if (length == 0) {
            return 0;
        }

        int *OPT = new int[length] {
            0
        };
        if (s[length - 1] != '0') {
            OPT[length - 1] = 1;
        }

        if (length > 1 && s[length - 2] == '1' || (s[length - 2] == '2' && s[length - 1] >= '0' && s[length - 1] <= '6')) {
            OPT[length - 2]++;
        }
        if (length > 1 && s[length - 2] != '0' && s[length - 1] != '0') {
            OPT[length - 2]++;
        }

        for (int i = length - 3; i >= 0; i--) {
            int OPT2 = 0;
            int OPT1 = 0;
            if (s[i] == '1' || s[i] == '2' && s[i + 1] >= '0' && s[i + 1] <= '6') {
                OPT2 = OPT[i + 2];
            }
            if (s[i] != '0') {
                OPT1 = OPT[i + 1];
            }
            OPT[i] = OPT2 + OPT1;
        }
        int answer = OPT[0];
        delete [] OPT;

        return answer;
    }
};

int main() {
    Solution solution;
    std::cout << solution.numDecodings("012") << std::endl;
    return 0;
}