//https://leetcode.com/problems/number-of-segments-in-a-string/description/
//Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non - space characters.
//
//Please note that the string does not contain any non - printable characters.
//
//Example :
//
//	Input : "Hello, my name is John"
//	Output : 5


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
	int countSegments(string s) {

		int count = 0;
		for (int i = 0; i < s.size(); i++) {
			if (i != 0 && s[i] == ' ' &&s[i - 1] != ' ') { //if i = 1, ("a"), there is no s[1]
				count++;
			}
			if (i == s.size() - 1 && s[i] != ' ') {
				count++;
			}
		}
		return count;
	}
};

class Solution3 {
public:
	int countSegments(string s) {
		int output = 0;
		s += ' ';
		for (int i = 0; i<s.size(); i++)
		{
			if (s[i] != ' ' && s[i + 1] == ' ')
				output++;
		}
		return output;
	}
};

class Solution {
public:
	int countSegments(string s) {
		int count = 0;
		int i = 0;
		while (i < s.size()) {
			if (s[i] != ' ') {
				count++;			
				while (s[i] != ' ') {
					i++;
					if (i == s.size()) {
						break;
					}
				}
			}
			else {
				i++;
			}
		}
		return count;
	}
};
//own
class Solution {
public:
    int countSegments(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                while (s[i] != ' '&& i < s.size()) {
                    i++;
                }
                ans++;
            }
        }

        if (s[s.size() - 1] != ' ') {
            return ans++;
        }
        else {
            return ans;
        }
    }
};
int main()
{

	vector<int>nums({ 3, 1 ,0 });
	Solution question;
	question.countSegments("Hello, my name is John");
	Solution question2;
	question2.countSegments("nums");

	return 0;
}

