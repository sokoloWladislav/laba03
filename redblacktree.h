#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

typedef double Data;

typedef enum nodecolor {red, black} nodecolor;



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
    void left_Rotate(node *x);
    void right_Rotate(node *x);
    void insertFixup(node *z);
    void del_RBtree(node *nd);
    RedBlackTree(const RedBlackTree& other);
    node *findElement(node *root, Data x);
public:
    RedBlackTree();
    RedBlackTree(Data x);
    ~RedBlackTree();
    void insertElement(Data d);
    bool isFinded(Data x);
    node *getRoot()
    {
        return root;
    }
};

#endif // REDBLACKTREE_H
