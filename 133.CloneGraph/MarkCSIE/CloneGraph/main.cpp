#include <vector>
#include <map>

// Definition for undirected graph.

struct UndirectedGraphNode {
    int label;
    std::vector<UndirectedGraphNode *> neighbors;

    UndirectedGraphNode(int x) : label(x) {
    };
};

class Solution {
private:
    std::map<int, UndirectedGraphNode *> node_labels;
public:

    UndirectedGraphNode *cloneGraph(const UndirectedGraphNode *node) {
        if (node == nullptr) {
            return nullptr;
        }
        UndirectedGraphNode *copied_node = new UndirectedGraphNode(node->label);
        node_labels[node->label] = copied_node;
        for (const UndirectedGraphNode *n : node->neighbors) {
            const auto &iterator = node_labels.find(n->label);
            if (iterator == node_labels.end()) {
                UndirectedGraphNode * sub_graph = cloneGraph(n);
                copied_node->neighbors.push_back(sub_graph);
            } else {
                copied_node->neighbors.push_back(iterator->second);
            }

        }
        return copied_node;
    }
};

int main() {
    Solution solution;
    return 0;
}

