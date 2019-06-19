//https://leetcode.com/problems/min-stack/description/
//
//Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
//
//push(x) --Push element x onto stack.
//pop() --Removes the element on top of the stack.
//top() --Get the top element.
//getMin() --Retrieve the minimum element in the stack.
//Example:
//MinStack minStack = new MinStack();
//minStack.push(-2);
//minStack.push(0);
//minStack.push(-3);
//minStack.getMin();   --> Returns - 3.
//minStack.pop();
//minStack.top();      --> Returns 0.
//minStack.getMin();   --> Returns - 2.




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
bool myCompare(string a, string b) {
    int i = a.find(' ');
    int j = b.find(' ');
    if (isdigit(a[i + 1])) {
        if (isdigit(b[j + 1])) {
            return false;       // a b are both digit logs, a == b, keep their original order
        }
        else {
            return false;       // a is digit log, b is letter log, a > b
        } 
    }
    else {
        if (isdigit(b[j + 1])) {
            return true;        // a is letter log, b is digit log, a < b
        }
        else {
            if (a.substr(i) == b.substr(j)) {
                return a.substr(0, i) < b.substr(0, j); //If string part is the same, compare key
            }
            else {
                return a.substr(i) < b.substr(j);   // a and b are both letter
            }
        }
    }
}

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        //The order of equal elements is guaranteed to be preserved in stable_sort.
        //Use sort() cannot pass the OJ. 
        stable_sort(logs.begin(), logs.end(), myCompare);
        return logs;
    }
};



int main()
{



    vector<string>nums({ "3", "1" ,"0" });
    Solution question;
    question.reorderLogFiles(nums);


    return 0;
}