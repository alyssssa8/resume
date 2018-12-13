
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
    string toLowerCase(string str) {
        string ans = "";
        for (int i = 0; i < str.length(); i++) {
            if (str[i] <= 'Z' && str[i] >= 'A') {
                ans += str[i] - 'A' + 'a';
            }
            else {
                ans += str[i];
            }

        }
        return ans;
    }
};

int main()
{

    vector<int>nums({ 3, 1 ,0 });
    Solution question;
    question.toLowerCase("Hello");
   // Solution2 question2;
   // question2.sortedArrayToBST(nums);

    return 0;
}