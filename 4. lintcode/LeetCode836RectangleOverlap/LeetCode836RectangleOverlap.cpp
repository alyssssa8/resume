

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
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1 = rec1[0], y1 = rec1[1], x2 = rec1[2], y2 = rec1[3];
        int x3 = rec2[0], y3 = rec2[1], x4 = rec2[2], y4 = rec2[3];
        return (x1 < x4 && x3 < x2 && y1 < y4 && y3 < y2);
    }
};

int main()
{
    Solution question;
    vector<int> num1({ 0,0,2,2 });
    vector<int> num2({ 1,1,3,3 });
    question.isRectangleOverlap(num1, num2);  
    return 0;
}

