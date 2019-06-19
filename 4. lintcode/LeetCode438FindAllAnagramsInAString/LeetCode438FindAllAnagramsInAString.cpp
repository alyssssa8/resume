//
//
//https://leetcode.com/problems/palindrome-linked-list/description/
//
//Given a singly linked list, determine if it is a palindrome.
//
//Example 1 :
//
//	Input : 1->2
//	Output : false
//	Example 2 :
//
//	Input : 1->2->2->1
//	Output : true
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



class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res, sc(26, 0), pc(26, 0);
        for (char c : p)
            pc[c - 'a']++;
        for (int i = 0, j = 0-p.size(); i < s.size(); i++, j = i - p.size()) {
            sc[s[i] - 'a']++;
            if (j >= 0)
                sc[s[j] - 'a']--;
            if (pc == sc)
                res.push_back(j + 1);
        }
        return res;
    }
};
int main()
{


  

    Solution question;
    question.findAnagrams("cbaebabacd","abc");
  /*  Solution2 question2;
    question2.isPalindrome(head);*/


    return 0;
}