//https://leetcode.com/problems/valid-anagram/description/
//Given two strings s and t, write a function to determine if t is an anagram of s.
//
//Example 1 :
//
//	Input : s = "anagram", t = "nagaram"
//	Output : true
//	Example 2 :
//
//	Input : s = "rat", t = "car"
//	Output : false
//	Note :
//	You may assume the string contains only lowercase alphabets.
//
//	Follow up :
//What if the inputs contain unicode characters ? How would you adapt your solution to such case ?






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
	bool isAnagram(string s, string t) {
		int c[256] = {};
		for (int i = 0; i < s.size(); i++) {
			c[s[i]]++; 
		}
		for (int i = 0; i < t.size(); i++) { 
			c[t[i]]--; 
		}
		for (int i = 0; i < 256; i++) {
			if (c[i]) { //c[i] != 0
				return false; 
			}
		}
		return true;
	}
};

// the number of letters are same. 
class Solution {
public:
	bool isAnagram(string s, string t) {
		map<char, int> myMap1;
		map<char, int> myMap2;
		if (s.size() != t.size()) {
			return false;
		}
		for (int i = 0; i <s.size(); i++) {
			myMap1[s[i]] += 1;
			myMap2[t[i]] += 1;

		}

		return myMap1 == myMap2;
	}
};


int main()
{

	vector<int>nums({ 3, 1 ,0 });
	Solution question;
	question.isAnagram("abc", "efg");
	Solution question2;
	question2.isAnagram("abc", "efg");

	return 0;
}