#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "node.hpp"
#include <stack>
#include <queue>
#include <vector>

template<typename T>
class Iterator {
public:
    enum Order { PRE_ORDER, POST_ORDER, IN_ORDER, BFS, DFS };

    Iterator(Node<T>* root, Order order);

    T& operator*();
    Iterator& operator++();
    bool operator!=(const Iterator& other) const;

private:
    Node<T>* current;
    Order order;
    std::stack<Node<T>*> s;
    std::queue<Node<T>*> q;
    std::vector<Node<T>*> nodeList;
    std::size_t index;

    void initialize(Node<T>* root);
    void advance();
    void postOrderTraversal(Node<T>* node);
    void inOrderTraversal(Node<T>* node);
};

#endif // ITERATOR_HPP
