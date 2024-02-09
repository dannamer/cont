#include <iostream>
#include <string>
#include <vector>
struct node {
  int id;
  int parent;
  std::string text;
}


int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::vector<node> data;
    std::vector<node> root;
    for (int i = 0; i < n; ++i) {
      node a;
      std::cin >> a.id >> a.parent;
      std::getline(std::cin, a.text);
      if (a.parent == -1) {
        root.push_back(a);
      } else {
        data.push_back(a);
      }
    }
  }
}