


#include <iostream>

using namespace std;

int sumRecursion(int input);
int main()
{
    int input = 5;
    int myReturn = sumRecursion(input);
    return 0;

}


int sumRecursion(int input )
{
   
    if (input == 1)
    {
        return (1);
    }
    else
    {
        return sumRecursion(input - 1) + input;
    }    
 
}


