//https://leetcode.com/problems/reverse-string/description/
//Write a function that takes a string as input and returns the string reversed.
//
//Example :
//	Given s = "hello", return "olleh".
//
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


class Solution2 {
public:
	string reverseString(string s) {
		int start = 0;
		int end = s.size() - 1;

		while (start < end) {
			swap(s[start], s[end]);
			start++;
			end--;
		}
		return s;
	}
};

/*
class Solution {  // in-place reverse;
public:
	string reverseString(string s) {
		string ans("");
		for (int i = 0; i < s.size(); i++) {
			ans = s[i] + ans;
		}
		return ans;
	}
};
*/
int main()
{

	//vector<int>nums({ 3, 1 ,0 });
	string nums = "A man, a plan, a canal: Panama";
	Solution2 question;
	question.reverseString(nums);
	Solution2 question2;
	question2.reverseString(nums);

	return 0;
}