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

//use this one
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        int minInt = prices[0];
        int maxInt = 0;
        for (int i = 1; i < prices.size(); i++) {
            maxInt = max(prices[i] - minInt, maxInt);
            minInt = min(prices[i], minInt);
        }
        return maxInt;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int myMin = INT_MAX;
        int maxP = 0;
        for (int i = 1; i <prices.size(); i++){
            myMin = min(myMin,prices[i-1] );
            maxP = max(maxP, prices[i] - myMin);
            
        }
        return maxP;
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