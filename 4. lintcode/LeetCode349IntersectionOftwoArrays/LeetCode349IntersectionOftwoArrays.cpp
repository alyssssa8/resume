//https://leetcode.com/problems/intersection-of-two-arrays/description/
//Given two arrays, write a function to compute their intersection.
//
//Example:
//Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return[2].
//
//Note :
//	Each element in the result must be unique.
//	The result can be in any order.
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
#include<unordered_set>
#include <vector>
#include<set>
using namespace std;

class Test {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		set<int>mySet1;
		set<int>mySet2;

		for (int i = 0; i < nums1.size(); i++)
		{
			mySet1.insert(nums1[i]);
		}

		for (int i = 0; i < nums2.size(); i++)
		{
			if (mySet1.find(nums2[i]) != mySet1.end())
			{
				mySet2.insert(nums2[i]);
			}
		}
		vector<int>result(mySet2.begin(), mySet2.end());
		return result;		
	}
};

class Solution3 {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		set<int> hashSet;  //set will avoid the repetition
		vector<int> result;
		for (int i = 0; i<nums1.size(); i++)
		{
			hashSet.insert(nums1[i]); //hashSet[0]:1, hasSet[1]:2
		}

		for (int i = 0; i<nums2.size(); i++)
		{
			if (hashSet.find(nums2[i]) != hashSet.end())
			{
				if (std::find(result.begin(), result.end(), nums2[i]) != result.end())
				{
					//do nothing // already in the vector, avoid the repetition. 
				}
				else
				{
					result.push_back(nums2[i]);
				}
			}
		}
		return result;

	}
};

//beats 100%
class Solution2 {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, bool> seen;
		vector<int> res;
		for (int i = 0; i < nums1.size(); i++) {
			seen.insert(make_pair(nums1[i], false));
		}
		for (int j = 0; j < nums2.size(); j++) {
			auto itr = seen.find(nums2[j]);
			if (itr != seen.end()) {
				if (!itr->second) {  //false
					res.push_back(nums2[j]);
					itr->second = true;
				}
			}
		}
		return res;
	}
};
    
class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

		unordered_set<int> mySet1;  //to store the elements from nums1
		unordered_set<int> mySet2;  //to store the elements from mums2 which are also present in nums1
		for (int i = 0; i < nums1.size(); i++) {
			mySet1.insert(nums1[i]);
		}

		for (int j = 0; j < nums2.size(); j++) {
			if (mySet1.find(nums2[j]) != mySet1.end()) {
				mySet2.insert(nums2[j]);
			}
		}
		vector <int> vec(mySet2.begin(), mySet2.end()); //store elements from mySet2 to vector 
		return vec;
	}
};
int main()
{
	vector<int>nums1{ 1,2,2,1 };

	vector<int>nums2{ 2,2,1 };
	int newColor = 2;
	vector<int> ans(2, 3);
	/*Solution question;
	question.intersection(nums1,nums2);*/
	Solution2 question2;
	question2.intersection(nums1, nums2);
	Solution3 question3;
	question3.intersection(nums1, nums2);
	Test question4;
	question4.intersection(nums1, nums2);


	return 0;
}