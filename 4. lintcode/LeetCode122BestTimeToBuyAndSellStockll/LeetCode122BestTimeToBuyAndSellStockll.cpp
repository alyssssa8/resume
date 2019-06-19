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
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;

        int res = 0;

        for (size_t i = 1; i < prices.size(); i++)
            if (prices[i] - prices[i - 1] > 0)
                res += prices[i] - prices[i - 1];

        return res;
    }
};


int main()
{

    vector<int>nums({ 7, 1 ,5, 3, 6, 4 });
    Solution question;
    question.maxProfit(nums);
    Solution question2;
    question2.maxProfit(nums);

    return 0;
}