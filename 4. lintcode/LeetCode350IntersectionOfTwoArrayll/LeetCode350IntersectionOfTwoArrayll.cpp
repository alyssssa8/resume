//https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
//Given two arrays, write a function to compute their intersection.
//
//Example :
//	Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return[2, 2].
//
//	Note :
//	Each element in the result should appear as many times as it shows in both arrays.
//	The result can be in any order.
//	Follow up :
//What if the given array is already sorted ? How would you optimize your algorithm ?
//What if nums1's size is small compared to nums2's size ? Which algorithm is better ?
//What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once ?


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



class Test {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

		
	}
};
class Solution3 {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		int sz1 = nums1.size(), sz2 = nums2.size();
		vector<int> res;
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		int i = 0, j = 0;
		while (i != sz1 && j != sz2)
		{
			if (nums1[i] == nums2[j])
			{
				res.push_back(nums1[i]);
				i++; j++;
			}
			else if (nums1[i] > nums2[j])    //nums2 should go up
				j++;
			else if (nums1[i] < nums2[j])    //nums1 should go up
				i++;
		}
		return res;
	}
};

// use this one
class Solution2 {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
	{
		map<int, int> S;
		vector<int> V;

		int n = nums1.size();
		int m = nums2.size();

		for (int i = 0; i<n; i++)
		{
			S[nums1[i]]++; //nums1[i]=1  //1 2, 2 2
		}

		for (int i = 0; i<m; i++)
		{
			if (S[nums2[i]]>0)
			{
				V.push_back(nums2[i]);
				S[nums2[i]]--;
			}
		}

		return V;
	}
};
class Solution {
public:
	vector<int> intersect(vector<int>& a, vector<int>& b) {
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		a.erase(set_intersection(a.begin(), a.end(), b.begin(), b.end(), a.begin()), a.end());
		

		return a;
	}
};
int main()
{
	vector<int>nums1{ 1,2,2,1 };

	vector<int>nums2{ 2,2 };
	int newColor = 2;

	/*Solution question;
	question.intersect(nums1,nums2);*/
	Solution2 question2;
	question2.intersect(nums1, nums2);
	/*Solution3 question3;
	question3.intersect(nums1, nums2);*/


	return 0;
}