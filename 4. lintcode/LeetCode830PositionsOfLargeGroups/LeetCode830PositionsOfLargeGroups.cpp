//https://leetcode.com/problems/positions-of-large-groups/description/
//In a string S of lowercase letters, these letters form consecutive groups of the same character.
//
//For example, a string like S = "abbxxxxzyy" has the groups "a", "bb", "xxxx", "z" and "yy".
//
//Call a group large if it has 3 or more characters.We would like the starting and ending positions of every large group.
//
//The final answer should be in lexicographic order.
//
//
//
//Example 1:
//
//Input: "abbxxxxzzy"
//	Output : [[3, 6]]
//	Explanation : "xxxx" is the single large group with starting  3 and ending positions 6.
//	Example 2 :
//
//	Input : "abc"
//	Output : []
//	Explanation : We have "a", "b" and "c" but no large group.
//	Example 3 :
//
//	Input : "abcdddeeeeaabbbcd"
//	Output : [[3, 5], [6, 9], [12, 14]]
//
//
//	Note : 1 <= S.length <= 1000



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
	vector<vector<int>> largeGroupPositions(string S) {
		int start = 0;
		vector<vector<int>> ans;
		for (int i = 1; i <= S.size(); i++) {
			if (S[i] != S[i - 1] || i == S.size()) {
				if (i - start >= 3) {
					ans.push_back({ start,i - 1 });
				}
				start = i;
			}
		}
		return ans;

	}
};



class Solution {
public:
	vector<vector<int>> largeGroupPositions(string S) {
		vector<vector<int>> ans;
		int start = 0;
		for (int i = 0; i < S.size(); i++) {
			int count = 1;
			start = i;
			while (S[i] == S[i + 1] && i < S.size() - 1) {
				count++;
				i++;
			}
			if (count >= 3) {
				ans.push_back({ start, start + count-1 });
			}
		}
		return ans;
	}
};
int main()
{

	vector<int>nums({ 3, 1 ,0 });
	Solution question;
	question.largeGroupPositions("aaa");
	Solution question2;
	question2.largeGroupPositions("abc");

	return 0;
}
