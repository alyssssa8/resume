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
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int>m;
        for (int i = 0; i < paragraph.length(); ) {
            string s = "";
            while (i < paragraph.length() && isalpha(paragraph[i])) {
                s.push_back(tolower(paragraph[i++]));
            }
            while (i < paragraph.length() && !isalpha(paragraph[i])) {
                i++;
            }

            m[s]++;
        }

        for (auto x : banned) {
            m[x] = 0;
        }
        string res = "";
        int count = 0;
        for (auto x : m) {
            if (x.second > count) {
                res = x.first;
                count = x.second;
            }
        }
        return res;

    }
};



int main()
{

    vector<string>nums({ "1", "1" ,"0" });
    Solution question;
    question.mostCommonWord("jkljl",nums);
    Solution question2;
    //question2.mostCommonWord("jkljl", { "1", "1" ,"0" });

    return 0;
}