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
class Solution
{
public:
    string addBinary(string a, string b)
    {
        string ans = "";
        int newNum = 0;
        int i = a.size() - 1;
        int j = b.size() - 1;
        while (i >= 0 || j >= 0 || newNum == 1)
        {
            //newNum will get the real integer
            if (i >= 0) {
                newNum += a[i] - '0';
                i--;
            }
            if (j >= 0) {
                newNum += b[j] - '0';
                j--;
            }
            ans = char(newNum % 2 + '0') + ans;  // pay attention on the char() function
            newNum /= 2; //to check f there is a carry on!
        }
        return ans;
    }
};


int main()
{



    vector<int>nums({ 3, 1 ,0 });
    Solution question;
    question.addBinary("110","010");
   

    return 0;
}