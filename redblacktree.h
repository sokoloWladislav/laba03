#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include <exception>


typedef int Data;

typedef enum nodecolor {red, black} nodecolor;

class minimumE:public std::exception
{
    const char *what()const throw()
    {
        return "error finding M_element in empty tree\n";
    }
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
    void insertElement(node *&nd, Data d);
    void del_RBtree(node *nd);
    void copy_RBtree(node *&newn,node *old, node *newNil, node *oldNil);
    node *findElement(node *root, Data x);
    void conjunction(node *p, RedBlackTree &x);
    void difference(node *p, RedBlackTree &z, RedBlackTree x);
    void disjunction(node *p, RedBlackTree &z, RedBlackTree x);
    void output(node *nd);
public:
    void output();
    RedBlackTree();
    RedBlackTree(Data x);
    RedBlackTree(const RedBlackTree& other);
    RedBlackTree& operator = (const RedBlackTree &t);
    ~RedBlackTree();
    RedBlackTree operator + (RedBlackTree &x);
    RedBlackTree operator - (RedBlackTree &x);
    void insertElement(Data d);
    bool isFinded(Data x);
    Data findMinimal();
    RedBlackTree disjunction(RedBlackTree x);
    int getNumberOfElements()
    {
        return numberOfElements;
    }
};

#endif // REDBLACKTREE_H
