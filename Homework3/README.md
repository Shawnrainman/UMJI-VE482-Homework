# VE482 hw3 Ex.2

This is the README file of VE482 homework3 **Ex.2**.

There are three files for **Ex.2** in total:

- `list.h`
- `list.c`
- `main.c`

## `list.h`

This is the file that defines data structure including:

- `_node`: struct that store a `char` and a `void` pointer as key-value pair, and a `_node` pointer that point to the next node in the linked list
- `_list`: struct that store a pointer of type `_node ` as the head node of the linked list, and `len` the length of the linked list
- `_type`: struct that store two int variables `dataType` and `sortType` that indicating the type of input data and the required sort method, the classification of data type and sort method is defined through macro

Functions are defined to support different functionality.

- `listConstructor`: function that initializes and returns the pointer to an empty linked list
- `listDestructor`: function that frees all the allocated memory
- `addNode`: function that adds new node to the linked list, will first fill in the head node if the head node is empty
- `searchList`: function that searches the whole list to find the value that can match the input key, returns NULL if the list is empty or no key can match
- `sort`: function that decides which comparator function should be used given a pointer of `_type`
- `sortList`: function that makes use of the function pointer (comparator) to sort the linked list
- `outputList`: fuction that outputs the sorted linke list to certain file according to the given pointer of `_type`

## `list.c`

This file contains the implementation of functions declared in `list.h`, as well as comparator corresponding to different data type and sorting type.

## `main.c`

This file contains the functions that handle the input arguments and make use of the functions mentioned above.

- `main`: main function that takes the input arguments and calling corresponding funtions to handle
- `getType`: function that takes the input arguments and figures out the input data type and sorting type for later usage
- `sortFile`: function that reads in data from given file to create linked list, calls functions to sort the list, and calls function s to output the sorted list into corresponding file
