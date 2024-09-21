#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "tree.hpp"
#include "complex.hpp"
#include <iostream>
#include <stdexcept>

// Node Tests
TEST_CASE("Node class operations") {
    Node<int> n(1, 3);

    SUBCASE("Node initialization") {
        CHECK(n.value == 1);
        CHECK(n.children.size() == 3);
    }

    SUBCASE("Node children") {
        Node<int>* child1 = new Node<int>(2, 3);
        Node<int>* child2 = new Node<int>(3, 3);
        n.children[0] = child1;
        n.children[1] = child2;

        CHECK(n.children[0]->value == 2);
        CHECK(n.children[1]->value == 3);
        CHECK(n.children[2] == nullptr);

        delete child1;
        delete child2;
    }
}

// Tree Tests
TEST_CASE("Tree<int> operations") {
    Tree<int> t(3);

    SUBCASE("Add and find nodes") {
        t.add_root(1);
        t.add_sub_node(1, 2);
        t.add_sub_node(1, 3);
        t.add_sub_node(2, 4);

        CHECK(t.getRoot() != nullptr);
        CHECK(t.find(t.getRoot(), 1) != nullptr);
        CHECK(t.find(t.getRoot(), 2) != nullptr);
        CHECK(t.find(t.getRoot(), 3) != nullptr);
        CHECK(t.find(t.getRoot(), 4) != nullptr);
        CHECK(t.find(t.getRoot(), 5) == nullptr);
    }
}

TEST_CASE("Tree<std::string> operations") {
    Tree<std::string> t(3);

    SUBCASE("Add and find nodes") {
        t.add_root("root");
        t.add_sub_node("root", "child1");
        t.add_sub_node("root", "child2");
        t.add_sub_node("child1", "child1.1");

        CHECK(t.getRoot() != nullptr);
        CHECK(t.find(t.getRoot(), "root") != nullptr);
        CHECK(t.find(t.getRoot(), "child1") != nullptr);
        CHECK(t.find(t.getRoot(), "child2") != nullptr);
        CHECK(t.find(t.getRoot(), "child1.1") != nullptr);
        CHECK(t.find(t.getRoot(), "child3") == nullptr);
    }
}

TEST_CASE("Tree<Complex> operations") {
    Tree<Complex> t(3);

    SUBCASE("Add and find nodes") {
        t.add_root(Complex(0, 0));
        t.add_sub_node(Complex(0, 0), Complex(1, 1));
        t.add_sub_node(Complex(0, 0), Complex(2, 2));
        t.add_sub_node(Complex(1, 1), Complex(3, 3));

        CHECK(t.getRoot() != nullptr);
        CHECK(t.find(t.getRoot(), Complex(0, 0)) != nullptr);
        CHECK(t.find(t.getRoot(), Complex(1, 1)) != nullptr);
        CHECK(t.find(t.getRoot(), Complex(2, 2)) != nullptr);
        CHECK(t.find(t.getRoot(), Complex(3, 3)) != nullptr);
        CHECK(t.find(t.getRoot(), Complex(4, 4)) == nullptr);
    }
}

// Iterator Tests
TEST_CASE("Iterator class operations") {
    Tree<int> t(3);
    t.add_root(1);
    t.add_sub_node(1, 2);
    t.add_sub_node(1, 3);
    t.add_sub_node(2, 4);

    SUBCASE("Pre-order traversal") {
        Iterator<int> it = t.begin_pre_order();
        std::vector<int> values;
        while (it != t.end_pre_order()) {
            values.push_back(*it);
            ++it;
        }
        CHECK(values == std::vector<int>({1, 2, 4, 3}));
    }

    SUBCASE("Post-order traversal") {
        Iterator<int> it = t.begin_post_order();
        std::vector<int> values;
        while (it != t.end_post_order()) {
            values.push_back(*it);
            ++it;
        }
        CHECK(values == std::vector<int>({4, 2, 3, 1}));
    }

    SUBCASE("In-order traversal") {
        Iterator<int> it = t.begin_in_order();
        std::vector<int> values;
        while (it != t.end_in_order()) {
            values.push_back(*it);
            ++it;
        }
        CHECK(values == std::vector<int>({4, 2, 1, 3}));
    }

    SUBCASE("BFS traversal") {
        Iterator<int> it = t.begin_bfs_scan();
        std::vector<int> values;
        while (it != t.end_bfs_scan()) {
            values.push_back(*it);
            ++it;
        }
        CHECK(values == std::vector<int>({1, 2, 3, 4}));
    }

    SUBCASE("DFS traversal") {
        Iterator<int> it = t.begin_dfs_scan();
        std::vector<int> values;
        while (it != t.end_dfs_scan()) {
            values.push_back(*it);
            ++it;
        }
        CHECK(values == std::vector<int>({1, 2, 4, 3}));
    }
}

// Complex Tests
TEST_CASE("Complex class operations") {
    Complex c1(1, 2);
    Complex c2(3, 4);
    Complex c3(1, 2);

    SUBCASE("Equality operator") {
        CHECK(c1 == c3);
        CHECK_FALSE(c1 == c2);
    }

    SUBCASE("Comparison operators") {
        CHECK(c2 > c1);
        CHECK(c1 < c2);
    }

    SUBCASE("String representation") {
        CHECK(c1.toString() == "(1, 2)");
        CHECK(c2.toString() == "(3, 4)");
    }

    SUBCASE("Output stream operator") {
        std::ostringstream oss;
        oss << c1;
        CHECK(oss.str() == "(1, 2)");
    }
}

