
// erasing from set
#include <iostream>
#include <set>

int main()
{
    std::set<int> myset;
    std::set<int>::iterator it;

    // insert some values:
    for (int i = 1; i < 10; i++) myset.insert(i * 10);  // 10 20 30 40 50 60 70 80 90

    it = myset.begin();
    ++it;                                         // "it" points now to 20

    myset.erase(it);

    myset.erase(40);

    it = myset.find(60);
    myset.erase(it, myset.end());

    std::cout << "myset contains:";
    for (it = myset.begin(); it != myset.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';


    /*Virtual table :
    Include all the virtual function.
        Virtual1
        Virtual2
        Virtual3
        the size of parent class need to add 4byte.There is a potential pointer point to virtual table.
*/


    return 0;
}