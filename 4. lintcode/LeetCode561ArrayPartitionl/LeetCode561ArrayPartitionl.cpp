//https://leetcode.com/problems/array-partition-i/description/
//Given an array of 2n integers, your task is to group these integers into n pairs of integer, say(a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.
//
//Example 1 :
//	Input : [1, 4, 3, 2]
//
//	Output : 4
//	Explanation : n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).
//	Note :
//	n is a positive integer, which is in the range of[1, 10000].
//	All the integers in the array will be in the range of[-10000, 10000].


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

class Solution2 {
public:
	int arrayPairSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int ans = 0;
		for (int i = 0; i < nums.size(); i += 2)
		{
			ans += nums[i];
		}
        return ans;
	}
};

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        vector<int> hashtable(20001, 0);
        for (size_t i = 0; i < nums.size(); i++)
        {
            hashtable[nums[i] + 10000]++;  // avoid the negative problem!
        }
        int ret = 0;
        int flag = 0;
        for (size_t i = 0; i < 20001;) {
            if ((hashtable[i] > 0) && (flag == 0)) {  // use flag to minus one value or skip the one. 
                ret = ret + i - 10000;
                flag = 1;
                hashtable[i]--;
            }
            else if ((hashtable[i] > 0) && (flag == 1)) {
                hashtable[i]--;
                flag = 0;
            }
            else i++;
        }
        return ret;

    }
};

int main()
{

	vector<int>nums({ 1,4,3,2 });

	Solution question;
	question.arrayPairSum(nums);
	
	return 0;
}


