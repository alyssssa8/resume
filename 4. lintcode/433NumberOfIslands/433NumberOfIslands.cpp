//https://leetcode.com/problems/number-of-islands/description/
//https://www.jiuzhang.com/solution/number-of-islands/
//http://www.lintcode.com/en/problem/number-of-islands/
//
//Given a 2d grid map of '1's(land) and '0's(water), count the number of islands.An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.You may assume all four edges of the grid are all surrounded by water.
//
//Example 1 :
//
//    11110
//    11010
//    11000
//    00000
//    Answer : 1
//
//    Example 2 :
//
//    11000
//    11000
//    00100
//    00011


#include <iostream>
#include <math.h>
#include <algorithm> 
#include<vector>
#include<string>
#include <queue>
#include <stack>
#include <list>
#include <map>   //hash table

using namespace std;
int numIslands(vector<vector<char>>& grid);
void dfs(vector<vector<char>>& grid, int x, int y);

class Solution {
private:
	int ans = 0;
public:
	int numIslands(vector<vector<char>>& grid) {

		int row = grid.size();
		if (row == 0)
		{
			return ans;
		}
		int col = grid[0].size();

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (grid[i][j] == '1')
				{
					ans++;
					dfs(i, j, grid);
				}
				
			}
		}
		return ans;
	}

	void dfs(int row, int col, vector < vector<char>> & grid)
	{
		if (row >= grid.size() || col >= grid[0].size() || row < 0 || col < 0 || grid[row][col] == '0')
		{
			return;
		}	
		grid[row][col] = '0';

		dfs(row + 1, col, grid);
		dfs(row - 1, col, grid);
		dfs(row, col + 1, grid);
		dfs(row, col - 1, grid);

		

	}

};
int main()
{
    vector<vector<char>> grid({ { '1','1','0','0','0' }, { '1','1','0','0','0' }, { '0','0','1','0','0' }, {'0','0','0','1','1'} });

    vector<vector<char>>::iterator iter;
    vector<char>::iterator iter2;
    for (iter = grid.begin(); iter != grid.end(); iter++)
    {
        for (iter2 = iter->begin(); iter2 != iter->end(); iter2++)
        {
            cout << *iter2 << endl; // if vector is a struct, (*iter).member or iter->member
        }
        cout << "_______________________" << endl;
       
    }

  
    numIslands(grid);
    return 0;
}

int numIslands(vector<vector<char>>& grid)
{

    
        if (grid.empty())
        {
            return 0;
        }
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for (int y = 0; y < m; ++y)
            for (int x = 0; x < n; ++x) {
                cout << "x = " << x << "  y = " << y << " ans " << ans << " grid[[y][x] " << grid[y][x] << endl;
                cout << "_____________________" << endl;
                if (grid[y][x] == '1')
                {
                    
                    ans++;

                }
                dfs(grid, x, y);
            }
        return ans;
 }


void dfs(vector<vector<char>>& grid, int x, int y) {
    if (x < 0 || y < 0 || x >= grid[0].size() || y >= grid.size() || grid[y][x] == '0')
        return;
    grid[y][x] = '0';
    dfs(grid, x + 1, y);
    dfs(grid, x - 1, y);
    dfs(grid, x, y + 1);
    dfs(grid, x, y - 1);
}
