//https://leetcode.com/problems/linked-list-cycle/description/
//https://www.youtube.com/watch?v=qckKEYP9bBA
//http://zxi.mytechroad.com/blog/leetcode/leetcode-21-merge-two-sorted-lists/
//Given a linked list, determine if it has a cycle in it.
//
//Follow up :
//Can you solve it without using extra space ?


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
#include <unordered_set>
#include <set>
using namespace std;



class Solution {
public:
    bool isAlienSorted(vector<string> words, string order) {
        int mapping[26];
        for (int i = 0; i < 26; i++)
            mapping[order[i] - 'a'] = i;
        for (string &w : words)
            for (char &c : w)
                c = mapping[c - 'a'];
        return is_sorted(words.begin(), words.end());
        // Returns true if the range [first,last) is sorted into ascending order.
    }
};



int main()
{

    

    vector<string> words({ "hello","leetcode" });
    Solution question;
    question.isAlienSorted(words, "hlabcdefgijkmnopqrstuvwxyz");


    return 0;
}