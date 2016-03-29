#include <iostream>
#include <string>
#include <unordered_set>
#include <queue>

class Solution {
public:

    int ladderLength(std::string begin_word, std::string end_word, std::unordered_set<std::string>& word_set) {
        int layer_count = 1;

        std::queue<std::string> node_queue;
        node_queue.push(end_word);
        int node_count = 1;
        int next_node_count = 0;
        int visit_count = 0;
        while (node_queue.size() > 0) {
            std::string word = node_queue.front();
            for (int i = 0; i < word.length(); i++) {
                for (char c = 'a'; c <= 'z'; c++) {
                    std::string temp_word = word;
                    temp_word[i] = c;

                    if (temp_word == begin_word) {
                        return layer_count + 1;
                    } else if (word_set.find(temp_word) != word_set.end()) {
                        word_set.erase(temp_word);
                        node_queue.push(temp_word);
                        next_node_count++;
                    }
                }
            }
            node_queue.pop();
            visit_count++;
            if (visit_count == node_count) {
                layer_count++;
                node_count = next_node_count;
                next_node_count = 0;
                visit_count = 0;
            }
        }
        return 0;
    }
};

int main() {
    Solution solution;
    std::unordered_set<std::string> test = {"hot", "dot", "dog", "lot", "log"};
    std::cout << solution.ladderLength("hit", "cog", test) << std::endl;
    return 0;
}