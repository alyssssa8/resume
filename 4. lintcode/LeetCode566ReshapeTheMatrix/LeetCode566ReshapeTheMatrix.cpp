//https://leetcode.com/problems/reshape-the-matrix/description/
//https://www.youtube.com/watch?v=tI8M9GO4Kvo
//
//n MATLAB, there is a very useful function called 'reshape', which can reshape a matrix into a new one with different size but keep its original data.
//
//You're given a matrix represented by a two-dimensional array, and two positive integers r and c representing the row number and column number of the wanted reshaped matrix, respectively.
//
//The reshaped matrix need to be filled with all the elements of the original matrix in the same row - traversing order as they were.
//
//If the 'reshape' operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.
//
//Example 1:
//Input:
//nums =
//[[1, 2],
//[3, 4]]
//r = 1, c = 4
//Output :
//	[[1, 2, 3, 4]]
//Explanation :
//	The row - traversing of nums is[1, 2, 3, 4].The new reshaped matrix is a 1 * 4 matrix, fill it row by row by using the previous list.
//	Example 2 :
//	Input :
//	nums =
//	[[1, 2],
//	[3, 4]]
//			r = 2, c = 4
//				Output :
//				[[1, 2],
//				[3, 4]]
//			Explanation :
//				There is no way to reshape a 2 * 2 matrix to a 2 * 4 matrix.So output the original matrix.
//				Note :
//				The height and width of the given matrix is in range[1, 100].
//				The given r and c are all positive.
















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

class Solution1 {
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
		vector<vector<int>> newMatrix(r, vector<int>(c, 0));
		int originalRaw = nums.size();
		int originalColumn = nums[0].size();
		if (originalRaw * originalColumn != r * c)
			return nums;

		int newRaw = 0, newColumn = 0;
		for (int i = 0; i < originalRaw; i++)
		{
			for (int j = 0; j < originalColumn; j++)
			{
				newMatrix[newRaw][newColumn] = nums[i][j];
				newColumn++;
				if (newColumn == c)
				{ 
					newColumn = 0;
					newRaw++;
				}
			}
		}
		return newMatrix;
	}
};

class Solution2 {
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
		int oldRow = nums.size(), oldCol = nums[0].size();
		if (r * c != oldRow * oldCol) {
			return nums;
		}

		vector<vector<int>> newMatrix(r, vector<int>(c, 0));
		for (int i = 0; i < oldRow * oldCol; i++) {
			newMatrix[i / c][i%c] = nums[i / oldCol][i%oldCol];
		}
		return newMatrix;
	}
};

class Solution3 {
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
	
	
		int oldR = nums.size();
		int oldC = nums[0].size();
		if (oldR == 0) return nums; // when the old matrix is empty, ¿ÕÊý×é
		if (oldR * oldC != r * c) return nums; // when old and new are not match
		//***
		vector<vector<int>> ans(r, vector<int>(c)); // important;


		int x = 0; int y = 0;
		for (int i = 0; i < oldR * oldC; i++) {
			int org_y = i / oldC; // it is divided by colomn. 
			int org_x = i % oldC;
			int new_y = i / c;
			int new_x = i % c;
			
			ans[new_y][new_x] = nums[org_y][org_x];
				
		}
		return ans;
	}
};


class Solution {
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
		if (nums.size() * nums[0].size() != r * c) {
			return nums;
		}
		int traverse = 0;
		vector<vector<int>> ans(r, vector<int>(c, 0));
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				ans[i][j] = nums[traverse / (nums[0].size())][traverse % (nums[0].size())];
				traverse++;
			}
		}
		return ans;

	}
};
int main()
{

	vector<vector<int>>nums({ { 1,2 }, {3,4} });
	int r = 1;
	int c = 4;
	Solution question;
	question.matrixReshape(nums,r, c);
	Solution question2;
	question2.matrixReshape(nums,c, r);

	return 0;
}

