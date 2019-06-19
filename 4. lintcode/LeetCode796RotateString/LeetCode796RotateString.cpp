


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
    bool rotateString(string A, string B) {
        if (A.size() != B.size()) return false;
        if (A == B) {
            return true;
        }
        for (int i = 0; i < A.size(); ++i) {
            if (A.substr(i, A.size() - i) + A.substr(0, i) == B) return true;
        }
        return false;
    }
};


class Solution
{
public:
    bool rotateString(string text, string pattern)
    {
        // Rotating strings does not change their length
        if (text.length() != pattern.length()) return false;

        // Concatenate the first string to itself to get the rid of circular searching
        string concatenatedString = text + text;

        // If it is a rotation, then it must occur as a substring of the concatenated string
        if (concatenatedString.find(pattern) != string::npos) return true;
        else {
            return false;
        }
    }
};
int main()
{

    vector<int>nums({ 3, 1, 4, 1, 5 });
    Solution question;
    question.rotateString("adf","dfs");
    /* Solution2 question2;
     question2.findPairs(nums, 2);*/

    return 0;
}