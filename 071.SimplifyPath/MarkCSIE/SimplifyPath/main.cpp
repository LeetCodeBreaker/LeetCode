#include <list>
#include <string>
#include <iostream>

class Solution {
public:

    std::string simplifyPath(std::string path) {
        std::list<std::string> folderList;
        std::string tempString = "";
        int length = path.length();
        for (int i = 0; i < length; i++) {
            if (path[i] != '/') {
                tempString = tempString + path[i];
            }
            if (path[i] == '/' || i == length - 1) {
                if (!tempString.empty()) {
                    if (tempString == "..") {
                        if (!folderList.empty()) {
                            folderList.pop_back();
                        }
                    } else if (tempString != ".") {
                        folderList.push_back(tempString);
                    }
                }
                tempString.clear();
            }
        }
        
        std::string answer = "/";
        for (std::string folder : folderList) {
            answer += folder + "/";
        }
        if (!folderList.empty()) {
            answer.pop_back();
        }
        return answer;
    }
};

int main() {
    Solution solution;
    std::cout << solution.simplifyPath("/a/./b/../../c/") << std::endl;
    std::cout << solution.simplifyPath("/../") << std::endl;
    std::cout << solution.simplifyPath("/...") << std::endl;
    std::cout << solution.simplifyPath("///eHx/..") << std::endl;

    return 0;
}