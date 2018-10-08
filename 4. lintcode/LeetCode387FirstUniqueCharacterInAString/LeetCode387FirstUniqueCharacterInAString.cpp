//https://leetcode.com/problems/first-unique-character-in-a-string/description/
//Given a string, find the first non - repeating character in it and return it's index. If it doesn't exist, return -1.
//
//Examples :
//
//	s = "leetcode"
//	return 0.
//
//	s = "loveleetcode",
//	return 2.
//	Note: You may assume the string contain only lowercase letters.



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

//98.02%
class Solution2 {
public:
	int firstUniqChar(string s) {
		int list[256] = { 0 };
		for (auto i : s)
			list[i] ++;
		for (int i = 0; i<s.length(); i++)
			if (list[s[i]] == 1) return i;
		return -1;
	}
};
//25.18%

class Solution {
public:
	int firstUniqChar(string s) {
		map<char, int>myMap;
		for (int i = 0; i < s.size(); i++) {
			myMap[s[i]]++;
		}

		int i = 0;
		while (i < s.size()) {
			if (myMap[s[i]] == 1) {
				return i;
			}
			i++;
		}
		return -1;
	}
};


int main()
{

	vector<int>nums({ 3, 1 ,0 });
	Solution question;
	question.firstUniqChar("dfsad");
	Solution question2;
	question2.firstUniqChar("dfs");

	return 0;
}
