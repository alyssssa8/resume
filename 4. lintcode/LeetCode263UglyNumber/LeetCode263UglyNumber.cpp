//https://leetcode.com/problems/ugly-number/description/
//https://www.youtube.com/watch?v=1wpe7yeqZd0
//http://zxi.mytechroad.com/blog/math/leetcode-263-ugly-number/
//
//Write a program to check whether a given number is an ugly number.
//
//Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
//
//Example 1:
//
//Input: 6
//	Output : true
//	Explanation : 6 = 2 ¡Á 3
//	Example 2 :
//
//	Input : 8
//	Output : true
//	Explanation : 8 = 2 ¡Á 2 ¡Á 2
//	Example 3 :
//
//	Input : 14
//	Output : false
//	Explanation : 14 is not ugly since it includes another prime factor 7.
//	Note :
//
//	1 is typically treated as an ugly number.



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
	bool isUgly(int num) {

		vector<int> factors({ 2,3,5 });
		for (int i = 0; i < factors.size(); i++) {
			while (num && num % factors[i] == 0) { // num equal to num != 0.  0 % 2 = 0; so need to have num == true;
				num = num / factors[i];
			}
		}
		return num == 1;
	}

};

// Author: Huahua
// Running time: 9 ms
class Solution2 {
public:
	bool isUgly(int num) {
		const vector<int> factors{ 2, 3, 5 };
		for (const int factor : factors) {

			while (num && num % factor == 0) {
				num /= factor;
			}
		}
		return num == 1;
	}
};
int main()
{

	vector<int>nums({ 3, 1 ,0 });
	Solution question;
	question.isUgly(0);
	Solution question2;
	question2.isUgly(138);

	return 0;
}