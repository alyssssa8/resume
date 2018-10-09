//https://leetcode.com/problems/combination-sum-ii/description/
//http://www.lintcode.com/problem/combination-sum-ii/
//https://www.jiuzhang.com/solution/combination-sum-ii/
//http://www.goodtecher.com/leetcode-40-combination-sum-ii/
//http://zxi.mytechroad.com/blog/searching/leetcode-40-combination-sum-ii/


//Given a collection of candidate numbers(candidates) and a target number(target), find all unique combinations in candidates where the candidate numbers sums to target.
//
//Each number in candidates may only be used once in the combination.
//
//Note :
//
//    All numbers(including target) will be positive integers.
//    The solution set must not contain duplicate combinations.
//    Example 1 :
//
//    Input : candidates = [10, 1, 2, 7, 6, 1, 5], target = 8,
//    A solution set is :
//[
//    [1, 7],
//    [1, 2, 5],
//    [2, 6],
//    [1, 1, 6]
//]
//Example 2:
//
//Input: candidates = [2, 5, 2, 1, 2], target = 5,
//    A solution set is :
//       [
//           [1, 2, 2],
//           [5]
//       ]

#include <iostream>

#include <math.h>
#include <algorithm>
#include<vector>
#include<string>
#include <queue>
#include <stack>
#include <list>
#include <map>   //hash table
#include <vector>
using namespace std;

const int index_count = 10000;
vector<vector<int> > results;
vector<vector<int>> combinationSum(vector<int>& candidates, int target);
void dfs(vector<int>& candidates, int target, int s, vector<int>& cur, vector<vector<int>>& ans);
//void dfs(vector<int>& candidates, int target, int s, int d, int n, vector<int>& cur, vector<vector<int>>& ans);



class Solution {

private:
	vector<vector<int>> ans;
	vector<int>tempAns;
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		dfs(target, 0, candidates);
		return ans;

	}

	void dfs(int target, int depth, vector<int>& candidates)
	{
		if (target == 0)
		{
			ans.push_back(tempAns);
			return;
		}
		for (int i = depth; i < candidates.size(); i++)
		{
			if (candidates[i] > target)
			{
				return;
			}
			if (i > depth && candidates[i] == candidates[i - 1])
			{
				continue;
			}
			tempAns.push_back(candidates[i]);
			dfs(target - candidates[i], i + 1, candidates);
			tempAns.pop_back();
		}

	}
};

int main()
{
    int target = 8;
    vector<int> candidates({ 10, 1, 2, 7, 6, 1, 5 });
    vector<vector<int>> result = combinationSum(candidates, target);
    vector< vector<int> >::iterator row;
    vector<int>::iterator col;
    cout << "return result: " << endl;
    for (row = result.begin(); row != result.end(); row++) {
        for (col = row->begin(); col != row->end(); col++) {
            cout << *col;
        }
        cout << endl;
    }



    return 0;
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> cur;
    sort(candidates.begin(), candidates.end());


    vector<int>::iterator iter;
    for (iter = candidates.begin(); iter != candidates.end(); iter++) {

        cout << *iter << ",";
    }
    //cout << "  target: " << target << " s: " << 0 << "  d + 1: " << 0 << "  n:" << n << "  cur: ";
    cout << "  target: " << target << "  s:" << 0 << "  cur: ";

    for (iter = cur.begin(); iter != cur.end(); iter++) {

        cout << *iter << ",";
    }
    cout << "  ans: ";
    vector< vector<int> >::iterator row;
    vector<int>::iterator col;
    for (row = ans.begin(); row != ans.end(); row++) {
        for (col = row->begin(); col != row->end(); col++) {
            cout << *col;
        }
        //cout << endl;
    }
    cout << endl;

    dfs(candidates, target, 0, cur, ans);


    //}

    return ans;
}


//without ordering the output
void dfs(vector<int>& candidates, int target, int s, vector<int>& cur, vector<vector<int>>& ans)
{  //1,1,2,5,6,7,10
    if (target == 0) {
        ans.push_back(cur);
        return;
    }

    for (int i = s; i < candidates.size(); ++i)
    {

        vector<int>::iterator iter;
        cout << endl;        
        cout << "  target: " << target << "  i + 1: " << i << "  s:" << s;    
        vector< vector<int> >::iterator row;
        vector<int>::iterator col;
       
        int num = candidates[i];

        if (num > target)
        {
            return;
        }
        if (i > s && candidates[i] == candidates[i - 1])
        {
			cout << "___________________________________" << endl;
			cout << "i: " << i << endl;
			cout << "candidate [i]: " << candidates[i] << "  candidates[i-1]" << candidates[i - 1] << endl;
			cout << "___________________________________" << endl;

            continue;
        }

        cur.push_back(num);
        cout << " cur: ";
        for (iter = cur.begin(); iter != cur.end(); iter++) {

            cout << *iter << ",";
        }
        cout << "  ans: ";
        for (row = ans.begin(); row != ans.end(); row++) {
            for (col = row->begin(); col != row->end(); col++) {
                cout << *col;
            }
            cout << ",";
        }
        //cout << endl;
        //cout << endl;
        //1,1,2,5,6,7,10
        dfs(candidates, target - num, i + 1, cur, ans);
        cur.pop_back();
    }
}


/*
void dfs(const vector<int>& candidates, 
             int target, int s, 
             set<vector<int>>& ans,              
             vector<int>& curr) {
        if (target == 0) {
            ans.insert(curr);
            return;
        }
        
        for (int i = s; i < candidates.size(); ++i) {
            int num = candidates[i];

            if (num > target) 
			{
				return;
			}

            curr.push_back(num);
            dfs(candidates, target - num, i + 1, ans, curr);
            curr.pop_back();
        }
    }
*/


