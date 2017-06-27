#include "BinaryTree.h"
#include <iostream>

int main()
{
    bool testPassed = false;
    BinaryTree fhtagn;


    fhtagn.insert(20);

    fhtagn.insert(5);

    if (!fhtagn.isEmpty())
    {
        std::cout << "insert function working as intended\n\n";
        
    }

    fhtagn.remove(20);

    fhtagn.remove(5);






    if (fhtagn.isEmpty())
    {
        std::cout << "remove working as intended \n\n";
        testPassed = true;
    }



    if (testPassed)
    {
        std::cout << "all tests passed successfully\n\n";
        system("pause");
    }

    return 0;

}

