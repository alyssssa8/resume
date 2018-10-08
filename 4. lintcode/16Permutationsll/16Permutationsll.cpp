//
//https://leetcode.com/problems/permutations-ii/description/
//https://www.jiuzhang.com/solution/permutations-ii/#tag-highlight-lang-cpp
//https://www.lintcode.com/problem/permutations-ii/description
//Given a collection of numbers that might contain duplicates, return all possible unique permutations.
//
//Example:
//
//Input: [1, 1, 2]
//	Output :
//	[
//		[1, 1, 2],
//		[1, 2, 1],
//		[2, 1, 1]
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

vector<vector<int>> permuteUnique(vector<int>& nums);
void helper(vector<vector<int> > &results, vector<int> &permutation, vector<int> &nums, bool used[]);




class Solution {
private:

	vector<vector<int>> ans;
	vector<int> tempAns;
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		bool *used = new bool[nums.size()];

		for (int i = 0; i < nums.size(); i++)
		{
			used[i] = false;
		}

		sort(nums.begin(), nums.end());
		dfs(nums, used);
		delete[] used;
		return ans;

	}
	void dfs(vector<int>& nums, bool used[])
	{

		if (tempAns.size() == nums.size())
		{
			ans.push_back(tempAns);
			return;
		}


		for (int i = 0; i <nums.size(); i++)
		{
			if (used[i] == true)
			{
				continue;
			}
			if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == true)
			{
				continue;
			}
			used[i] = true;

			tempAns.push_back(nums[i]);
			dfs(nums, used);
			tempAns.pop_back();
			used[i] = false;

		}
	}
};

int main()
{
	vector<int> candidates({ 1,1,2 });
	vector<vector<int>> result = permuteUnique(candidates);
	vector< vector<int> >::iterator row;
	vector<int>::iterator col;
	cout << "return result: " << endl;
	for (row = result.begin(); row != result.end(); row++) {
		for (col = row->begin(); col != row->end(); col++) {
			cout << *col;
		}
		cout << endl;
	}

	return 0;
}

vector<vector<int>> permuteUnique(vector<int>& nums){
	vector<vector<int> > results;
	vector<int> permutation;
	int arraySize = nums.size();
	bool *used = new bool[arraySize];
	
	for (int i = 0; i < nums.size(); i++) {
		used[i] = false;
	}

	sort(nums.begin(), nums.end());
	helper(results, permutation, nums, used);
	delete [] used;
	return results;

}

void helper(vector<vector<int> > &results,vector<int> &permutation,vector<int> &nums,bool used[]){
	if (nums.size() == permutation.size()) {
			results.push_back(permutation);
			return;
		}

		for (int i = 0; i < nums.size(); i++) {
			if (used[i]) {
				continue;
			}
			if (i > 0 && used[i - 1] == false && nums[i] == nums[i - 1]) {
				continue;//112 121
			}

			used[i] = true;
			permutation.push_back(nums[i]);
			helper(results, permutation, nums, used);
			permutation.pop_back();
			used[i] = false;
		}



}