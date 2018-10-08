//https://leetcode.com/problems/subsets-ii/description/
//https://www.lintcode.com/problem/subsets-ii/description
//https://www.jiuzhang.com/solution/subsets-ii/
//http://www.goodtecher.com/leetcode-90-subsets-ii/
//Given a collection of integers that might contain duplicates, nums, return all possible subsets(the power set).
//Input : [1, 2, 2]
//	Output :
//	[
//		[2],
//		[1],
//		[1, 2, 2],
//		[2, 2],
//		[1, 2],
//		[]
//	]
#include <iostream>

#include <math.h>
#include <algorithm>
#include<vector>
#include<string>
#include <queue>
#include <stack>
#include <list>
#include <map>   //hash table
#include <vector>
using namespace std;

vector<vector<int>> subsetsWithDup(vector<int>& nums);
void dfs(const vector<int>& candidates, int s, vector<vector<int>>& ans, vector<int>& curr);


class Solution {
private:
	vector<vector<int>>ans;
	vector<int> tempAns;
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {

		sort(nums.begin(), nums.end());
		dfs(0, nums);

		return ans;
	}

	void dfs(int depth, vector<int> & nums)
	{
		ans.push_back(tempAns);
		for (int i = depth; i < nums.size(); i++)
		{
			if (i > depth && nums[i - 1] == nums[i])
			{
				continue;
			}

			tempAns.push_back(nums[i]);
			dfs(i + 1, nums);
			tempAns.pop_back();
		}

	}

}; 

int main()
{
	vector<int> candidates({ 1,2,2 });
	vector<int> myvector({ 1,2,3 });
	std::vector<int>::iterator it;

	if (find(myvector.begin(), myvector.end(), candidates[1]) != myvector.end()) {
		
		return true;
	}
	

	vector<vector<int>> result = subsetsWithDup(candidates);
	Solution question;
	question.subsetsWithDup(candidates);
	return 0;
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	vector<vector<int>> ans;
	std::sort(nums.begin(), nums.end());
	vector<int> curr;
	dfs(nums, 0, ans, curr);
	return ans;

}

void dfs(const vector<int>& candidates, int s, vector<vector<int>>& ans, vector<int>& curr) {
	vector< vector<int> >::iterator row;
	vector<int>::iterator col;

	ans.push_back(curr);
	cout << "  ans: ";
	for (row = ans.begin(); row != ans.end(); row++) {
		for (col = row->begin(); col != row->end(); col++) {
			cout << *col;
		}
		cout << ",";
	}


	for (int i = s; i < candidates.size(); ++i) {
		if (i != s && candidates[i] == candidates[i - 1])
		{
			continue;
		}

		curr.push_back(candidates[i]);
		dfs(candidates, i + 1, ans, curr);
		curr.pop_back();
	}
	/*cout << "  ans: ";
	for (row = ans.begin(); row != ans.end(); row++) {
		for (col = row->begin(); col != row->end(); col++) {
			cout << *col;
		}
		cout << ",";
	}

*/

}