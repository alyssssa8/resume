//https://leetcode.com/problems/can-place-flowers/description/
//
//Suppose you have a long flowerbed in which some of the plots are planted and some are not.However, flowers cannot be planted in adjacent plots - they would compete for water and both would die.
//
//Given a flowerbed(represented as an array containing 0 and 1, where 0 means empty and 1 means not empty), and a number n, return if n new flowers can be planted in it without violating the no - adjacent - flowers rule.
//
//Example 1:
//Input: flowerbed = [1, 0, 0, 0, 1], n = 1
//	Output : True
//	Example 2 :
//	Input : flowerbed = [1, 0, 0, 0, 1], n = 2
//	Output : False
//	Note :
//	   The input array won't violate no-adjacent-flowers rule.
//		   The input array size is in the range of[1, 20000].
//		   n is a non - negative integer which won't exceed the input array size.

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
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		flowerbed.insert(flowerbed.begin(), 0);
		flowerbed.push_back(0);
		for (int i = 1; i < flowerbed.size() - 1; ++i)
		{
			if (flowerbed[i - 1] + flowerbed[i] + flowerbed[i + 1] == 0)
			{
				--n;
				++i;
			}

		}
		return n <= 0;  //[0,0,1,0,0//1
	}
};

class Solution3 {
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {

		int count = 0;
		for (int i = 0; i < flowerbed.size(); i++) {
			if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)) {
				flowerbed[i] = 1;
				count++;
			}
			if (count >= n)  //if count == 0, return true;
				return true;
		}
		return false;
	}
};

class Solution4 {
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {

		for (int i = 0; i < flowerbed.size(); i++) {
			if ((flowerbed[i - 1] == 0 || i == 0) && flowerbed[i] == 0 && (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)) {
				n--;
				i++;
			}
		}
		return n <= 0;

	}
};


// input [0], 1
// 10001, 1


int main()
{

	vector<int>nums({ 1, 0, 0, 0, 0, 0, 1 });
	int n = 2;
	Solution question;
	question.canPlaceFlowers(nums,n);
	Solution3 question2;
	question2.canPlaceFlowers(nums,n);

	return 0;
}

