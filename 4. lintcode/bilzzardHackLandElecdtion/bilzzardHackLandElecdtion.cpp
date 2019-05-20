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
    string electionWinner(vector<string> votes) {
        unordered_map<string, int> result;

        for (int i = 0; i < votes.size(); i++) {
            if (result.find(votes[i]) == result.end()) {
                result[votes[i]] = 1;
            }
            else {
                result[votes[i]]++;
            }
        }

        string winner = "0";
        int max = 0;
        for (auto r : result) {
            if (r.second >= max) {
                if (r.first.compare(winner) > 0) {
                    max = r.second;
                    winner = r.first;
                }
            }
        }
        return winner;
    }  
};

class Solution {
public:
    string electionWinner(vector<string> votes) {
        unordered_map<string, int> result;
        string winner = "0";
        int max = 0;
        for (int i = 0; i < votes.size(); i++) {     
            result[votes[i]] ++;
            if (result[votes[i]] > max) {
                max = result[votes[i]];
                winner = votes[i];              
            }   
            else if (result[votes[i]] == max) {
                if (votes[i] > winner) {
                    winner = votes[i];
                }
            }
        }  
        return winner;
    }
};


int main()
{

    Solution question;
    //vector<string> values({ {"Alex"},{"Michael"},{"Harry"},{"Dave"},{"Michael"},{"Victor"},{"Harry"},{"Alex"},{"Mary"},{"Mary"} });
    vector<string> values({ {"Alice"},{"Allison"},{"Alice"},{"Allison"},{"Ashley"},{"Ashley"}});
    //vector<string> values({ {"Victor"},{"Veronica"},{"Ryan"},{"Dave"},{"Maria"},{"Maria"},{"Farah"},{"Farah"},{"Ryan"},{"Veronica"} });

    question.electionWinner(values);
    return 0;
}