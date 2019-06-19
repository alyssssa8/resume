

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
    bool isPalindrome(string s) {
        int start = 0, end = s.size() - 1;
        while (start < end)
        {
            if (!isalnum(s[start])) ++start; // skip non alphanumerical characters
            else if (!isalnum(s[end])) --end;
            else if (tolower(s[start]) != tolower(s[end])) return false; // return false when nonequal is found
            else {
                start++;
                end--;
            }
        }
        return true;
    }
};

int main()
{


    vector<int>nums1({ 0 });
    vector<int>nums2({ 1 });
    Solution question;
    question.isPalindrome("A man, a plan, a canal: Panama");
    /*   Solution question2;
       question2.merge(250);*/
    return 0;
}