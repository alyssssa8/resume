//https://leetcode.com/problems/word-pattern/description/
//
//Given a pattern and a string str, find if str follows the same pattern.
//
//Here follow means a full match, such that there is a bijection between a letter in pattern and a non - empty word in str.
//
//Example 1:
//
//Input: pattern = "abba", str = "dog cat cat dog"
//	Output : true
//	Example 2 :
//
//	Input : pattern = "abba", str = "dog cat cat fish"
//	Output : false
//	Example 3 :
//
//	Input : pattern = "aaaa", str = "dog cat cat dog"
//	Output : false
//	Example 4 :
//
//	Input : pattern = "abba", str = "dog dog dog dog"
//	Output : false
//	Notes :
//	You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.



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
#include<set>
using namespace std;


class Solution3 {
public:
	bool wordPattern(string pattern, string str) {
		vector<string>words;
		map<string, char>myMapString;
		map<char, string>myMapChar;

		int begin = 0;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == ' ') {
				words.push_back(str.substr(begin, i - begin));
				begin = i + 1;
			}
		}
		words.push_back(str.substr(begin, str.size() - begin));
		if (words.size() != pattern.size()) {
			return false;
		}
		for (int i = 0; i < pattern.size(); i++) {
			if (myMapString.find(words[i]) == myMapString.end() && myMapChar.find(pattern[i]) == myMapChar.end()) {
				myMapString[words[i]] = pattern[i];
				myMapChar[pattern[i]] = words[i];
			}
			else if (myMapString[words[i]] != pattern[i] || myMapChar[pattern[i]] != words[i]) {
				return false;
			}
		}
		return true;


	}
};

//"abba"
//"dog dog dog dog"
class Solution2 {
public:
	bool wordPattern(string pattern, string str) {
		vector<string> words;
		int begin = 0;
		//int count=pattern-1;
		//get each word. 
		for (int i = 0; i<str.size(); i++) {
			if (str[i] == ' ') {
				words.push_back(str.substr(begin, i - begin));
				begin = i + 1;
			}
		}
		// for the last word
		words.push_back(str.substr(begin, str.size() - begin));
		unordered_map<char, string> myMap;
		set<string> sm;  // int list[256] or vector, list["abc] does not work. 
		if (words.size() != pattern.size()) {
			return false;
		}
		for (int i = 0; i<pattern.size(); i++) {
			//if not in myMap and not in sm , then insert the value.  
			if (myMap.find(pattern[i]) == myMap.end() && sm.find(words[i]) == sm.end()) {
				myMap[pattern[i]] = words[i];
				sm.insert(words[i]);
			}
			// if in sm but not in myMap, return false
			else if (myMap.find(pattern[i]) == myMap.end() && sm.find(words[i]) != sm.end()) {
				return false;
			}
			// if not equal, return false or find it in the myMap. 
			else if (myMap[pattern[i]] != words[i]) {
				return false;
			}
		}
		return true;
	}
};


class Solution {
public:
	bool wordPattern(string pattern, string str) {
		vector<string> words;
		int begin = 0;

		for (int i = 0; i<str.size(); i++) {
			if (str[i] == ' ') {
				words.push_back(str.substr(begin, i - begin));
				begin = i + 1;
			}
		}
		// for the last word
		words.push_back(str.substr(begin, str.size() - begin));
		string myMap[256];
		set<string> sm;  // int list[256] or vector, list["abc] does not work. 
		if (words.size() != pattern.size()) {
			return false;
		}
		for (int i = 0; i<pattern.size(); i++) {
			//if not in myMap and not in sm , then insert the value.  
			if (myMap[pattern[i]] == "" && sm.find(words[i]) == sm.end()) {
				myMap[pattern[i]] = words[i];
				sm.insert(words[i]);
			}
			// if in sm but not in myMap, return false
			else if (myMap[pattern[i]] == "" && sm.find(words[i]) != sm.end()) {
				return false;
			}
			// if not equal, return false or find it in the myMap. 
			else if (/*myMap[pattern[i]] != "" &&*/ myMap[pattern[i]] != words[i]) { // comment part is default. 
				return false;
			}
		}
		return true;
	}
};


int main()
{

	vector<int>nums({ 3, 1 ,0 });
	
	Solution question;
	question.wordPattern("abba", "dog cat cat dog");
	Solution question2;
	question2.wordPattern("abba", "dog cat cat dog");

	return 0;
}



