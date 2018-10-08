//https://leetcode.com/problems/guess-number-higher-or-lower/description/
//We are playing the Guess Game.The game is as follows :
//
//I pick a number from 1 to n.You have to guess which number I picked.
//
//Every time you guess wrong, I'll tell you whether the number is higher or lower.
//
//You call a pre - defined API guess(int num) which returns 3 possible results(-1, 1, or 0) :
//
//	-1 : My number is lower
//	1 : My number is higher
//	0 : Congrats!You got it!
//	Example :
//	n = 10, I pick 6.
//
//	Return 6.


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

int guess(int num);


class Test {
public:
	int guessNumber(int n) {

		int start = 1;
		int end = n;
		while (start <= end)
		{
			int mid = start + (end - start) / 2;
			int result = guess(mid);
			if (result == 0)
			{
				return mid;
			}
			else if (result == 1)
			{
				start = mid + 1;
			}
			else
			{
				end = mid - 1;

			}
		}
		return -1;
	}
};

class Solution {
public:
	int guessNumber(int n) {

		//simple binary search : low = 1; high = n
		int low = 1;
		while (low <= n) {
			int mid = low + (n - low) / 2;
			int res = guess(mid);
			if (res == 0)
				return mid;
			else if (res == -1) // be careful about who is lower. 
				n = mid - 1;
			else
				low = mid + 1;
		}
		return -1; //be careful about the return value. 

	}
};		

int main()
{
	vector<int>numbers{ 1,3,5,6 };
	int x = 5;


	Solution question;
	question.guessNumber(x);
	Test question2;
	question2.guessNumber(x);

	return 0;
}