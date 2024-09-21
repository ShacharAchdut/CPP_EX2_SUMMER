# Generic Tree with GUI Representation

## Overview

This project implements a generic tree data structure with a graphical user interface (GUI) representation. The tree can hold nodes of any data type, including primitive types like `int` and `std::string`, as well as user-defined classes like `Complex`. The GUI is implemented using SDL2, which allows for a visual representation of the tree structure.

## Features

- **Generic Tree Structure**: Supports nodes with any data type using C++ templates.
- **GUI Visualization**: Provides a graphical representation of the tree using SDL2.
- **Template Specialization**: Converts various data types to string representations for display purposes.
- **Flexible Node Capacity**: Configurable maximum number of children per node.

## File Structure

- `main.cpp`: Contains the main function, demonstrating the usage of the tree.
- `tree.hpp` & `tree.cpp`: Defines the generic tree and its operations.
- `node.hpp` & `node.cpp`: Defines the node structure used in the tree.
- `iterator.hpp` & `iterator.cpp`: Implements tree traversal iterators.
- `tree_gui.hpp` & `tree_gui.cpp`: Implements the GUI for tree visualization using SDL2.
- `complex.hpp`: Defines the `Complex` class.

## Compilation and Execution

### Prerequisites

Ensure you have SDL2 installed on your system. 

### Compilation

Use the make commands to compile the project:

```sh
make
```

### Running

Execute the compiled program to see the tree in action:

```sh
./tree
```

## Example Usage

### Main Function

The `main` function in `main.cpp` demonstrates how to use the tree with `int`, `std::string`, and `Complex` data types.

#### Example with `int`:

```cpp
#include "tree.hpp"
#include "tree_gui.hpp"

int main() {
    Tree<int> t(1);
    t.add_sub_node(1, 2);
    t.add_sub_node(1, 3);
    t.add_sub_node(1, 4);
    t.add_sub_node(2, 5);
    t.add_sub_node(2, 6);
    t.add_sub_node(3, 7);
    t.add_sub_node(4, 8);

    TreeGUI<int> intGui(t);
    intGui.run();

    return 0;
}
```

#### Example with `std::string`:

```cpp
#include "tree.hpp"
#include "tree_gui.hpp"

int main() {
    Tree<std::string> t("root");
    t.add_sub_node("root", "child1");
    t.add_sub_node("root", "child2");
    t.add_sub_node("child1", "child1.1");
    t.add_sub_node("child1", "child1.2");

    TreeGUI<std::string> stringGui(t);
    stringGui.run();

    return 0;
}
```

#### Example with `Complex`:

```cpp
#include "tree.hpp"
#include "tree_gui.hpp"
#include "complex.hpp"

int main() {
    Tree<Complex> t(Complex(0, 0));
    t.add_sub_node(Complex(0, 0), Complex(1, 1));
    t.add_sub_node(Complex(0, 0), Complex(2, 2));
    t.add_sub_node(Complex(1, 1), Complex(3, 3));
    t.add_sub_node(Complex(1, 1), Complex(4, 4));

     TreeGUI<Complex> complexGui(t);
    complexGui.run();

    return 0;
}
```

## Code Explanation

### Tree Data Structure

The `Tree` class is a generic tree that supports nodes with any data type. Here's a brief overview of its components:

- **Template Class**: `template <typename T>` allows the tree to hold any data type.
- **Nodes**: Each node can have multiple children, controlled by a configurable parameter `k`.
- **Add Sub Node**: Adds a child node to a specified parent node.
- **Traversal**: Supports various traversal methods using iterators.

### Template Specialization

Template specialization is used to provide string representations for different data types. This is necessary for displaying the nodes in the GUI. Here’s how it’s done for `std::string` and `Complex`:

```cpp
template <>
std::string TreeGUI<std::string>::toString(const std::string& value) {
    return value;
}

template <>
std::string TreeGUI<Complex>::toString(const Complex& value) {
    return value.toString();
}
```

### GUI Representation

The `TreeGUI` class uses SDL2 to visualize the tree. It handles:

- **Initialization**: Sets up SDL2 and creates a window.
- **Rendering**: Draws the tree structure and node values on the screen.
- **Event Handling**: Manages user inputs and window events.

### Complex Class

The `Complex` class represents complex numbers and includes methods for:

- **Construction**: Creating complex numbers with real and imaginary parts.
- **String Representation**: Converting the complex number to a string for display.
- **Comparison Operators**: Comparing two complex numbers based on their magnitude.

## Conclusion

This project demonstrates the use of templates in C++ to create a flexible and reusable data structure. The GUI component shows how to visualize complex data structures using SDL2. The combination of these techniques provides a robust foundation for further extensions and customizations.

---