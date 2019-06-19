//https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/
//448. Find All Numbers Disappeared in an Array
//DescriptionHintsSubmissionsDiscussSolution
//Given an array of integers where 1 ¡Ü a[i] ¡Ü n(n = size of array), some elements appear twice and others appear once.
//
//Find all the elements of[1, n] inclusive that do not appear in this array.
//
//Could you do it without extra space and in O(n) runtime ? You may assume the returned list does not count as extra space.
//
//Example :
//
//	Input :
//	[4, 3, 2, 7, 8, 2, 3, 1]
//
//Output :
//	[5, 6]

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


class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		vector<int>ans;
		for (int i = 1; i <= nums.size(); i++) {
			ans.push_back(i);
		}
		for (int i = 0; i <nums.size(); i++) {
			ans[nums[i] - 1] = -1;
		}
		ans.erase(remove(ans.begin(), ans.end(), -1), ans.end());
		return ans;
	}
};

class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {

		vector< int > res;
		for (auto i = 1; i <= nums.size(); ++i)
			res.push_back(i);

		for (auto n : nums)
		{
			if (n <= nums.size())
				res[n - 1] = -1;
		}
	

		res.erase(remove(res.begin(), res.end(), -1), res.end());
		//remove: from, end, remove value.
		// remove return: An iterator to the element that follows the last element not removed.
		//Removes from the vector either a single element (position) or a range of elements ([first,last)).
		return res;

	}
};
//bad one 
class Solution2  {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		vector<int>ans;
		int count = 0;
		set <int > newNumber(nums.begin(), nums.end());
		vector<int>newNum(newNumber.begin(), newNumber.end());
		sort(nums.begin(), nums.end());		
		int size = nums.size();
		for (int i = 1; i <= size; i++)
		{
			if (i != newNum[count]) {
				ans.push_back(i);
				continue;
			}
			count++;
		}
		return ans;
	}
};


int main()
{
	vector<int>nums({ 4,3,2,7,8,2,3,1});
	Solution question;
	question.findDisappearedNumbers(nums);
	/*Solution question2;
	question2.sortedArrayToBST(nums);
*/
	return 0;
}