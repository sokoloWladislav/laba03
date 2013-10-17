#include <iostream>
#include "redblacktree.h"
#include <exception>

using namespace std;

int main()
{
    try
    {
    RedBlackTree A, B ,C;
    A.insertElement(3);
    A.insertElement(5);
    A.insertElement(-5);
    A.insertElement(1);
    A.insertElement(6);
    B.insertElement(-5);
    B.insertElement(1);
    cout << A.isFinded(6) << endl;
    cout << A.getNumberOfElements() << endl;
    cout << C.getNumberOfElements() << endl;
    }

    catch (exception &e)
    {
        cerr<<e.what();
    }
    return 0;
}
