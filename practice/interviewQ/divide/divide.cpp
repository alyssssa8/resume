#include <iostream>

#include <string>
#include <string.h>

#include <math.h>
#include <time.h>

#include <fstream>

#include <map>   //hash table
#include <queue>
#include <stack>
#include <list>
#include "windows.h"
#include <vector>

#define SIZE 10
using namespace std;
const int FIRST_NUMBER = 111;
const int SECOND_NUMBER = 2;


int main()
{
    int counter = 0;
    int reminder = FIRST_NUMBER;
    //int temp = FIRST_NUMBER;
    while ( reminder >=SECOND_NUMBER)
    {
        reminder -= SECOND_NUMBER;
        counter++;

    }
    cout << counter << endl;
    cout << "The reminder is: " << reminder << endl;
    return 0;
}
