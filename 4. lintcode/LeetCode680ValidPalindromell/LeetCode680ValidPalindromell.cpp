

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
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;
        while (i < j) {
            if (s[i] != s[j]) {
                return isp(s, i + 1, j) || isp(s, i, j - 1);
            }
            j--;
            i++;
        }
        return true;
    }

private:
    bool isp(string s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};



class Solution {
public:
    bool validPalindrome(string s) {
        int lo = 0, hi = s.size() - 1;
        return validPalindrome(s, lo, hi, 0);
    }

    bool validPalindrome(string &s, int lo, int hi, int count) {
        if (count > 1) return false;
        while (lo < hi) {
            if (s[lo] == s[hi]) {
                lo++; hi--;
            }
            else {
                return validPalindrome(s, lo + 1, hi, count + 1) ||
                    validPalindrome(s, lo, hi - 1, count + 1);
            }
        }
        return true;
    }
};


int main()
{

    vector<int>nums({ -15, -6, 8, 10 ,60 });
    Solution question;
    question.validPalindrome("ebcbbececabbacecbbcbe");
   /* Solution2 question2;
    question2.validPalindrome(nums);*/

    return 0;
}

