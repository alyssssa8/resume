

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
    vector<int> numberOfLines(vector<int>& widths, string S) {
        vector<int>ans;
        int temp = 0;
        int line = 0;
        for (int i = 0; i < S.length(); i++) {
            temp += widths[S[i] - 'a'];
            if (temp > 100) {
                line++;
                temp = 0;
                i--;
            }
        }
        if (temp > 0) {
            line++;
        }
        ans.push_back(line);
        ans.push_back(temp);
        return ans;

    }
};




int main()
{

    vector<int>nums({ 3, 1 ,0 });
    Solution question;
    question.numberOfLines(nums);
    Solution question2;
    question2.numberOfLines(nums);

    return 0;
}
