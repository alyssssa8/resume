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
    vector<string> braces(vector<string> values) {
        stack<char> myStack;
        vector<string> ans;
        int arrSize = values.size();
        for (int j = 0; j < arrSize; j++) {
            while (myStack.empty() == false) {
                myStack.pop();
            }

            bool determined = false;  // must have this. for example: "{[}" "{]}"

            for (int i = 0; i < values[j].size(); i++) {
                if (values[j][i] == '(') {
                    myStack.push(')');
                }
                else if (values[j][i] == '{') {
                    myStack.push('}');
                }
                else if (values[j][i] == '[') {
                    myStack.push(']');
                }
                else {
                    if (myStack.empty() || myStack.top() != values[j][i]) {
                        ans.push_back("NO");
                        determined = true;  //"{]}"

                        break;
                    }
                    else {
                        myStack.pop();
                    }
                }
            }

            if (determined == false && myStack.empty()) {  //"{[}"

                ans.push_back("YES");
            }
            else if (myStack.empty() == false && determined == false) {
                ans.push_back("NO");
            }
        }

        return ans;
    }



};


int main()
{

    Solution question;
    vector<string> values({ {"{}[()"},{"{[}]}"} });
    question.braces(values);
    return 0;
}