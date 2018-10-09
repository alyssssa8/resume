


#include <iostream>

using namespace std;

int GCD(int input1, int input2);
int main()
{
    int input1 = 25;
    int input2 = 10;
    int myReturn = GCD(input1, input2);

    return 0;

}


int GCD(int input1, int input2)
{
    if (input1 == input2)
    {
        return input1;
    }
    else
    {
        if (input1 < input2)
        {
            int temp = input1;
            input1 = input2;
            input2 = temp;
        }
        return GCD(input1 - input2, input2);
    }

}



