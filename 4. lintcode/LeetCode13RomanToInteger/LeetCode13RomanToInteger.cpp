
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
    int romanToInt(string s) {
        if (s.length() == 0) return 0;
        int result = 0, len = s.length(), i = len - 1;
        int prev = 0;
        while (i >= 0) {
            char curt = s[i];
            if (curt == 'I') {
                if (prev > 1)
                    result -= 1;
                else
                    result += 1;
                prev = 1;
            }
            else if (curt == 'V') {
                result += 5;
                prev = 5;
            }
            else if (curt == 'X') {
                if (prev > 10)
                    result -= 10;
                else
                    result += 10;
                prev = 10;
            }
            else if (curt == 'L') {
                result += 50;
                prev = 50;
            }
            else if (curt == 'C') {
                if (prev > 100)
                    result -= 100;
                else
                    result += 100;
                prev = 100;
            }
            else if (curt == 'D') {
                result += 500;
                prev = 500;
            }
            else if (curt == 'M') {
                result += 1000;
                prev = 1000;
            }
            --i;
        }
        return result;
    }
};

class Solution {
public:
    int romanToInt(string s) {
        int nums[128];
        nums['I'] = 1;
        nums['V'] = 5;
        nums['X'] = 10;
        nums['L'] = 50;
        nums['C'] = 100;
        nums['D'] = 500;
        nums['M'] = 1000;
        int result = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (i + 1 < s.size() && nums[s[i + 1]] > nums[s[i]])
                result -= nums[s[i]];
            else
                result += nums[s[i]];
        }
        return result;
    }
};


int main()
{
    vector<int>nums({ 3, 1 ,0 });
    Solution question;
    question.romanToInt("V");
    Solution2 question2;
    question2.romanToInt("IV");

    return 0;
}