//https://leetcode.com/problems/fizz-buzz/description/
//Write a program that outputs the string representation of numbers from 1 to n.
//
//But for multiples of three it should output ¡°Fizz¡± instead of the number and for the multiples of five output ¡°Buzz¡±.For numbers which are multiples of both three and five output ¡°FizzBuzz¡±.
//
//Example :
//
//	n = 15,
//
//	Return :
//	[
//		"1",
//		"2",
//		"Fizz",
//		"4",
//		"Buzz",
//		"Fizz",
//		"7",
//		"8",
//		"Fizz",
//		"Buzz",
//		"11",
//		"Fizz",
//		"13",
//		"14",
//		"FizzBuzz"
//	]




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


//100%
class Solution2 {
public:
	vector<string> fizzBuzz(int n) {
		vector<string> index(n);
		for (int i = 0; i<n; i++) {
			if ((i + 1) % 3 == 0) {
				index[i] += "Fizz";
			}
			if ((i + 1) % 5 == 0) {
				index[i] += "Buzz";
			}
			if (index[i].empty()) {// else will be of with if, not for 2 if.   if already have 3 or five , will not add to index[i]. 
				index[i] += to_string(i + 1);
			}
		}
		return index;

	}
};


class Solution {
public:
	vector<string> fizzBuzz(int n) {
		vector<string> ans;
		for (int i = 1; i <= n; i++) {
			if (i % 3 == 0 && i % 5 == 0) {
				ans.push_back("FizzBuzz");
			}
			else if (i % 3 == 0) {
				ans.push_back("Fizz");

			}
			else if (i % 5 == 0) {
				ans.push_back("Buzz");
			}
			else {
				ans.push_back(to_string(i));
			}

		}
		return ans;
	}
};


int main()
{

	vector<int>nums({ 3, 1 ,0 });
	Solution question;
	question.fizzBuzz(15);
	Solution2 question2;
	question2.fizzBuzz(6);

	return 0;
}
