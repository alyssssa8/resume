//https://leetcode.com/problems/single-number/description/
//
//Given a non - empty array of integers, every element appears twice except for one.Find that single one.
//
//Note :
//
//	Your algorithm should have a linear runtime complexity.Could you implement it without using extra memory ?
//
//	Example 1 :
//
//	Input : [2, 2, 1]
//	Output : 1
//	Example 2 :
//
//	Input : [4, 1, 2, 1, 2]
//	Output : 4




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
#include<set>
using namespace std;

class Solution2 {
public:
	int singleNumber(vector<int>& nums) {
		set<int> numset;

		for (int num : nums)
		{
			if (numset.find(num) == numset.end())
				numset.insert(num);
			else
				numset.erase(num);
		}

		return *(numset.begin());
	}
};

class Solution3 {
public:
	int singleNumber(vector<int>& nums)
	{
		unordered_map<int, int> m;
		for (int i = 0; i<nums.size(); i++)
			m[nums[i]]++;
		for (auto count : m)
			if (count.second != 2)
				return count.first;
	}
};

class Solution4 {
public:
	int singleNumber(vector<int>& nums)
	{
		unordered_map<int, int> m;
		for (int i = 0; i<nums.size(); i++) {
			m[nums[i]]++;
		}
		for (int i = 0; i<nums.size(); i++) {
			if (m[nums[i]] != 2) {
				return nums[i];
			}
		}

	}
};


class Solution {
public:
	int singleNumber(vector<int>& nums)
	{
		int result = 0;
		for (int i = 0; i<nums.size(); i++)
		{
			result ^= nums[i];
		}
		return result;
	}
};

//39.39%
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end());

		for (int i = 0; i <nums.size(); i = i + 2)
			if (nums[i] != nums[i + 1]) {
				return nums[i];
			}

		return 0;
	}
};
int main()
{

	vector<int>nums({ 2, 2 ,0 });
	Solution question;
	question.singleNumber(nums);
	Solution question2;
	question2.singleNumber(nums);

	return 0;
}
