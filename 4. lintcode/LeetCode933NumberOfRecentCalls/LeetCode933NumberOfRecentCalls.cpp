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



class RecentCounter {
public:
    queue<int> q;
    RecentCounter() {

    }

    int ping(int t) {
        while (q.empty() == false && q.front() < t - 3000) {
            q.pop();
        }
        q.push(t);
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

int main()
{

    RecentCounter* obj = new RecentCounter();
    int t = 1000;
    int param_1 = obj->ping(t);

    return 0;
}