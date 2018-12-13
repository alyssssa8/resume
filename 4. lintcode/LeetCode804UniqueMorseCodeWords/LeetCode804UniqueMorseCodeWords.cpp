
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
#include<unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> container = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
        unordered_set<string> ans;
        for (int i = 0; i < words.size(); i++) {
            string temp = "";
            for (int j = 0; j < words[i].size(); j++) {
                temp += container[words[i][j] - 'a'];
            }
            ans.insert(temp);
        }
        return ans.size();
    }
};


int main()
{

    vector<string>nums({ "gin", "zen", "gig", "msg" });
    Solution question;
    question.uniqueMorseRepresentations(nums);
    //Solution2 question2;
    //question2.uniqueMorseRepresentations(nums);

    return 0;
}