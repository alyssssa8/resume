//0,1,1,2,3,5,8,13,21,34,55,89,144
//				1
//			1	 2	  1
//		1     3     3      1
//	1      4	 6		4		1	

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
    int cap(vector<vector<char>>& b, int x, int y, int dx, int dy) {
        while (x >= 0 && x < b.size() && y >= 0 && y < b[x].size() && b[x][y] != 'B') {
            if (b[x][y] == 'p') {
                return 1;
            }
            x += dx, y += dy;
        }
        return 0;
    }
    int numRookCaptures(vector<vector<char>>& board) {
        for (auto i = 0; i < board.size(); ++i)
            for (auto j = 0; j < board[i].size(); ++j)
                if (board[i][j] == 'R') return cap(board, i, j, 0, 1) + cap(board, i, j, 0, -1) + cap(board, i, j, 1, 0) + cap(board, i, j, -1, 0);
        return 0;
    }

};
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int row = 0;
        int col = 0;
        int ans = 0;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'R') {
                    row = i;
                    col = j;
                    i = board.size();
                    j = board[0].size();
                }
            }
        }
        for (int j = col + 1; j < board[0].size(); j++) {
            if (board[row][j] == 'B') {
                break;
            }
            if (board[row][j] == 'p') {
                ans++;
                break;
            }
        }
        for (int j = col - 1; j >= 0; j--) {
            if (board[row][j] == 'B') {
                break;
            }
            if (board[row][j] == 'p') {
                ans++;
                break;
            }
        }
        for (int i = row + 1; i < board.size(); i++) {
            if (board[i][col] == 'B') {
                break;
            }
            if (board[i][col] == 'p') {
                ans++;
                break;
            }
        }
        for (int i = row - 1; i >= 0; i--) {
            if (board[i][col] == 'B') {
                break;
            }
            if (board[i][col] == 'p') {
                ans++;
                break;
            }
        }
        return ans;
    }
};


int main()
{

    vector<vector<char>>board({{ '.', '.' },{ '.', '.' } });
    vector<vector<int>>nums({ { 1, 1 ,0 },{1, 0, 1},{0, 0, 0} });
    Solution question;
    question.numRookCaptures(board);


    return 0;
}
