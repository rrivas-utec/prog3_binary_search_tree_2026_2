//
// Created by rrivas on 5/11/2026.
//

#ifndef PROG3_BINARY_SEARCH_TREE_2026_2_BINARY_SEARCH_TREE_H
#define PROG3_BINARY_SEARCH_TREE_2026_2_BINARY_SEARCH_TREE_H
#include <functional>
#include <memory>
#include <stack>

template <
    class KeyType,
    class ValueType,
    class Compare = std::less<KeyType>
    >
class BST {
public:
    void insert_or_assign(const KeyType &key, const ValueType &value) {
        auto& link = find_link(key);
        if (!link) {
            link = std::make_unique<node_t>(node_t{{key, value}});
        }
        else {
            link->item.second = value;
        }
    }

    void erase(const KeyType &key) {
        auto& target_link = find_link(key);

        // No lo encuentro, no lo borro y termino
        if (!target_link) { return; }

        // CASO # 1: no tiene hijos
        if (!target_link->left && !target_link->right) {
            target_link.reset();
            return;
        }
        // CASO # 2: tiene un hijo
        else if (!target_link->left || !target_link->right) {
            auto& child_link = !target_link->left
                        ? target_link->right
                        : target_link->left;
            auto replacement_link = std::move(child_link);
            target_link = std::move(replacement_link);
            return;
        }
        // CASO # 3: tiene los 2 hijos
        auto& leftmost_link = find_leftmost_link(target_link->right);

        auto successor_link = std::move(leftmost_link);
        leftmost_link = std::move(successor_link->right);

        successor_link->left = std::move(target_link->left);
        successor_link->right = std::move(target_link->right);
        target_link = std::move(successor_link);
    }


    ValueType find(const KeyType &key) const { return ValueType{}; }

    template <class Callable>
    void pre_order(Callable func) const {}

    template <class Callable>
    void in_order(Callable func) const {
        node_t* curr = root_.get();
        std::stack<node_t*> pending;
        while (curr || !pending.empty()) {
            while (curr) {
                pending.push(curr);
                curr = curr->left.get();
            }
            curr = pending.top();
            pending.pop();
            std::invoke(func, curr->item);
            curr = curr->right.get();
        }

    }

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

    std::unique_ptr<node_t>& find_link(const KeyType &key) {
        auto link_ptr = &root_;
        while (*link_ptr) {
            if (comp(key, (*link_ptr)->item.first)) {
                link_ptr = &(*link_ptr)->left;
            }
            else if(comp((*link_ptr)->item.first, key)) {
                link_ptr = &(*link_ptr)->right;
            }
            else {
                break;
            }
        }
        return *link_ptr;
    }

    std::unique_ptr<node_t>& find_leftmost_link(std::unique_ptr<node_t>& subtree) {
        auto link_ptr = &subtree;
        while (*link_ptr && (*link_ptr)->left) {
            link_ptr = &(*link_ptr)->left;
        }
        return *link_ptr;
    }

};
#endif //PROG3_BINARY_SEARCH_TREE_2026_2_BINARY_SEARCH_TREE_H
