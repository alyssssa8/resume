//https://leetcode.com/problems/longest-palindrome/description/
//Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.
//
//This is case sensitive, for example "Aa" is not considered a palindrome here.
//
//Note:
//	Assume the length of given string will not exceed 1, 010.
//
//		Example :
//
//		Input :
//		"abccccdd"
//
//		Output :
//		7
//
//		Explanation :
//		One longest palindrome that can be built is "dccaccd", whose length is 7.




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
#include <set>
using namespace std;
// use this one
class Solution {
public:
	int longestPalindrome(const string& s) {
		vector<int> freqs(128, 0);
		//int freqs[128] = { 0 }; //could use array. both will loop 128 times
		for (int i = 0; i < s.size(); i++) {
			freqs[s[i]]++;
		}

		int ans = 0;
		int odd = 0;
		for (const int freq : freqs) {  // could not use int "i = 0; i < s.size(); i++". for example,  ababa, will loop all the letters, will have repeatition. 
			int temp = 0;				// could not use set, only will have s, will not have the count. 		
			if (freq % 2 == 0) {
				temp = freq;
			}
			else {
				temp = freq - 1;
			}
			ans = ans + temp;
			// same as: ans += freq % 2 == 0 ? freq : freq - 1;
			// same as: ans += freq / 2 * 2;
			// same as: ans += ((freq >> 1) << 1);            
			// same as: ans += freq & (INT_MAX - 1);
			//ans += freq & (~1); // clear the last bit

		}

		if (ans < s.size()) {
			ans++;
		}

		return ans;
	}
};




class Solution2 {
public:
	int longestPalindrome(string s) {
		map<char, int> myMap;
		int count = 0;
		for (int i = 0; i < s.size(); i++) {
			myMap[s[i]]++;
			if (myMap[s[i]] == 2) {
				count += 2;
				myMap[s[i]] = 0;
			}
		}
		if (count < s.size()) {
			count++;
		}
		return count;
	}
};


int main()
{
	int temp[256] = { 0 };
	begin(temp);
	vector<int>nums({ 3, 1 ,0 });
	Solution question;
	question.longestPalindrome("abccccdd");
	//question.longestPalindrome("caba");
	Solution question2;
	question2.longestPalindrome("sdasd");

	return 0;
}
