

//https://leetcode.com/problems/house-robber/description/
//https://www.youtube.com/watch?v=H75Qp7ExCwo
//http://zxi.mytechroad.com/blog/dynamic-programming/leetcode-198-house-robber/
//You are a professional robber planning to rob houses along a street.Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
//
//Given a list of non - negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
//
//Example 1 :
//
//	Input : [1, 2, 3, 1]
//	Output : 4
//	Explanation : Rob house 1 (money = 1) and then rob house 3 (money = 3).
//	Total amount you can rob = 1 + 3 = 4.
//	Example 2 :
//
//	Input : [2, 7, 9, 3, 1]
//	Output : 12
//	Explanation : Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
//	Total amount you can rob = 2 + 9 + 1 = 12


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
	int rob(vector<int>& nums) {
		ans = vector<int>(nums.size(), -1);
		return rob(nums, nums.size() - 1);
	}

	int rob(vector<int>& nums, int i) {
		if (i < 0) {
			return 0;
		}
		if (ans[i] >= 0) {
			cout << "****" << endl;
			cout << "return ans[i]: " << ans[i] << endl;
			cout << "****" << endl;
			return ans[i];
		}
		cout << "i: " << i << endl;
		cout << "ans[i]" << ans[i] << " nums[i]" << nums[i] << endl;		
		int a = rob(nums, i - 2);
		int b = rob(nums, i - 1);
		cout << "**********num[i]: "<<nums[i] << endl;

		return ans[i] = max(a + nums[i], b);
	}


};

//[1,2,3,1]
//[2,7,9,3,1]
//[10,1,2,8]

int main()
{
	vector<int>nums({ 2, 7, 9, 3, 1});
	Solution question;
	question.rob(nums);
	Solution question2;
	question2.rob(nums);

	return 0;
}
