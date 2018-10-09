//https://leetcode.com/problems/flood-fill/description/
//https://www.youtube.com/watch?v=ln_mc5LtL5M
//http://zxi.mytechroad.com/blog/searching/leetcode-733-flood-fill/
//An image is represented by a 2 - D array of integers, each integer representing the pixel value of the image(from 0 to 65535).
//
//Given a coordinate(sr, sc) representing the starting pixel(row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.
//
//To perform a "flood fill", consider the starting pixel, plus any pixels connected 4 - directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4 - directionally to those pixels(also with the same color as the starting pixel), and so on.Replace the color of all of the aforementioned pixels with the newColor.
//
//At the end, return the modified image.
//
//Example 1:
//Input:
//image = [[1, 1, 1], [1, 1, 0], [1, 0, 1]]
//sr = 1, sc = 1, newColor = 2
//Output : [[2, 2, 2], [2, 2, 0], [2, 0, 1]]
//	Explanation :
//	From the center of the image(with position(sr, sc) = (1, 1)), all pixels connected
//	by a path of the same color as the starting pixel are colored with the new color.
//	Note the bottom corner is not colored 2, because it is not 4 - directionally connected
//	to the starting pixel.
//	Note :
//
//	The length of image and image[0] will be in the range[1, 50].
//	The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
//	The value of each color in image[i][j] and newColor will be an integer in[0, 65535].

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
private:


public:
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		if (image[sr][sc] == newColor) {
			return image;
		}
		dfs(image, sr, sc, newColor, image[sr][sc]);
		return image;
	}

	void dfs(vector<vector<int>> & image, int sr, int sc, int newColor, int oldColor) {
		if (sr >= 0 && sr < image.size() && sc >= 0 && sc < image[0].size() && image[sr][sc] == oldColor) { // new color == old color, will have infinite loop. 
			image[sr][sc] = newColor;
			dfs(image, sr + 1, sc, newColor, oldColor);
			dfs(image, sr - 1, sc, newColor, oldColor);
			dfs(image, sr, sc + 1, newColor, oldColor);
			dfs(image, sr, sc - 1, newColor, oldColor);
		}
		return;
	}
};
// Author: Huahua
// Runtime: 33 ms
class Solution2 {
public:
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		//if (image[sr][sc] == newColor) return image;
		int m = image.size();
		int n = image[0].size();
		floodFill(image, sc, sr, n, m, image[sr][sc], newColor);
		return image;
	}
private:
	void floodFill(vector<vector<int>>& image,
		int x, int y, int n, int m, int orgColor, int newColor) {
		if (x < 0 || x >= n || y < 0 || y >= m) return;
		if (image[y][x] != orgColor) return;

		image[y][x] = newColor;
		floodFill(image, x + 1, y, n, m, orgColor, newColor);
		floodFill(image, x - 1, y, n, m, orgColor, newColor);
		floodFill(image, x, y + 1, n, m, orgColor, newColor);
		floodFill(image, x, y - 1, n, m, orgColor, newColor);
	}
};
int main()
{
	vector < vector<int>>image{ {0,0,0},{0,1,1} };
	int sr = 1;
	int sc = 1;
	int newColor = 1;

	Solution question;
	question.floodFill(image, sr, sc, newColor);
	//Solution question2;
	//question2.maxAreaOfIsland(grid);

	return 0;
}