

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
    string reverseWords(string s) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ') {   // when i is a non-space
                int j = i;
                for (; j < s.length() && s[j] != ' '; j++) {} // move j to the next space
                reverse(s.begin() + i, s.begin() + j);
                i = j - 1;
            }
        }

        return s;
    }
};

class Solution {
public:
    string reverseWords(string s) {
        string res;
        stack<int> tempStack;
        for (int i = 0; i < s.length(); i++) {

            if (s[i] == ' ' || i == s.length() - 1) {
                if (i == s.length() - 1) {
                    res += s[i];
                }
                while (tempStack.empty() == false) {

                    res += tempStack.top();
                    tempStack.pop();
                }

                if (i != s.length() - 1) {
                    res += ' ';
                }

            }

            else {
                tempStack.push(s[i]);
            }
        }
        return res;

    }
};

int main()
{

    vector<int>nums({ 3, 1 ,0 });
    Solution question;
    question.reverseWords("dfdf");
    Solution question2;
    question.reverseWords("dfdf");

    return 0;
}
