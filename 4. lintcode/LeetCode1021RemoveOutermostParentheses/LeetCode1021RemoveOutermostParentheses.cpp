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

//var removeOuterParentheses = function(S) {
//    var result = [];
//    var opened = 0;
//    var openIndex;
//    var closed = 0;
//    for (let i = 0; i < S.length; i++) {
//        if (S[i] == = "(") {
//
//            if (opened == = 0) {
//                openIndex = i + 1;
//            }
//            opened++;
//        }
//        else {
//            closed++;
//        }
//        if (opened == = closed) {
//            opened = 0;
//            closed = 0;
//            result.push(S.substring(openIndex, i));
//        }
//
//    }
//    return result.join("");
//
//};
class Solution {
public:
    string removeOuterParentheses(string S) {
        int open = 0;
        string ans = "";
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == '(') {
                open++;
                if (open != 1) {
                    ans += S[i];
                }
            }
            else {
                open--;
                if (open != 0) {
                    ans += S[i];
                }
            }
        }
        return ans;
    }
};

int main()
{

    vector<int>nums({ 3, 1 ,0 });
    Solution question;
    cout<<question.removeOuterParentheses("(()())(())");
    

    return 0;
}