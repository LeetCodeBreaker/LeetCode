from collections import deque


class TrieNode:

    def __init__(self):
        self.dict_link = dict()
        self.is_word = False


class WordDictionary:
    # initialize your data structure here.

    def __init__(self):
        self.root = TrieNode()

    # @param {string} word
    # @return {void}
    # Adds a word into the data structure.
    def addWord(self, word):
        cur_node = self.root
        for c in word:
            i = ord(c) - 97  # ord('a') is 97
            if i not in cur_node.dict_link:
                cur_node.dict_link[i] = TrieNode()
            cur_node = cur_node.dict_link[i]
        cur_node.is_word = True

    # @param {string} word
    # @return {boolean}
    # Returns if the word is in the data structure. A word could
    # contain the dot character '.' to represent any one letter.
    def search(self, word):
        return self.bfs_search(word)

    def bfs_search(self, word):
        container = deque()
        container.append((self.root, 0))  # append root
        N = len(word)
        while container:
            node, word_idx = container.popleft()
            if word_idx == N:
                if node.is_word:
                    return True
                continue

            i = ord(word[word_idx]) - 97
            if i >= 0 and i in node.dict_link:
                container.append((node.dict_link[i], word_idx + 1))
            if i == -51:  # char = '.''
                for next_node in node.dict_link.values():
                    container.append((next_node, word_idx + 1))
        return False
