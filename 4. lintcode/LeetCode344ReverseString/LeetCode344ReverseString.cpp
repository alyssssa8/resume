//https://leetcode.com/problems/reverse-string/description/
//Write a function that takes a string as input and returns the string reversed.
//
//Example :
//	Given s = "hello", return "olleh".
//
//



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


class Solution3 {
public:
    void reverseString(vector<char>& s) {
        int start = 0;
        int end = s.size() - 1;
        char temp;
        while (start < end) {
            temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start++;
            end--;
        }

    }
};


class Solution {
public:
    string reverseString(string s) {

        for (int i = 0, j = s.length() - 1; i <= (s.length() - 1) / 2; i++, j--) {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;

        }

        return s;
    }
};

class Solution2 {
public:
	string reverseString(string s) {
		int start = 0;
		int end = s.size() - 1;

		while (start < end) {
			swap(s[start], s[end]);
			start++;
			end--;
		}
		return s;
	}
};

/*
class Solution {  // in-place reverse;
public:
	string reverseString(string s) {
		string ans("");
		for (int i = 0; i < s.size(); i++) {
			ans = s[i] + ans;
		}
		return ans;
	}
};
*/
int main()
{

	//vector<int>nums({ 3, 1 ,0 });
	string nums = "ABCDEFGHIJK";
	Solution question;
	question.reverseString(nums);
	Solution2 question2;
	question2.reverseString(nums);

	return 0;
}