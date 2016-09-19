#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>

class Solution {
private:
    std::unordered_map<std::string, bool> memo;
public:

    bool wordBreak(const std::string &s, const std::unordered_set<std::string>& word_dict) {
        if (s.empty()) {
            return true;
        }
        bool answer = false;
        std::unordered_set<std::string> temp_word_dict = word_dict;
        for (const auto &word : word_dict) {
            std::size_t found = s.find(word);
            if (found != std::string::npos) {
                std::string pre_s = s.substr(0, found);
                std::string post_s = s.substr(found + word.length());

                bool pre_answer = false;
                const auto pre_found = memo.find(pre_s);
                if (pre_found != memo.end()) {
                    pre_answer = pre_found->second;
                } else {
                    pre_answer = wordBreak(pre_s, temp_word_dict);
                    memo.insert({pre_s, pre_answer});
                }

                bool post_answer = false;
                const auto post_found = memo.find(post_s);
                if (post_found != memo.end()) {
                    post_answer = post_found->second;
                } else {
                    post_answer = wordBreak(post_s, temp_word_dict);
                    memo.insert({post_s, post_answer});
                }

                if (pre_answer && post_answer) {
                    answer = true;
                    break;
                }
            } else {
                temp_word_dict.erase(word);
            }
        }

        return answer;
    }

    //    bool wordBreak2(const std::string& s, const std::unordered_set<std::string>& wordDict) {
    //        bool result(false);
    //        std::vector<bool> f(s.size() + 1, false);
    //        f[0] = true;
    //        for (size_t i = 1; i <= s.size(); ++i) {
    //            for (size_t j = 0; j <= i - 1; ++j) {
    //                if (f[j] && wordDict.count(s.substr(j, i - j))) {
    //                    f[i] = true;
    //                    break;
    //                }
    //            }
    //        }
    //        result = f[s.size()];
    //        return result;
    //    }

};

int main() {
    Solution solution;
    std::unordered_set<std::string> word_dict({"leet", "code"});
    std::cout << std::boolalpha << solution.wordBreak("leetcode", word_dict) << std::endl;
    return 0;
}

