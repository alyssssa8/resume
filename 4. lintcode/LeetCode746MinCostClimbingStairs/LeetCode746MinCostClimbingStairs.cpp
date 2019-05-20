//https://leetcode.com/problems/min-cost-climbing-stairs/description/
//https://www.youtube.com/watch?v=v3WqNLmmBdk
//http://zxi.mytechroad.com/blog/dynamic-programming/leetcode-746-min-cost-climbing-stairs/


//
//On a staircase, the i - th step has some non - negative cost cost[i] assigned(0 indexed).
//
//Once you pay the cost, you can either climb one or two steps.You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.
//
//Example 1:
//Input: cost = [10, 15, 20]
//	Output : 15
//	Explanation : Cheapest is start on cost[1], pay that cost and go to the top.
//	Example 2 :
//	Input : cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
//	Output : 6
//	Explanation : Cheapest is start on cost[0], and only step on 1s, skipping cost[3].
//	Note :
//	cost will have a length in the range[2, 1000].
//	Every cost[i] will be an integer in the range[0, 999].
//


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
private:
	vector<int> ans;
public:
	int minCostClimbingStairs(vector<int>& cost) {
		ans = vector<int>(cost.size() + 1, 0);
		return dfs(cost, cost.size());
	}
	// cost[5] = 10;
	// 6th floor , pay 10.
	int dfs(vector<int> & cost, int i) {

		if (i <= 1) {
			return 0;
		}
		if (ans[i] >0) {
			return ans[i];
		}

		return ans[i] = min(dfs(cost, i - 2) + cost[i - 2], dfs(cost, i - 1) + cost[i - 1]);
	}
};

// 1,100,1
//       ()+1 ->> ()
//    ()+100  --> ()
//    ()+100
int main()
{

	vector<int>nums({ 1, 100, 1, 1, 1, 100, 1, 1, 100, 1 });
	Solution question;
	question.minCostClimbingStairs(nums);
	Solution question2;
	question2.minCostClimbingStairs(nums);

	return 0;
}
