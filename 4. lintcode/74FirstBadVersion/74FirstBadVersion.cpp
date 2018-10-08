









//You are a product manager and currently leading a team to develop a new product.Unfortunately, the latest version of your product fails the quality check.
//Since each version is developed based on the previous version, all the versions after a bad version are also bad.
//
//Suppose you have n versions[1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.
//
//You are given an API bool isBadVersion(version) which will return whether version is bad.Implement a function to find the first bad version.
//You should minimize the number of calls to the API.
//https://leetcode.com/problems/first-bad-version/description/
//http://www.lintcode.com/en/problem/first-bad-version/
//https://www.jiuzhang.com/solution/first-bad-version/

#include <iostream>

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





bool isBadVersion(int version)
{
	if (version == 5)
		return false;
}

class Solution {
public:
	int firstBadVersion(int n) {

		int start = 1;
		int end = n;
		while (start <= end)
		{
			int mid = start + (end - start) / 2;
			if (isBadVersion(mid)) // spell error. "isBadversion"
			{
				end = mid - 1;
			}
			else
			{
				start = mid + 1;
			}
		}
		return start;

	}
};

int main()
{


	Solution question;
	question.firstBadVersion(5);
	
	return 0;
}
