////https://leetcode.com/problems/excel-sheet-column-number/description/
////Given a column title as appear in an Excel sheet, return its corresponding column number.
////
////For example :
////
////A -> 1
////B -> 2
////C -> 3
////...
////Z -> 26
////AA -> 27
////AB -> 28
////...
////Example 1:
////
////Input: "A"
////	Output : 1
////	Example 2 :
////
////	Input : "AB"
////	Output : 28
////	Example 3 :
////
////	Input : "ZY"
////	Output : 7



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
	int titleToNumber(std::string s) {
		return s.size() == 0 ? 0 : 26 * titleToNumber(s.substr(0, s.size() - 1)) + s[s.size() - 1] - 'A' + 1;
	}
};



class Solution3 {
public:
	int titleToNumber(string s) {
		int res = 0;
		//for(auto c: s){
		for (int i = 0; i <s.size(); i++) {
			res *= 26;
			res += s[i] - 'A' + 1;//need to use two line, otherwize, will be over flow. 
		}
		return res;
	}
};
//Line 9: Char 19 : runtime error : signed integer overflow : 2147483624 + 87 cannot be represented in type 'int' (solution.cpp)
class Solution {
public:
	int titleToNumber(string s) {
		int ans = 0;
		for (int i = 0; i < s.size(); i++) {
			ans = ans * 26;
			ans = ans + s[i] - 'A' + 1;
		}
		return ans;
	}
};
int main()
{

	vector<int>nums({ 3, 1 ,0 });
	Solution question;
	question.titleToNumber("A");
	Solution2 question2;
	question2.titleToNumber("AB");

	return 0;
}