// Tree<int> operations
TEST_CASE("Tree<int> operations") {
    Tree<int> t(3);

    SUBCASE("Adding root and sub-nodes") {
        t.add_root(1);
        t.add_sub_node(1, 2);
        t.add_sub_node(1, 3);
        t.add_sub_node(1, 4);
        
        Node<int>* root = t.getRoot();
        REQUIRE(root != nullptr);
        CHECK(root->value == 1);
        CHECK(root->children[0]->value == 2);
        CHECK(root->children[1]->value == 3);
        CHECK(root->children[2]->value == 4);
    }
}

// New test case to replace the duplicated one
TEST_CASE("Tree<int> structure validation") {
    Tree<int> t(3);

    t.add_root(1);
    t.add_sub_node(1, 2);
    t.add_sub_node(1, 3);
    t.add_sub_node(2, 4);
    t.add_sub_node(2, 5);

    SUBCASE("Root and children validation") {
        Node<int>* root = t.getRoot();
        REQUIRE(root != nullptr);
        CHECK(root->value == 1);
        CHECK(root->children.size() == 3);
        CHECK(root->children[0]->value == 2);
        CHECK(root->children[1]->value == 3);
        CHECK(root->children[0]->children[0]->value == 4);
        CHECK(root->children[0]->children[1]->value == 5);
    }
}

// Tree<Complex> operations
TEST_CASE("Tree<Complex> operations") {
    Tree<Complex> t(2);

    Complex c1(1.0, 1.0);
    Complex c2(2.0, 2.0);
    Complex c3(3.0, 3.0);

    t.add_root(c1);
    t.add_sub_node(c1, c2);
    t.add_sub_node(c1, c3);

    Node<Complex>* root = t.getRoot();
    REQUIRE(root != nullptr);
    CHECK(root->value == c1);
    CHECK(root->children[0]->value == c2);
    CHECK(root->children[1]->value == c3);
}

TEST_CASE("Tree<Complex> traversal") {
    Tree<Complex> t(2);

    Complex c1(1.0, 1.0);
    Complex c2(2.0, 2.0);
    Complex c3(3.0, 3.0);
    Complex c4(4.0, 4.0);

    t.add_root(c1);
    t.add_sub_node(c1, c2);
    t.add_sub_node(c1, c3);
    t.add_sub_node(c2, c4);

    SUBCASE("Complex number traversal") {
        Iterator<Complex> it = t.begin_bfs_scan();
        std::vector<Complex> values;
        while (it != t.end_bfs_scan()) {
            values.push_back(*it);
            ++it;
        }
        std::cout << "BFS values: ";
        for (const Complex& v : values) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
        CHECK(values == std::vector<Complex>({c1, c2, c3, c4}));
    }
}

TEST_CASE("Tree<int> traversal operations") {
    Tree<int> t(3);

    t.add_root(1);
    t.add_sub_node(1, 2);
    t.add_sub_node(1, 3);
    t.add_sub_node(2, 4);
    t.add_sub_node(2, 5);
    t.add_sub_node(3, 6);
    t.add_sub_node(3, 7);

    SUBCASE("Pre-order traversal") {
        std::vector<int> values;
        for (auto it = t.begin_pre_order(); it != t.end_pre_order(); ++it) {
            values.push_back(*it);
        }
        CHECK(values == std::vector<int>({1, 2, 4, 5, 3, 6, 7}));
    }

    SUBCASE("Post-order traversal") {
        std::vector<int> values;
        for (auto it = t.begin_post_order(); it != t.end_post_order(); ++it) {
            values.push_back(*it);
        }
        CHECK(values == std::vector<int>({4, 5, 2, 6, 7, 3, 1}));
    }
}

TEST_CASE("Tree<int> edge cases") {
    Tree<int> t(2);

    SUBCASE("Single element tree") {
        t.add_root(1);
        CHECK_NOTHROW(t.begin_pre_order());
        CHECK(*t.begin_pre_order() == 1);
    }

    SUBCASE("Tree with only root and maximum children") {
        t.add_root(1);
        t.add_sub_node(1, 2);
        t.add_sub_node(1, 3);
        CHECK_NOTHROW(t.begin_pre_order());
        std::vector<int> values;
        for (auto it = t.begin_pre_order(); it != t.end_pre_order(); ++it) {
            values.push_back(*it);
        }
        CHECK(values == std::vector<int>({1, 2, 3}));
    }
}

TEST_CASE("Tree<int> find node functionality") {
    Tree<int> t(2);

    t.add_root(1);
    t.add_sub_node(1, 2);
    t.add_sub_node(1, 3);
    t.add_sub_node(2, 4);
    t.add_sub_node(2, 5);

    SUBCASE("Find existing node") {
        Node<int>* found = t.find(t.getRoot(), 4);
        CHECK(found != nullptr);
        CHECK(found->value == 4);
    }

    SUBCASE("Find non-existing node") {
        Node<int>* found = t.find(t.getRoot(), 99);
        CHECK(found == nullptr);
    }
}
