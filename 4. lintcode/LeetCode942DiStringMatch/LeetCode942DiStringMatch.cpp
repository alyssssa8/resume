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
    vector<int> diStringMatch(string S)
    {
        int min = 0, max = S.size();
        vector<int> res;

        for (int i = 0; i < S.size(); i++)
        {
            if (S[i] == 'I') res.push_back(min++);
            if (S[i] == 'D') res.push_back(max--);
        }
        res.push_back(min);

        return res;
    }
};


int main()
{

    vector<int>nums({ 3, 1 ,0 });
    Solution question;
    question.diStringMatch("DIDI");
    Solution question2;
    question2.diStringMatch("DIDI");

    return 0;
}
