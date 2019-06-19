//https://leetcode.com/problems/array-partition-i/description/
//Given an array of 2n integers, your task is to group these integers into n pairs of integer, say(a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.
//
//Example 1 :
//	Input : [1, 4, 3, 2]
//
//	Output : 4
//	Explanation : n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).
//	Note :
//	n is a positive integer, which is in the range of[1, 10000].
//	All the integers in the array will be in the range of[-10000, 10000].


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

class TwoSum {
private:
    unordered_map<int, int> myMap;
public:
    /** Initialize your data structure here. */
    TwoSum() {

    }

    /** Add the number to an internal data structure.. */
    void add(int number) {
        myMap[number]++;
    }

    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for (auto i : myMap) {
            // if(myMap.count(value - i.first) && (i.first != value - i.first || i.second > 1)){
            //     return true;
            // }
            if (myMap.count(value - i.first) && (i.first != value - i.first || i.second > 1)) {
                return true;
            }
        }
        return false;

    }
};


int main()
{

    vector<string>nums({ "bella","label","roller" });

    TwoSum question;
    question.add(1);
    question.add(3);
    question.add(3);
    question.add(5);
    question.find(4);
    question.find(7);
    return 0;
}


