#include <iostream>
#include "binary_search_tree.h"

int main() {
   BST<std::string,int> tree;
    tree.insert_or_assign("A", 10);
    tree.insert_or_assign("C", 10);
    tree.insert_or_assign("D", 10);
    tree.insert_or_assign("F", 10);
    tree.insert_or_assign("E", 10);
    tree.insert_or_assign("B", 10);
    tree.in_order([] (const auto& item){ std::cout << item.first << " "; });
    std::cout << std::endl;
    tree.erase("D");
    tree.in_order([] (const auto& item){ std::cout << item.first << " "; });
    std::cout << std::endl;
    return 0;
}