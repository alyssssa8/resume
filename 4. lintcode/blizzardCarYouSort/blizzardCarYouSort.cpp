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
class Solution3 {
public:
    void customSort(vector<int> arr) {
        // sort(arr.begin(), arr.end());
        map<int, int> freq;
        vector<int> data;
        for (int c : arr) {
            freq[c]++;
        }
        for (int i = 0; i < freq.size(); i++) {
            if ((freq[i] != 0) && (find(data.begin(), data.end(), freq[i]) == data.end())) {
                data.push_back(freq[i]);
            }
        }
        sort(data.begin(), data.end());
        for (auto i : data) {
            for (auto j = freq.begin(); j != freq.end();) {
                if (j->second == i) {
                    for (int k = 0; k < i; k++) {
                        cout << j->first << endl;
                    }
                    j = freq.erase(j);
                }
                else {
                    j++;
                }
            }
        }
        return;
    }

};

class Solution {
public:
    void customSort(vector<int> arr) {
       // sort(arr.begin(), arr.end());
        map<int, int> freq;
        vector<int> data;
        for (int c : arr) {
            freq[c]++;
        }
        for (int i = 0; i < freq.size(); i++) {
            if ((freq[i] != 0) && (find(data.begin(), data.end(), freq[i]) == data.end())) {
                //cout << freq[i] << endl;
                data.push_back(freq[i]);
            }
        }
       sort(data.begin(), data.end());
        for (auto i : data) {
            //for (auto j = freq.begin(); j != freq.end();) {
            for (auto& j : freq) {
                if (j.second == i) {
                    for (int k = 0; k < i; k++) {
                        cout << j.first << endl;
                    }
                    //j = freq.erase(&j);
                }
                /*else {
                    j++;
                }*/
            }
        }
        return;
    }

};

class Solution2 {
public:
    void customSort(vector<int> s) {
        unordered_map<int, int> freq;
        vector<vector<int>> bucket(s.size());
        for (int i = 0; i < s.size(); i++) {
            freq[s[i]]++;
        }
        for (auto& it : freq) {
            int n = it.second;
            int c = it.first;
            bucket[n].push_back(c);
        }
        for (int i = 0; i<bucket.size(); i++) {     
            for (int j = 0; j < bucket[i].size(); j++){
                for (int k = 0; k <i;k++) {                 
                    cout << bucket[i][j];
                }                 
            }
        }
        return ;
       
    }

};
int main()
{
    //vector<int>nums({ 3, 1, 2, 2, 4 }); //1 3 4 22
    //vector<int>nums({ 4, 5, 6, 5, 4, 3 }); ////3 6 44 55
    vector<int>nums({ 4, 3, 5, 6, 5, 4, 3, 5, 5, 8 }); ////6 8 33 44 5555 

    Solution question;
    question.customSort(nums);
    return 0;
}