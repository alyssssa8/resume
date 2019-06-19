

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
class Solution3 {
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

class Solution2 {
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

// own
class Solution {
public:
    string reverseWords(string s) {
        string tempString = "";
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                for (int j = tempString.size() - 1; j >= 0; j--) {
                    ans += tempString[j];
                }
                tempString = "";
                ans += ' ';
            }
            else {
                tempString += s[i];
            }
        }
        for (int j = tempString.size() - 1; j >= 0; j--) {
            ans += tempString[j];
        }
        return ans;
    }
};
int main()
{
    vector<int>nums({ 3, 1 ,0 });
    Solution question;
    question.reverseWords("Let's take LeetCode contest");
    Solution question2;
    question.reverseWords("dfdf");
    return 0;
}
