#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>

class TrieNode {
public:

    TrieNode() : count(0) {
    }

    std::unordered_map<char, TrieNode*> children;
    int count;
    
    // TODO: Destructor
};

class Trie {
private:
    TrieNode root;

public:

    void insert(const std::string &word) {
        TrieNode *current = &root;
        for (int i = 0; i < word.length(); ++i) {
            if (current->children.find(word[i]) == current->children.end()) {
                current->children.insert(std::make_pair(word[i], new TrieNode()));
            }
            current = current->children.find(word[i])->second;
        }
        ++(current->count);
    }

    bool search(const std::string &word) {
        return search(&root, word, 0);
    }


private:

    bool search(const TrieNode* const current, const std::string &word, const int &index) {
        if (index == word.length()) {
            return current->count > 0;
        }

        if (word[index] == '.') {
            bool found = false;
            for (auto it = current->children.begin(); it != current->children.end(); ++it) {
                found |= search(it->second, word, index + 1);
            }
            return found;
        } else {
            auto child = current->children.find(word[index]);
            if (child == current->children.end()) {
                return false;
            } else {
                return search(child->second, word, index + 1);
            }
        }
    }
};

class WordDictionary {
private:
    Trie trie;

public:
    // Adds a word into the data structure.

    void addWord(std::string word) {
        trie.insert(word);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.

    bool search(std::string word) {
        return trie.search(word);
    }
};

int main() {
    WordDictionary wordDictionary;
    wordDictionary.addWord("word");
    std::cout << wordDictionary.search("pattern") << std::endl;
    return 0;
}

