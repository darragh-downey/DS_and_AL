#ifndef BST_H
#define BST_H

#include <iostream>

typedef struct tree {
    int _data;              /** data item **/
    struct tree *parent;    /** pointer to parent **/
    struct tree *left;      /** left subtree **/
    struct tree *right;     /** right subtree **/
} tree;

class BST
{
public:
    BST(int data);
    ~BST();
    void insert(int data);
    bool contains(int data);
    void remove(int data);

    void printValue();
    void printInOrder();   // left, root, right
    void printPreOrder();  // root, left, right
    void printPostOrder(); // left, right, root

    static BST *search_tree(BST *l, int x);
    static BST *find_minimum(BST *l);
    static BST *find_maximum(BST *l);

private:
    BST *_left;
    BST *_right;
    int _data;
};

#endif // BST_H
