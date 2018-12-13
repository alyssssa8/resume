

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
#include<unordered_set>
using namespace std;
class Solution2 {
public:
    vector<string> findWords(vector<string>& words) {

        std::unordered_set<char>  dict1 = { 'q','Q','w','W','e','E','r','R','t','T','y','Y','u','U','i','I','o','O','p','P' };
        std::unordered_set<char>  dict2 = { 'a','A','s','S','d','D','f','F','g','G','h','H','j','J','k','K','l','L' };
        std::unordered_set<char>  dict3 = { 'z','Z','x','X','c','C','v','V','b','B','n','N','m','M' };

        vector<string> res;

        for (string word : words) {
            bool d1 = true, d2 = true, d3 = true;
            for (char ch : word) { // changed auto to type
                if (d1 == true) {
                    std::unordered_set<char>::iterator it = dict1.find(ch);
                    if (it == dict1.end()) {
                        d1 = false;
                    }
                }
                if (d2 == true) {
                    auto it = dict2.find(ch);
                    if (it == dict2.end()) {
                        d2 = false;
                    }
                }
                if (d3 == true) {
                    auto it = dict3.find(ch);
                    if (it == dict3.end()) {
                        d3 = false;
                    }
                }

            }
            if (d1 || d2 || d3) {
                res.push_back(word);
            }

        }
        return res;


    }
};

class Solution {
public:
    vector<string> findWords(vector<string>& words){

        unordered_set<char>  dict1 = { 'q','Q','w','W','e','E','r','R','t','T','y','Y','u','U','i','I','o','O','p','P' };
        unordered_set<char>  dict2 = { 'a','A','s','S','d','D','f','F','g','G','h','H','j','J','k','K','l','L' };
        unordered_set<char>  dict3 = { 'z','Z','x','X','c','C','v','V','b','B','n','N','m','M' };

        vector<string> res;

        for (auto &word : words)
        {
            bool d1 = true, d2 = true, d3 = true;

            for (auto & ch : word)
            {
                if (d1) {
                    auto it = dict1.find(ch);
                    if (it == dict1.end()) d1 = false;
                }

                if (d2) {
                    auto it = dict2.find(ch);
                    if (it == dict2.end()) d2 = false;
                }

                if (d3) {
                    auto it = dict3.find(ch);
                    if (it == dict3.end()) d3 = false;
                }
            }

            if (d1 || d2 || d3) res.push_back(word);
        }

        return res;


    }
};


int main()
{

    vector<string>nums({"dfd", "dfd"});
    Solution question;
    question.findWords(nums);
    Solution question2;
    question2.findWords(nums);

    return 0;
}