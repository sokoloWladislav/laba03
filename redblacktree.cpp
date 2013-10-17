#include "redblacktree.h"

RedBlackTree::RedBlackTree()
{
    Nil=new node;
    Nil->color=black;
    Nil->left=0;
    Nil->right=0;
    Nil->parent=0;
    Nil->element=0;
    root=Nil;
    numberOfElements=0;
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
    numberOfElements=1;
}

RedBlackTree::~RedBlackTree()
{
    del_RBtree(root);
    Nil=0;
    numberOfElements=0;
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
    if(x->right!=Nil)
    {
        node *y=x->right;
        x->right=y->left;
        if(y->left!=Nil)
            y->left->parent=x;
        y->parent=x->parent;
        if(x->parent==Nil)
            root=y;
        else
        {
            if(x==x->parent->left)
                x->parent->left=y;
            else
                x->parent->right=y;
        }
        y->left=x;
        if(x!=Nil)
            x->parent=y;
        y=0;
    }
}

void RedBlackTree::right_Rotate(node *x)
{
    if(x->left!=Nil)
    {
        node *y=x->left;
        x->left=y->right;
        if(y->right!=Nil)
            y->right->parent=x;
        if(y!=Nil)
            y->parent=x->parent;
        if(x->parent==Nil)
            root=y;
        else
        {
            if(x==x->parent->left)
                x->parent->left=y;
            else
                x->parent->right=y;
        }
        y->right=x;
        if(x!=Nil)
            x->parent=y;
        y=0;
    }
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
    y=0;
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
        if(z->element>x->element)
            x=x->right;
        if(z->element==x->element)
            delete z;
    }
    if(z->element!=x->element)
    {
        z->parent=y;
        if(y==Nil)
            root=z;
        else
        {
            if(z->element<y->element)
                y->left=z;
            else
                y->right=z;
        }
        z->left=Nil;
        z->right=Nil;
        z->color=red;
        y=0;
        x=0;
        insertFixup(z);
        z=0;
        ++numberOfElements;
    }
}

RedBlackTree::node *RedBlackTree::findElement(node *t, Data x)
{
    if(t==Nil) return Nil;
    if(x<t->element) return findElement(t->left,x);
    if(x>t->element) return findElement(t->right,x);
    return t;
}

bool RedBlackTree::isFinded(Data x)
{
    if(findElement(root, x)==Nil)
        return false;
    else
        return true;
}

Data RedBlackTree::findMinimal()
{
    node *y=root;
    if(y==Nil)
        throw minimumE();
    else
    {
        while(y->left!=Nil)
            y=y->left;
        return y->element;
    }
}

void RedBlackTree::conji(node *p, RedBlackTree Y, RedBlackTree &Z)
{
    if(p!=Nil)
    {
        conji(p->left, Y, Z);
        if(Y.isFinded(p->element))
            Z.insertElement(p->element);
        conji(p->right, Y, Z);
    }
}

void RedBlackTree::differ(node *p, RedBlackTree Y, RedBlackTree &Z)
{
    if(p!=Nil)
    {
        differ(p->left, Y, Z);
        if(!Y.isFinded(p->element))
            Z.insertElement(p->element);
        differ(p->right, Y, Z);
    }
}

void RedBlackTree::disji(node *p, RedBlackTree &Z)
{
    disji(p->left, Z);
    Z.insertElement(p->element);
    disji(p->right, Z);
}

RedBlackTree RedBlackTree::conjunction(RedBlackTree X, RedBlackTree Y)
{
    RedBlackTree Z;
    X.conji(root, Y, Z);
    return Z;
}

RedBlackTree RedBlackTree::difference(RedBlackTree X, RedBlackTree Y)
{
    RedBlackTree Z;
    X.differ(root, Y, Z);
    return Z;
}

RedBlackTree RedBlackTree::disjunction(RedBlackTree X, RedBlackTree Y)
{
    RedBlackTree Z;
    X.disji(root, Z);
    Y.disji(root, Z);
    return Z;
}
