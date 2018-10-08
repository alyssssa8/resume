


#include <iostream>

using namespace std;

int fibonacci(int input);
int main()
{
    int input = 7;
    int myReturn = fibonacci(input);
    return 0;

}


int fibonacci(int input)
{

    if (input == 2|| input == 1)
    {
        return (1);
    }
    else
    {
        return fibonacci(input - 1) + fibonacci(input - 2);

    }

}


