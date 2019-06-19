

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
    int islandPerimeter(vector<vector<int>>& grid) {
        int count = 0, repeat = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    count++;
                    if (i != 0 && grid[i - 1][j] == 1) {
                        repeat++;
                    }
                    if (j != 0 && grid[i][j - 1] == 1) {
                        repeat++;
                    }
                }
            }
        }
        return 4 * count - repeat * 2;
    }
};


int main()
{
    vector<vector<int>>nums({ { 0, 1 ,0,0 }, {1,1,1,0} });
    Solution question;
    question.islandPerimeter(nums);
  
    return 0;
}
