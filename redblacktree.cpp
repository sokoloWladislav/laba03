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

void RedBlackTree::insertFixup(node *z)
{
    node *y=Nil;
    while(z->parent->color==red)
    {
        if(z->parent==z->parent->parent->left)
        {
            y=z->parent->parent->right;
            if(y->color==red)
            {
                y->color=black;
                z->parent->color=black;
                z->parent->parent->color=red;
                z=z->parent->parent;
            }
            else
            {
                if(z==z->parent->right)
                {
                    z=z->parent;
                    left_Rotate(z);
                }
                z->parent->color=black;
                z->parent->parent->color=red;
                right_Rotate(z->parent->parent);
            }
        }
        else
        {
            y=z->parent->parent->left;
            if(y->color==red)
            {
                y->color=black;
                z->parent->color=black;
                z->parent->parent->color=red;
                z=z->parent->parent;
            }
            else
            {
                if(z==z->parent->left)
                {
                    z=z->parent;
                    right_Rotate(z);
                }
                z->parent->color=black;
                z->parent->parent->color=red;
                left_Rotate(z->parent->parent);
            }
        }
    }
    root->color=black;
}

void RedBlackTree::insertElement(Data d)
{
    node *z=new node;
    z->element=d;
    node *y=Nil;
    node *x=root;
    while(x!=Nil)
    {
        y=x;
        if(z->element<x->element)
            x=x->left;
        else
            x=x->right;
    }
    z->parent=y;
    if(y==Nil)
        root=z;
    else if(z->element<y->element)
        z=y->left;
    else
        z=y->right;
    z->left=Nil;
    z->right=Nil;
    z->color=red;
    insertFixup(z);
}

RedBlackTree::node *RedBlackTree::findElement(node *root, Data x)
{
    node *temp=root;
    if(temp!=Nil)
    {
        if(temp->element<x)
            return findElement(root->left,x);
        if(temp->element>x)
            return findElement(root->right,x);
        if(temp->element==x)
            return temp;
    }
    else
        return Nil;
}

bool RedBlackTree::isFinded(Data x)
{
    if(findElement(root, x)==Nil)
        return false;
    else
        return true;
}
