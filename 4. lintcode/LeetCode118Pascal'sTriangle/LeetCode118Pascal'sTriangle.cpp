


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


class Solution2 {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for (auto i = 0; i < numRows; ++i)
        {
            res.push_back(vector<int>(i + 1, 1));
            //row.push_back(1); same as above
            for (auto j = 1; j < i; ++j) res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
        }
        return res;
    }
};


class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> r(numRows);

        for (int i = 0; i < numRows; i++) {
            r[i].resize(i + 1);
            r[i][0] = r[i][i] = 1;

            for (int j = 1; j < i; j++)
                r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
        }

        return r;
    }
};
int main()
{

    vector<int>nums({ 3, 1, 4, 1, 5 });
    Solution question;
    question.generate(5);
   /* Solution2 question2;
    question2.findPairs(nums, 2);*/

    return 0;
}