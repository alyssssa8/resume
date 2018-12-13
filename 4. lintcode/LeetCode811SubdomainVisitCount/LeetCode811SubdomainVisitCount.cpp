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
    vector<string> subdomainVisits(vector<string>& cpdomains)
    {
        unordered_map<string, int> m;

        for (const auto& word : cpdomains)
        {
            int i = word.find(" "); //same as ' '
            int n = stoi(word.substr(0, i));
            string s = word.substr(i + 1, word.size() - i - 1);

            for (int i = s.size() - 1; i >= 0; i--) {
                if (s[i] == '.') m[s.substr(i + 1, s.size() - i - 1)] += n;
                else if (i == 0) m[s.substr(i, s.size() - i)] += n;
            }
        }

        vector<string> v;
        for (const auto& e : m) v.push_back(to_string(e.second) + " " + e.first);
        return v;
    }
};
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string, int> c;
        for (auto cd : cpdomains) {
            int i = cd.find(" ");
            int n = stoi(cd.substr(0, i));
            string s = cd.substr(i + 1, cd.length() - 1 - i);
            for (int i = 0; i < s.length(); i++) {
                if (s[i] == '.') {
                    c[s.substr(i + 1, s.length() - i)] += n;
                }
            }
            c[s] += n;

        }
        vector<string> res;
        for (auto k : c) {
            res.push_back(to_string(k.second) + " " + k.first);
        }
        return res;
    }
};


int main()
{

    vector<string>nums({ "900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org" });
    Solution question;
    question.subdomainVisits(nums);
    Solution2 question2;
    question2.subdomainVisits(nums);

    return 0;
}
