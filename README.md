# 0x1D. C - Binary trees

+ By: Alexandre Gautier
+ Weight: 5

```
There should be one project repository per group. If you clone/fork/whatever a project repository with the same name before the second deadline, you risk a 0% score.

```


### Resources
* Binary tree
* Data Structure and Algorithms - Tree
* Tree Traversal
* Binary Search Tree


### Requirements
***General***
+ Allowed editors: vi, vim, emacs
+ All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
+ Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
+ No more than 5 functions per file


## Data structures
#### Basic Binary Tree
```
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
```

#### Binary Search Tree
```
typedef struct binary_tree_s bst_t;
```

#### AVL Tree
```
typedef struct binary_tree_s avl_t;
```

#### Max Binary Heap
```
typedef struct binary_tree_s heap_t;
```



