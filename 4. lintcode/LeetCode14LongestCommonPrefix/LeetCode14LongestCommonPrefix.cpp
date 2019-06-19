

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
    string longestCommonPrefix(vector<string>& strs) {

        if (strs.empty()) {
            return "";
        }
        if (strs.size() == 1) {
            return strs[0];
        }
        for (int i = 0; i < strs[0].size(); i++) {
            for (int j = 0; j < strs.size() - 1; j++) {
                if (i >= strs[j + 1].size() || strs[j][i] != strs[j + 1][i]) {
                    return strs[j].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};

int main()
{


    vector<string>nums({ "flower","flow","flight" });
   
    vector<int>nums2({ 1 });
    Solution question;
    question.longestCommonPrefix(nums);
    /*   Solution question2;
       question2.merge(250);*/
    return 0;
}