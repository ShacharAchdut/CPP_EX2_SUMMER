#include <iostream>
#include "tree.hpp"
#include "complex.hpp"
#include "tree_gui.hpp"

int main() {


    Tree<Complex> c;

    c.add_root(Complex(1, 2));
    c.add_sub_node(Complex(1, 2), Complex(3, 4));
    c.add_sub_node(Complex(1, 2), Complex(5, 6));
    c.add_sub_node(Complex(3, 4), Complex(7, 8));

    std::cout << "Pre-Order Traversal: ";
    for (auto it = c.begin_pre_order(); it != c.end_pre_order(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Post-Order Traversal: ";
    for (auto it = c.begin_post_order(); it != c.end_post_order(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "In-Order Traversal: ";
    for (auto it = c.begin_in_order(); it != c.end_in_order(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "BFS Traversal: ";
    for (auto it = c.begin_bfs_scan(); it != c.end_bfs_scan(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "DFS Traversal: ";
    for (auto it = c.begin_dfs_scan(); it != c.end_dfs_scan(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    
    //
    TreeGUI<Complex> complexGui(c);
    complexGui.run();



/* 
     DISABLE THE TREE BEFORE WITH // COMMENTS
     AND 
     FREE THE // COMMENTS TO ENABLE THIS TREE 
    */

    // Tree<std::string> k(3);

    // k.add_root("Root");
    // k.add_sub_node("Root", "Child1");
    // k.add_sub_node("Root", "Child2");
    // k.add_sub_node("Root", "Child3");
    // k.add_sub_node("Child1", "Grandchild1");
    // k.add_sub_node("Child1", "Grandchild2");

    // TreeGUI<std::string> strGui(k);
    // strGui.run();


/* 
     DISABLE THE TREE BEFORE WITH // COMMENTS
     AND 
     FREE THE // COMMENTS TO ENABLE THIS TREE 
    */


    // Tree<std::string> t(3);  // Set k to 3 to allow up to 3 children per node

    // // Adding root and its direct children
    // t.add_root("root");

    // t.add_sub_node("root", "child1");
    // t.add_sub_node("root", "child2");
    // t.add_sub_node("root", "child3");

    // // Adding grandchildren
    // t.add_sub_node("child1", "child1_1");
    // t.add_sub_node("child1", "child1_2");
    // t.add_sub_node("child1", "child1_3");

    // t.add_sub_node("child2", "child2_1");
    // t.add_sub_node("child2", "child2_2");
    // t.add_sub_node("child2", "child2_3");

    // t.add_sub_node("child3", "child3_1");
    // t.add_sub_node("child3", "child3_2");
    // t.add_sub_node("child3", "child3_3");

    // // Adding great-grandchildren
    // t.add_sub_node("child1_1", "child1_1_1");
    // t.add_sub_node("child1_1", "child1_1_2");

    // t.add_sub_node("child1_2", "child1_2_1");
    // t.add_sub_node("child1_2", "child1_2_2");

    // t.add_sub_node("child1_3", "child1_3_1");
    // t.add_sub_node("child1_3", "child1_3_2");

    // t.add_sub_node("child2_1", "child2_1_1");
    // t.add_sub_node("child2_1", "child2_1_2");

    // t.add_sub_node("child2_2", "child2_2_1");
    // t.add_sub_node("child2_2", "child2_2_2");

    // t.add_sub_node("child2_3", "child2_3_1");
    // t.add_sub_node("child2_3", "child2_3_2");

    // t.add_sub_node("child3_1", "child3_1_1");
    // t.add_sub_node("child3_1", "child3_1_2");

    // t.add_sub_node("child3_2", "child3_2_1");
    // t.add_sub_node("child3_2", "child3_2_2");

    // t.add_sub_node("child3_3", "child3_3_1");
    // t.add_sub_node("child3_3", "child3_3_2");

    // TreeGUI<std::string> stringGui(t);
    // stringGui.run();

    return 0;
}

