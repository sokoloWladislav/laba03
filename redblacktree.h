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
    void insertFixup(node *x);
    void del_RBtree(node *nd);
public:
    RedBlackTree();
    RedBlackTree(Data x);
    ~RedBlackTree();
    RedBlackTree(const RedBlackTree& other);
    node *getRoot()
    {
        return root;
    }
};

#endif // REDBLACKTREE_H
