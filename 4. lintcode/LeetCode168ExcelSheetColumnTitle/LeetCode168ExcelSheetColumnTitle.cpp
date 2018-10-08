//https://leetcode.com/problems/excel-sheet-column-title/description/
//Given a positive integer, return its corresponding column title as appear in an Excel sheet.
//
//For example :
//
//1->A
//2->B
//3->C
//...
//26->Z
//27->AA
//28->AB
//...
//Example 1:
//
//Input: 1
//	Output : "A"
//	Example 2 :
//
//	Input : 28
//	Output : "AB"
//	Example 3 :
//
//	Input : 701
//	Output : "ZY"


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
	string convertToTitle(int n) {

		//return n == 0 ? "" : convertToTitle(n / 26) + (char)(--n % 26 + 'A');
		if (n == 0) {
			return "";
		}
		else {
			return convertToTitle(n / 26) + char(--n % 26 + 'A');
		}

	}
};
class Solution3 {
public:
	string convertToTitle(int n) {
		string str("");
		while (n)
		{
			str = char((n - 1) % 26 + 'A') + str;
			n = (n - 1) / 26;
		}
		return str;
	}
};


class Solution2 {
public:
	string convertToTitle(int n) {
		 
		//return n == 0 ? "" : convertToTitle(n / 26) + (char)(--n % 26 + 'A');                            // if n = 27, next loop: n = 1, % 0||| next loop: n = 0, % 0. 
		return n == 0 ? "" : convertToTitle((n - 1) / 26) + (char) ((n - 1) % 26 + 'A');  // if n = 27, 27 - 1 = 26, next loop: n = 1, % 0||| next loop: n = 0, % 0


	}
};


int main()
{

	vector<int>nums({ 3, 1 ,0 });
	Solution question;
	question.convertToTitle(27);
	Solution2 question2;
	question2.convertToTitle(27);

	return 0;
}
