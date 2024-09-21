#ifndef NODE_HPP
#define NODE_HPP

#include <vector>

template<typename T>
class Node {
public:
    T value; // Value stored in the node
    std::vector<Node<T>*> children; // Children nodes

    Node(const T& val, int k) : value(val) {
        children.resize(k, nullptr); // Resize children vector to accommodate k children
    }
};

#endif // NODE_HPP
