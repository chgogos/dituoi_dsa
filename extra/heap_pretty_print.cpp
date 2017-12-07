/**
 *  https://stackoverflow.com/questions/20922755/print-heap-array-in-tree-format
 *
 **/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>


std::string do_padding(unsigned index, unsigned mlength) {
  std::string padding;
  if (int((index - 1) / 2) != 0) {
    return (int((index - 1) / 2) % 2 == 0)
               ? (do_padding(int((index - 1) / 2), mlength) +
                  std::string(mlength + 4, ' ') + " ")
               : (do_padding(int((index - 1) / 2), mlength) +
                  std::string(mlength + 3, ' ') + " |");
  }
  return padding;
}

void printer(std::vector<int> const &tree, unsigned index, unsigned mlength) {
  auto last = tree.size() - 1;
  auto left = 2 * index + 1;
  auto right = 2 * index + 2;
  std::cout << " " << tree[index] << " ";
  if (left <= last) {
    auto llength = std::to_string(tree[left]).size();
    std::cout << "---" << std::string(mlength - llength, '-');
    printer(tree, left, mlength);
    if (right <= last) {
      auto rlength = std::to_string(tree[right]).size();
      std::cout << "\n"
                << do_padding(right, mlength) << std::string(mlength + 3, ' ')
                << " | ";
      std::cout << "\n"
                << do_padding(right, mlength) << std::string(mlength + 3, ' ')
                << " -" << std::string(mlength - rlength, '-');
      printer(tree, right, mlength);
    }
  }
}

void print_tree(std::vector<int> &tree) {
  unsigned mlength = 0;
  for (int &element : tree) {
    auto clength = std::to_string(element).size();
    if (clength > mlength) {
      mlength = std::to_string(element).size();
    }
  }
  std::cout << std::string(mlength - std::to_string(tree[0]).size(), ' ');
  printer(tree, 0, mlength);
}

int main() {
  std::vector<int> test;
  for (auto i = 0; i < 50; ++i) {
    test.push_back(rand() % 1000 + 1);
  }
  std::make_heap(test.begin(), test.end());
  std::cout << "\n";
  print_tree(test);
}