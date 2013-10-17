#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include <exception>

typedef double Data;

typedef enum nodecolor {red, black} nodecolor;

class minimumE:public std::exception
{
    const char *what()const throw(){return "error find M_element in empty tree\n";}
};

class RedBlackTree
{
    struct node
    {
        node *left;
        node *right;
        node *parent;
        nodecolor color;
        Data element;
    };
    node *root;
    node *Nil;
    int numberOfElements;
    void left_Rotate(node *x);
    void right_Rotate(node *x);
    void insertFixup(node *z);
    void del_RBtree(node *nd);
    RedBlackTree(const RedBlackTree& other);
    node *findElement(node *root, Data x);
    RedBlackTree& operator = (const RedBlackTree &t);
    void conji(node *p, RedBlackTree Y, RedBlackTree &Z);
    void differ(node *p, RedBlackTree Y, RedBlackTree &Z);
    void disji(node *p, RedBlackTree &Z);
public:
    RedBlackTree();
    RedBlackTree(Data x);
    ~RedBlackTree();
    void insertElement(Data d);
    bool isFinded(Data x);
    Data findMinimal();
    node *getRoot(){return root;}
    int getNumberOfElements(){return numberOfElements;}
    RedBlackTree conjunction(RedBlackTree X, RedBlackTree Y);
    RedBlackTree disjunction(RedBlackTree X, RedBlackTree Y);
    RedBlackTree difference(RedBlackTree X, RedBlackTree Y);
};

#endif // REDBLACKTREE_H
