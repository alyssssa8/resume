//https://leetcode.com/problems/isomorphic-strings/description/
//
//
//Given two strings s and t, determine if they are isomorphic.
//
//Two strings are isomorphic if the characters in s can be replaced to get t.
//
//All occurrences of a character must be replaced with another character while preserving the order of characters.No two characters may map to the same character but a character may map to itself.
//
//Example 1:
//
//Input: s = "egg", t = "add"
//	Output : true
//	Example 2 :
//
//	Input : s = "foo", t = "bar"
//	Output : false
//	Example 3 :
//
//	Input : s = "paper", t = "title"
//	Output : true
//	Note :
//	You may assume both s and t have the same length.



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
	bool isIsomorphic(string s, string t) {

		unordered_map<char, char>mp1, mp2;
		for (int i = 0; i < s.size(); i++) {
			if ((mp1[s[i]] && mp1[s[i]] != t[i]) || (mp2[t[i]] && mp2[t[i]] != s[i])) {
				return false;
			}
			cout << "t[i]: " << t[i] << " s[i]:" << s[i] << endl;
			mp1[s[i]] = t[i]; // if t[i] is empty, they it is equal to 0;
			mp2[t[i]] = s[i];
			cout << mp1[s[i]] << mp2[t[i]] << endl;
		}
		return true;
	}
};

class Solution {
public:
	// 's' has a mapping "to" 't' and is stored in the "to" charmap.
	// 't' has a mapping "from" 's' and is stored in the "from" charmap.
	// If s[i] has not been mapped to anything yet, just map it to t[i].
	// If there already exists a mapping s[i] "to" t[somethingElse] and NOT t[i], return false.
	// If t[i] doesn't have a mapping from anything yet, just map it from s[i].
	// If there already exists a mapping t[i] "from" s[somethingElse] and NOT s[i], return false.
	bool isIsomorphic(string s, string t) {
		char from[256],      to[256] = { -1 },                test3[256] = { 'a' };
		//default:-52| '?'	first index: -1 |'?', rest:0			  first index:97| 'a', rest:0
		int test[256] = { 0 }; // all 0's
		int test2[256] = { 1 };//first index: 1, rest: 0
		int test4[256]; //default value, 
		string test6[256]; //""
		string test7[256] = { "" };//""
		string test8[256] = { " " };//first index:" ", rest:""
		int len = s.size();

		for (int i = 0; i < len; i++) {
			if (to[s[i]] > 0 && to[s[i]] != t[i] || from[t[i]] > 0 && from[t[i]] != s[i]) {
				return false;
			}
			to[s[i]] = t[i];     // It's OK to overwite if an identical mapping existed already.       
			from[t[i]] = s[i];
		}
		return true;
	}
};

int main()
{

	string nums1 = "ge";
	string nums2 = "";
	Solution question;
	question.isIsomorphic(nums1, nums2);
	Solution question2;
	question2.isIsomorphic(nums1, nums2);

	return 0;
}
