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
    string frequencySort(string s) {

        unordered_map<char, int> freq;
        vector<string> bucket(s.size() + 1, "");
        string res;

        //count frequency of each character
        for (int i = 0; i < s.size(); i++) {
            freq[s[i]]++;
        }
        //put character into frequency bucket

        for (auto& it : freq) {
            int n = it.second;
            char c = it.first;
            bucket[n].append(n, c);
        }
        //form descending sorted string
        for (int i = s.size(); i > 0; i--) {
            if (!bucket[i].empty())
                res.append(bucket[i]);
        }
        return res;

    }
};
int main()
{
    //vector<int>nums({ 3, 1, 2, 2, 4 }); //1 3 4 22
    //vector<int>nums({ 4, 5, 6, 5, 4, 3 }); //3 6 44 55
    vector<int>nums({ 4, 3, 5, 6, 5, 4, 3, 5, 5, 8 });  //6 8 33 44 5555 

    Solution question;
    question.frequencySort("tree");
    return 0;
}