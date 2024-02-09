#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

struct Comment {
    int id;
    std::string text;
};

void printComments(const std::map<int, std::vector<Comment>>& tree, int nodeId, const std::string& prefix) {
    if (tree.find(nodeId) != tree.end()) {
        for (size_t i = 0; i < tree.at(nodeId).size(); ++i) {
            const auto& comment = tree.at(nodeId)[i];
            std::cout << prefix << (i == tree.at(nodeId).size() - 1 ? "`--" : "|--") << comment.text << std::endl;
            printComments(tree, comment.id, prefix + (i == tree.at(nodeId).size() - 1 ? "   " : "|  "));
        }
    }
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::map<int, std::vector<Comment>> tree;
        std::vector<int> roots;

        for (int i = 0; i < n; ++i) {
            int id, parent;
            std::string text;
            std::cin >> id >> parent;
            std::getline(std::cin, text);
            if (parent == -1) {
                roots.push_back(id);
            } else {
                tree[parent].push_back({id, text});
            }
        }

        // Сортировка детей каждого узла по идентификатору
        for (auto& [key, children] : tree) {
            std::sort(children.begin(), children.end(), [](const Comment& a, const Comment& b) {
                return a.id < b.id;
            });
        }

        // Вывод деревьев комментариев
        for (int root : roots) {
            printComments(tree, root, "");
            if (root != roots.back()) {
                std::cout << std::endl;
            }
        }

        if (t > 0) {
            std::cout << std::endl;
        }
    }
    return 0;
}