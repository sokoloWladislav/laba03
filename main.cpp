#include <iostream>
#include "redblacktree.h"

using namespace std;

int main()
{
    RedBlackTree A,B(5);
    A.insertElement(3);
    A.insertElement(4);
    //A.insertElement(-5);
    A.insertElement(5);
    //A.insertElement(6);
    //cout << A.isFinded(8);
    return 0;
}
