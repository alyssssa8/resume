//https://leetcode.com/problems/degree-of-an-array/description/
//
//Given a non - empty array of non - negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.
//
//Your task is to find the smallest possible length of a(contiguous) subarray of nums, that has the same degree as nums.
//
//Example 1:
//Input: [1, 2, 2, 3, 1]
//	Output : 2
//	Explanation :
//	The input array has a degree of 2 because both elements 1 and 2 appear twice.
//	Of the subarrays that have the same degree :
//	   [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
//		   The shortest length is 2. So return 2.
//		   Example 2 :
//		   Input : [1, 2, 2, 3, 1, 4, 2]
//		   Output : 6
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
//99.19%

// 找到最短的重复的距离
// 1，2，2，3，1，4，2
//index 1 to index 6, 6-1 =5 + 1 = 6


class Solution2 {
public:
	int findShortestSubArray(vector<int>& nums) {
		int counter[50000] = { 0 };
		int first[50000] = { 0 };

		int degree = 0;
		int min_length = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (counter[nums[i]] == 0) {
				counter[nums[i]] = 1;
				first[nums[i]] = i;
			}
			else
				counter[nums[i]]++;
			if (counter[nums[i]] > degree) { // get the most frequence(degree).
				degree = counter[nums[i]];
				min_length = i - first[nums[i]] + 1;
			}
			else if (counter[nums[i]] == degree) {
				min_length = min(min_length, i - first[nums[i]] + 1);
			}
		}

		return min_length;
	}
};


class Solution {
public:
	int findShortestSubArray(vector<int>& nums) {
		map<int, vector<int>>myMap;
		int ans = INT_MAX;
		int maxTimes = 0;
		for (int i = 0; i <nums.size(); i++) {
			if (myMap[nums[i]].empty()) {
				myMap[nums[i]].push_back(1);
				myMap[nums[i]].push_back(i);
				myMap[nums[i]].push_back(i);
			}
			else {
				myMap[nums[i]][0]++;
				myMap[nums[i]][2] = i;
			}
			if (myMap[nums[i]][0] == maxTimes) {
				ans = min(ans, myMap[nums[i]][2] - myMap[nums[i]][1] + 1);
			}
			else if (myMap[nums[i]][0] > maxTimes) {
				ans = myMap[nums[i]][2] - myMap[nums[i]][1] + 1;
				maxTimes = myMap[nums[i]][0];
			}
		}
		return ans;
	}
};


class Solution3 {
public:
	int findShortestSubArray(vector<int>& nums) {
		unordered_map<int, vector<int>> mMap;
		int maxTimes = 0;

		for (int i = 0; i<nums.size(); ++i) {
			if (mMap[nums[i]].empty()) {
				mMap[nums[i]].push_back(1);
				mMap[nums[i]].push_back(i);
				mMap[nums[i]].push_back(i);
			}
			else {
				mMap[nums[i]][0]++;
				mMap[nums[i]][2] = i;
			}
			maxTimes = max(maxTimes, mMap[nums[i]][0]);
		}

		int retVal = INT_MAX;
		for (pair<int, vector<int>> val : mMap) {
			if ((val.second)[0] == maxTimes) {
				retVal = min(retVal, (val.second)[2] - (val.second)[1] + 1);
			}
		}
		return retVal;
	}
};

int main()
{

	vector<int>nums({ 1, 2, 2, 3, 1});
	Solution question;
	question.findShortestSubArray(nums);
	Solution question2;
	question2.findShortestSubArray(nums);

	return 0;
}
