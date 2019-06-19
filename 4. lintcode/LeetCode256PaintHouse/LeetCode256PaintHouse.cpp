
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
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return min(costs[0][0], min(costs[0][1], costs[0][2]));
        }

        for (int i = 1; i < n; i++) {
            costs[i][0] += min(costs[i - 1][1], costs[i - 1][2]);
            costs[i][1] += min(costs[i - 1][0], costs[i - 1][2]);
            costs[i][2] += min(costs[i - 1][0], costs[i - 1][1]);
        }

        return min(costs[n - 1][0], min(costs[n - 1][1], costs[n - 1][2]));
    }
};
int main()
{
    vector<vector<int>> nums({ { 17,2,17 }, { 16, 16, 5 }, { 14,3,19 } });
    Solution question;
    question.minCost(nums);
    return 0;
}
