# Singly Linked List in C++

A clean and fully functional **singly linked list** implementation in
C++, designed for educational purposes and data structure practice.\
This project demonstrates pointer manipulation, dynamic memory
management, and common linked list operations implemented manually
without the STL.

------------------------------------------------------------------------

##  Overview

This project contains a custom `LinkedList` class built around a simple
`node` structure:

``` cpp
struct node {
    int data;
    node* next;
};
```

The project includes a menu‑driven console application that allows users
to interact with the linked list in real time.

------------------------------------------------------------------------

##  Features

### Core Operations

-   **Add First** -- Insert a node at the head of the list\
-   **Add Last** -- Insert a node at the tail\
-   **Remove First** -- Delete the head node\
-   **Remove Last** -- Delete the tail node\
-   **Delete by Value** -- Remove the first node containing a specific
    value\
-   **Search** -- Check if a value exists in the list\
-   **Count Nodes** -- Count and return number of existing nodes\
-   **Display List** -- Print list elements in order

### Internal Utilities

-   Manual dynamic memory allocation (`new` / `delete`)
-   Helper methods for node creation and deletion
-   Safe checks for edge cases (empty list, missing values,
    single‑element list)

------------------------------------------------------------------------

##  Menu‑Driven Interface

The program includes a simple console-based interface allowing users to
test all operations:

    --- Linked List Menu ---
    1. Add First
    2. Add Last
    3. Remove First
    4. Remove Last
    5. Delete by Value
    6. Display
    7. Count Nodes
    8. Search Value
    0. Exit

------------------------------------------------------------------------



##  License

This project is free to use, modify, and distribute for learning and
academic purposes.

------------------------------------------------------------------------

##  Contributions

Feel free to submit issues or pull requests if you'd like to improve or
optimize the implementation.
