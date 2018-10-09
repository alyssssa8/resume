//https://leetcode.com/problems/find-smallest-letter-greater-than-target/description/
//
//Given a list of sorted characters letters containing only lowercase letters, and given a target letter target, find the smallest element in the list that is larger than the given target.
//
//Letters also wrap around.For example, if the target is target = 'z' and letters = ['a', 'b'], the answer is 'a'.
//
//Examples :
//	Input :
//	letters = ["c", "f", "j"]
//	target = "a"
//	Output : "c"
//
//	Input :
//	letters = ["c", "f", "j"]
//	target = "c"
//	Output : "f"
//
//	Input :
//	letters = ["c", "f", "j"]
//	target = "d"
//	Output : "f"
//
//	Input :
//	letters = ["c", "f", "j"]
//	target = "g"
//	Output : "j"
//
//	Input :
//	letters = ["c", "f", "j"]
//	target = "j"
//	Output : "c"
//
//	Input :
//	letters = ["c", "f", "j"]
//	target = "k"
//	Output : "c"
//	Note :
//	letters has a length in range[2, 10000].
//	letters consists of lowercase letters, and contains at least 2 unique letters.
//	target is a lowercase letter.
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

class Test {
public:
	char nextGreatestLetter(vector<char>& letters, char target) {
		int start = 0;
		int end = letters.size() - 1;
		while (start <= end)
		{
			int mid = start + (end - start) / 2;
			if (letters[mid] <= target) //be careful, it is greater than, should be "<=" not "<"
			{
				start = mid + 1;
			}
			else
			{
				end = mid - 1;
			}
		}
		if (start >= letters.size())
		{
			return letters[0];
		}

		else
		{
			return letters[start];

		}

	}
};


class Solution {
public:
	char nextGreatestLetter(vector<char>& letters, char target) {
		int left, right;
		left = 0; right = letters.size();
		// search upper bound
		while (left < right)
		{
			int m = (left + right) / 2;

			char c = letters[m];
			if (target >= c)
				left = m + 1; // if target is equal to c, skip it.
			else
				right = m;
		}

		if (left >= letters.size()) // not found
		{
			return letters[0];
		}
		return letters[left]; //or right
	}
};

int main()
{
	vector<char> letters{ 'a','b','f' };
	char target = 'a';


	Solution question;
	question.nextGreatestLetter(letters,target);
	Test question2;
	question2.nextGreatestLetter(letters, target);
	return 0;
}