//359. Logger Rate Limiter
//Easy
//
//191
//
//65
//
//Favorite
//
//Share
//Design a logger system that receive stream of messages along with its timestamps, each message should be printed if and only if it is not printed in the last 10 seconds.
//
//Given a message and a timestamp(in seconds granularity), return true if the message should be printed in the given timestamp, otherwise returns false.
//
//It is possible that several messages arrive roughly at the same time.
#include <iostream>
#include <math.h>
#include <algorithm>
#include<vector>
#include<string>
#include <queue>
#include <stack>
#include <list>
#include <map>   //hash table
#include <vector>
using namespace std;

class Logger {
private:
    map<string, int>ok;
public:
    /** Initialize your data structure here. */
    Logger() {

    }

    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if (timestamp < ok[message]) {
            return false;
        }
        ok[message] = timestamp + 10;
        return true;
    }
};


int main()
{
    vector<int> num({ 1,2,3,4,5,6,7 });
    /* Solution question;
     question.rotate(num,3);*/
   /* Solution3 question3;
    int nums[] = { 1, 2, 3, 4, 5, 6, 7 };
    question3.rotate(nums, 7, 3);*/
    return 0;

}

