#include "redblacktree.h"

RedBlackTree::RedBlackTree()
{
    Nil=new node;
    Nil->color=black;
    Nil->left=Nil;
    Nil->right=Nil;
    Nil->parent=0;
    Nil->element=0;
    root=Nil;
}

RedBlackTree::RedBlackTree(Data x)
{
    Nil=new node;
    root=new node;
    Nil->color=black;
    Nil->left=0;
    Nil->right=0;
    Nil->parent=0;
    root->left=Nil;
    root->right=Nil;
    root->parent=Nil;
    root->color=black;
    root->element=x;
}

RedBlackTree::~RedBlackTree()
{
    del_RBtree(root);
    Nil=0;
}

void RedBlackTree::del_RBtree(node *nd)
{
    if(Nil==nd)return;
    del_RBtree(nd->left);
    del_RBtree(nd->right);
    delete nd;
    nd=0;
}

RedBlackTree::RedBlackTree(const RedBlackTree& other)
{
    //copy ctor
}

void RedBlackTree::left_Rotate(node *x)
{
    node *y=x->right;
    x->right=y->left;
    if(y->left!=Nil)
        y->left->parent=x;
    if(y!=Nil)
        y->parent=x->parent;
    if(x->parent==Nil)
        y=root;
    else if(x==x->parent->left)
        x->parent->left=y;
    else
        x->parent->right=y;
    y->left=x;
    if(x!=Nil)
        x->parent=y;
}

void RedBlackTree::right_Rotate(node *x)
{
    node *y=x->left;
    x->left=y->right;
    if(y->right!=Nil)
        y->right->parent=x;
    if(y!=Nil)
        y->parent=x->parent;
    if(x->parent==Nil)
        y=root;
    else if(x==x->parent->left)
        x->parent->left=y;
    else
        x->parent->right=y;
    y->right=x;
    if(x!=Nil)
        x->parent=y;
}

void RedBlackTree::insertFixup(node *x)
{
    while(x->parent->color==red)

}
