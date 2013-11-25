#include <iostream>
#include "redblacktree.h"
#include <exception>

using namespace std;

int main()
{
    try
    {
    RedBlackTree A(6), B(3), C;
    A.insertElement(3);
    A.insertElement(8);
    A.insertElement(2);
    B.insertElement(1);
    //B.insertElement(-1);
    B.insertElement(-2);
    B.insertElement(1);
    A.insertElement(-10);
    cout << endl;
    //cout << A.getNumberOfElements();
    C=A-B;
    //C=A.disjunction(B);
    C.output();
    }

    catch (exception &e)
    {
        cerr<<e.what();
    }
    return 0;
}
