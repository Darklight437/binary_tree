#include "BinaryTree.h"
#include <iostream>

int main()
{
    BinaryTree fhtagn;


    fhtagn.insert(20);

    fhtagn.insert(5);

    fhtagn.remove(20);

    fhtagn.remove(5);






    if (fhtagn.isEmpty())
    {
        std::cout << "list working as intended \n\n";
        system("pause");
    }


    return 0;

}

