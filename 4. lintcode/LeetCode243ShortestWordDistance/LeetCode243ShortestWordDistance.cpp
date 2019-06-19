//243. Shortest Word Distance
//Easy
//
//264
//
//26
//
//Favorite
//
//Share
//Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.
//
//Example:
//Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
//
//Input : word1 = “coding”, word2 = “practice”
//    Output : 3
//    Input : word1 = "makes", word2 = "coding"
//    Output : 1


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
#include<set>
using namespace std;

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int id1 = -1, id2 = -1;
        int minDist = INT_MAX;
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1) {
                id1 = i;
                if (id2 != -1) {
                    minDist = min(minDist, id1 - id2);
                }
            }
            else if (words[i] == word2) {
                id2 = i;
                if (id1 != -1) {
                    minDist = min(minDist, id2 - id1);
                }
            }
        }
        return minDist;
    }
};
int main()
{
    Solution question;
    vector<string> num1({ "practice", "makes", "perfect", "coding", "makes" });
    
    question.shortestDistance(num1, "practice","coding");
    return 0;
}

