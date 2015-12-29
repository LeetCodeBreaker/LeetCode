#include <iostream>
#include <string>

class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        int aIndex = a.length() - 1;
        int bIndex = b.length() - 1;
        int carry = 0;
        std::string answer = "";
        while (aIndex >= 0 || bIndex >= 0) {
            int aBit = aIndex < 0 ? 0 : a[aIndex] - '0';
            int bBit = bIndex < 0 ? 0 : b[bIndex] - '0';
            
            int sum = aBit ^ bBit ^ carry;
            carry = (aBit & bBit) | (aBit & carry) | (bBit & carry);
            answer = static_cast<char>(sum + '0') + answer;
            
            aIndex--;
            bIndex--;
        } 
        if (carry > 0) {
            answer = "1" + answer;
        }
        return answer;
    }
};

int main() {
    Solution solution;
    std::cout << solution.addBinary("1010", "1011") << std::endl;
    return 0;
}