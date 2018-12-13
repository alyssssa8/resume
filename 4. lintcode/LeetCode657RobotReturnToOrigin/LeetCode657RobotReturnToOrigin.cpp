
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
    bool judgeCircle(string moves) {
        map<char, int>myMap;
        for (int i = 0; i < moves.length(); i++) {
            myMap[moves[i]]++;
        }
        if (myMap['U'] == myMap['D'] && myMap['L'] == myMap['R']) {
            return true;
        }
        else {
            return false;
        }
    }
};


bool judgeCircle(string moves) {
    int x = 0, y = 0;
    for (char c : moves) {
        x += (c == 'R') - (c == 'L'), y += (c == 'U') - (c == 'D');
    }
    return x == 0 && y == 0;
}
class Solution {
public:
    bool judgeCircle(string moves) {
        int v = 0;
        int h = 0;
        for (char ch : moves) {
            switch (ch) {
            case 'U': v++; break;
            case 'D': v--; break;
            case 'R': h++; break;
            case 'L': h--; break;
            }
        }
        return v == 0 && h == 0;
    }
};

int main()
{

    vector<int>nums({ 3, 1 ,0 });
    Solution question;
    question.judgeCircle(nums);
    Solution2 question2;
    question2.sortedArrayToBST(nums);

    return 0;
}