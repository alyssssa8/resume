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
    int projectionArea(vector<vector<int>>& grid) {

        int ans = 0;
        int deduct = 0;
        vector<int> maxRow(grid.size(), 0);
        vector<int> maxCol(grid[0].size(), 0);
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                maxRow[i] = max(maxRow[i], grid[i][j]);
                maxCol[j] = max(maxCol[j], grid[i][j]);
                if (grid[i][j] == 0) {
                    deduct++;
                }
            }
        }
        for (int i = 0; i < grid.size(); i++) {
            ans += maxRow[i];
        }
        for (int j = 0; j < grid[0].size(); j++) {
            ans += maxCol[j];
        }
        ans += grid.size()*grid[0].size() - deduct;
        return ans;
    }
};




int main()
{
    vector<vector<int>>grid = { {3, 0, 8, 4},{2, 4, 5, 7},{9, 2, 6, 3},{0, 3, 1, 0 } };

    vector<int>nums({ 3, 1 ,0 });
    Solution question;
    question.projectionArea(grid);
    Solution question2;
    question2.projectionArea(grid);

    return 0;
}