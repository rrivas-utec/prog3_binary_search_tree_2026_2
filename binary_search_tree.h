//
// Created by rrivas on 5/11/2026.
//

#ifndef PROG3_BINARY_SEARCH_TREE_2026_2_BINARY_SEARCH_TREE_H
#define PROG3_BINARY_SEARCH_TREE_2026_2_BINARY_SEARCH_TREE_H
#include <functional>
#include <memory>

template <
    class KeyType,
    class ValueType,
    class Compare = std::less<KeyType>
    >
class BST {
public:
    void insert_or_assign(const KeyType &key, const ValueType &value) {}
    void erase(const KeyType &key) {}
    ValueType find(const KeyType &key) const { return ValueType{}; }

    template <class Callable>
    void pre_order(Callable func) const {}

    template <class Callable>
    void in_order(Callable func) const {}

    template <class Callable>
    void post_order(Callable func) const {}

private:
    struct node_t {
        std::pair<KeyType, ValueType> item;
        std::unique_ptr<node_t> left;
        std::unique_ptr<node_t> right;
    };

    std::unique_ptr<node_t> root_;
    Compare comp;

    std::unique_ptr<node_t> find_link(const KeyType &key) {
        
    }

};
#endif //PROG3_BINARY_SEARCH_TREE_2026_2_BINARY_SEARCH_TREE_H
