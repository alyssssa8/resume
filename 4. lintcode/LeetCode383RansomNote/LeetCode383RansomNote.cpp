//https://leetcode.com/problems/ransom-note/description/
//Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines; otherwise, it will return false.
//
//Each letter in the magazine string can only be used once in your ransom note.
//
//Note:
//You may assume that both strings contain only lowercase letters.
//
//canConstruct("a", "b") -> false
//canConstruct("aa", "ab") -> false
//canConstruct("aa", "aab") -> true



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

//33.75%
class Solution3 {
public:
	bool canConstruct(string ransomNote, string magazine) {
		map <char, int> myMap;

		for (int j = 0; j < magazine.size(); j++) {
			myMap[magazine[j]] += 1;
		}
		for (int k = 0; k < ransomNote.size(); k++) {
			if (myMap.find(ransomNote[k]) != myMap.end() && (myMap.find(ransomNote[k])->second > 0)) { // can not change it to .second. 
				myMap[ransomNote[k]] -= 1;
			}
			else {
				return false;
			}
		}
		return true;
	}
};
//73.02%
class Solution4 {
public:
	bool canConstruct(string ransomNote, string magazine) {
		bool found = true;
		for (int i = 0; i < ransomNote.size(); i++)
		{
			auto found = magazine.find(ransomNote[i]);
			if (found == std::string::npos)
			{
				return false;
			}
			magazine.erase(magazine.begin() + found);
		}
		return true;
	}
};

class Solution2 {
public:
	bool canConstruct(string ransomNote, string magazine) {
		map<char, int>myMap;
		for (int i = 0; i < magazine.size(); i++) {
			myMap[magazine[i]]++;
		}
		for (int i = 0; i < ransomNote.size(); i++) {
			myMap[ransomNote[i]]--;
			if (myMap[ransomNote[i]] < 0) {
				return false;
			}

		}
		return true;
	}
};
class Solution5 {
public:
	bool canConstruct(string ransomNote, string magazine) {
		int list[256] = { 0 };
		for (int i = 0; i < magazine.size(); i++) {
			list[magazine[i]]++;
		}
		for (int i = 0; i < ransomNote.size(); i++) {
			list[ransomNote[i]]--;
			if (list[ransomNote[i]] < 0) {
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
	question.canConstruct("bg","efjbdfbdgfjhhaiigfhbaejahgfbbgbjagbddfgdiaigdadhcfcj");
	Solution2 question2;
	question2.canConstruct("aa", "aab");

	return 0;
}
