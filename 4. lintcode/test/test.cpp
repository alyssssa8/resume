

#include <iostream>
#include <math.h>
#include <algorithm>
#include<vector>
#include<string>
#include <queue>
#include <stack>
#include <list>
#include <map>   //hash table
#include<unordered_map>
#include <vector>
using namespace std;


int main()
{
    int i = 0;
    int j = 0;
    while (i < 10) {
        while (j < 100) {
            if (j > 50) {
                break;
            }
            j++;
        }
        if (i >= 5) {
            break;
        }
        i++;

    }
    cout << j << ": " << i << endl;
    return 0;
}



