//https://leetcode.com/problems/backspace-string-compare/description
//Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.
//
//Example 1:
//
//Input: S = "ab#c", T = "ad#c"
//	Output : true
//	Explanation : Both S and T become "ac".
//	Example 2 :
//
//	Input : S = "ab##", T = "c#d#"
//	Output : true
//	Explanation : Both S and T become "".
//	Example 3 :
//
//	Input : S = "a##c", T = "#a#c"
//	Output : true
//	Explanation : Both S and T become "c".
//	Example 4 :
//
//	Input : S = "a#c", T = "b"
//	Output : false
//	Explanation : S becomes "c" while T becomes "b".
//	Note :
//
//	1 <= S.length <= 200
//	1 <= T.length <= 200
//	S and T only contain lowercase letters and '#' characters.
//	Follow up :
//
//	   Can you solve it in O(N) time and O(1) space ?


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

class Solution6 {
public:
	bool backspaceCompare(string S, string T) {

		for (int i = S.length() - 1, j = T.length() - 1;; i--, j--)
		{
			for (int b = 0; i >= 0 && (b != 0 || S[i] == '#'); --i) {
				if (S[i] == '#') {
					b += 1;
				}
				else {
					b += -1;
				}
			}
			for (int b = 0; j >= 0 && (b != 0 || T[j] == '#'); --j) {
				b += T[j] == '#' ? 1 : -1;
			}

			if (i < 0 || j < 0 || S[i] != T[j]) {
				return i == -1 && j == -1;
			}
		}
	}
};

class Solution5 {
public:
	bool backspaceCompare(string S, string T) {

		int lens = S.size() - 1, lent = T.size() - 1, cou1 = 0, cou2 = 0;
		while (lens > -1 || lent > -1)
		{
			if (lens > -1 && S[lens] == '#') {
				cou1++, lens--;
				continue;
			}
			if (lent > -1 && T[lent] == '#') {
				cou2++, lent--;
				continue;
			}

			if (lens > -1 && cou1 != 0) {
				cou1--, lens--;
				continue;
			}
			if (lent > -1 && cou2 != 0) {
				cou2--, lent--;
				continue;
			}

			if (S[lens] != T[lent]) {//ab#c,#a#c
				return false;
			}
			lens--; lent--;
		}
		return true;
	}
};

class Solution4 {
public:
	bool backspaceCompare(string S, string T) {

		for (int i = S.length() - 1, j = T.length() - 1;; i--, j--)
		{
			for (int b = 0; i >= 0 && (b != 0 || S[i] == '#'); --i) {
				if (S[i] == '#') {
					b++;
				}
				else {
					b--;
				}
			}
			for (int b = 0; j >= 0 && (b != 0 || T[j] == '#'); --j) {
				if (T[j] == '#') {
					b++;
				}
				else {
					b--;
				}
			}

			if (i < 0 || j < 0 || S[i] != T[j]) {
				return i == -1 && j == -1;
			}
		}
	}
};

class Solution3 {
public:
	bool backspaceCompare(string S, string T) {

		for (int i = S.length() - 1, j = T.length() - 1;; i--, j--)
		{
			int count = 0;
			while (i >= 0 && (count != 0 || S[i] == '#')) {
				if (S[i] == '#') {
					count++;
				}
				else {
					count--;
				}
				i--;
			}
			count = 0;
			while (j >= 0 && (count != 0 || T[j] == '#')) {
				if (T[j] == '#') {
					count++;
				}
				else {
					count--;
				}
				j--;
			}

			if (i < 0 || j < 0 || S[i] != T[j]) {
				return i == -1 && j == -1;
			}
		}
	}
};

//ab#c,#a#c
//##b,b
class Solution2 {
public:
	bool backspaceCompare(string S, string T) {
		int i = S.size() - 1, j = T.size() - 1;
		while (true)
		{
			int count = 0;
			while (i >= 0 && (count != 0 || S[i] == '#')) {
				if (S[i] == '#') {
					count++;
				}
				else {
					count--;
				}
				i--;
			}
		
			while (j >= 0 && (count != 0 || T[j] == '#')) {
				if (T[j] == '#') {
					count++;
				}
				else {
					count--;
				}
				j--;
			}

			if (i < 0 || j < 0 || S[i] != T[j]) {
				return i == -1 && j == -1;
			}
			i--;
			j--;
		}
	}
};
// use this one!
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int count = 0;
        string first = "";
        string second = "";
        for (int i = S.size() - 1; i >= 0; i--) {
            if (S[i] == '#') {
                count++;
            }
            else if (S[i] != '#'&& count == 0) {
                first = S[i] + first;

            }
            else {
                count--;
            }
        }
        count = 0;
        for (int i = T.size() - 1; i >= 0; i--) {
            if (T[i] == '#') {
                count++;
            }
            else if (T[i] != '#'&& count == 0) {
                second = T[i] + second;

            }
            else {
                count--;
            }
        }
        return first == second;
    }
};
int main()
{

	//vector<int>nums({ 3, 1 ,0 });
	/*Solution question;
	question.backspaceCompare("xywrrmp","xywrrmu#p");*/
	Solution question2;
	bool res = question2.backspaceCompare("a##c","#a#c");

	return 0;
}


