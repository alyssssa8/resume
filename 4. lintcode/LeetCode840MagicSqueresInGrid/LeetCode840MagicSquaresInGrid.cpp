//https://leetcode.com/problems/magic-squares-in-grid/description/
//A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.
//
//Given an grid of integers, how many 3 x 3 "magic square" subgrids are there ? (Each subgrid is contiguous).
//
//
//
//Example 1 :
//
//	Input : [[4, 3, 8, 4],
//	[9, 5, 1, 9],
//	[2, 7, 6, 2]]
//	Output : 1
//	Explanation :
//	The following subgrid is a 3 x 3 magic square :
//438
//951
//276
//
//while this one is not:
//	384
//	519
//	762
//
//	In total, there is only one magic square inside the given grid.
//	Note :
//
//	1 <= grid.length <= 10
//	1 <= grid[0].length <= 10
//	0 <= grid[i][j] <= 15
//


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
	int numMagicSquaresInside(vector<vector<int>>& grid) {



	}
};


int main()
{

	vector<vector<int>>nums({ { 1, 1 ,0 },{ 1, 0, 1 },{ 0, 0, 0 } });
	Solution question;
	question.numMagicSquaresInside(nums);
	Solution question2;
	question2.numMagicSquaresInside(nums);

	return 0;
}