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

class Solution {
public:
    bool isValid(string s) {
        stack<char>myStack;
        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '{') {
                myStack.push('}');
            }
            else if (s[i] == '[') {
                myStack.push(']');
            }
            else if (s[i] == '(') {
                myStack.push(')');
            }
            else {
                if (myStack.empty() || myStack.top() != s[i]) {
                    return false;
                }
                else {
                    myStack.pop();
                }
            }
        }

        return myStack.empty();
    }
};


int main()
{

    vector<int>nums({ 3, 1 ,0 });
    Solution question;
    question.isValid("()");
    Solution question2;
    question2.isValid("()");

    return 0;
}