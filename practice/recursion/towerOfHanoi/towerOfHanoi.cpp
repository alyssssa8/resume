


#include <iostream>

using namespace std;

int towerOfHanoi(char A, char B, char C, int n);
int main()
{
    char A = 'A', B  ='B', C = 'C';
    int n = 3;
    int myReturn = towerOfHanoi(A, B, C, n);

    return 0;

 }


int towerOfHanoi(char A, char B, char C,int n)
{ 
  
    if (n > 0)
    {
        towerOfHanoi(A, C, B, n - 1);
        cout << " from " << A << " to " << C <<endl;
        towerOfHanoi(B, A, C, n - 1);
    }
    return 0;

}



