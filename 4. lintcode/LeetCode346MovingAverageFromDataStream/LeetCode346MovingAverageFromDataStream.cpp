

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
// use this one


class MovingAverage {
private:
    queue<int> qu;
    int avergeSize;
    double sum;
public:
    MovingAverage(int size) {
        avergeSize = size;
    }

    double next(int val) {
        sum += val;
        qu.push(val);
        int queueSize = (int)qu.size();
        if (queueSize <= avergeSize) {
            return sum / queueSize;
        }
        else {
            sum -= qu.front();
            qu.pop();
            return sum / avergeSize;
        }
    }
};
int main()
{
    MovingAverage m(3);
    return 0;
}
