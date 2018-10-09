//https://www.lintcode.com/problem/combination-sum/description
//https://leetcode.com/problems/combination-sum/description/
//https://www.jiuzhang.com/solution/combination-sum/
//https://www.youtube.com/watch?v=irFtGMLbf-s&t=232s
//https://www.youtube.com/watch?v=zIY2BWdsbFs
//Given a set of candidate numbers(candidates) (without duplicates) and a target number(target), find all unique combinations in candidates where the candidate numbers sums to target.
//
//The same repeated number may be chosen from candidates unlimited number of times.
//
//Note:
//
//All numbers(including target) will be positive integers.
//The solution set must not contain duplicate combinations.
//Example 1 :
//
//    Input : candidates = [2, 3, 6, 7], target = 7,
//    A solution set is :
//[
//    [7],
//    [2, 2, 3]
//]
//Example 2 :
//
//    Input : candidates = [2, 3, 5], target = 8,
//    A solution set is :
//[
//    [2, 2, 2, 2],
//    [2, 3, 3],
//    [3, 5]
//]


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
	vector<int> tempAns;
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

		sort(candidates.begin(), candidates.end());
		dfs(0, target, candidates);
		return ans;
	}

	void dfs(int depth, int target, vector<int >& candidates)
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
			tempAns.push_back(candidates[i]);
			dfs(i, target - candidates[i], candidates);
			tempAns.pop_back();
		}

	}
};
int main()
{
    int target = 7;
    vector<int> candidates({ 2, 3, 6, 7 });
    vector<vector<int>> result = combinationSum(candidates, target);
    vector< vector<int> >::iterator row;
    vector<int>::iterator col;
    cout << "return result: " << endl;
    for (row = result.begin(); row != result.end(); row++) {
        for (col = row->begin(); col != row->end(); col++) {
            cout << *col ;
        }
        cout << endl;
    }
 

	Solution question;
	question.combinationSum(candidates, target);
    return 0;
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> cur;
    sort(candidates.begin(), candidates.end());
    /*
    for (int n = 1; n <= target / candidates[0]; ++n)//target / candidates:7 / 2 = 3. for example: 2 2 2, lengh is 3, if 4, 2 2 2 2 = will more than 7
    {
        //print
        vector<int>::iterator iter;
        for (iter = candidates.begin(); iter != candidates.end(); iter++) {
            
            cout << *iter << ",";
        }
        //cout << "  target: " << target << " s: " << 0 << "  d + 1: " << 0 << "  n:" << n << "  cur: ";
        cout << "  target: " << target <<  "  n:" << n << "  cur: ";

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
        cout << "this is the inside dfs: " << endl;
        //__________________________________________________________________________________________
        dfs(candidates, target, 0, 0, n, cur, ans);
        */
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

//order the output
//s:start at which element
//d:depth 
//n:lenght

void dfs(vector<int>& candidates, int target, int s,int d, int n, vector<int>& cur, vector<vector<int>>& ans)
{
    if (d == n)
    {
        if (target == 0)
        {
            ans.push_back(cur);
            return;
        }
    }

    for (int i = s; i < candidates.size(); ++i) {
        if (candidates[i] > target)
        {
            break;
        }
        cur.push_back(candidates[i]);

        vector<int>::iterator iter;
        for (iter = candidates.begin(); iter != candidates.end(); iter++) {

            cout << *iter << ",";
        }
        cout << "  target: " << target <<" s: "<<i<<"  d + 1: "<< d + 1 << "  n:" << n << "  cur: ";

        for (iter = cur.begin(); iter != cur.end(); iter++) {

            cout << *iter << ",";
        }
        cout << "  ans: ";
        vector< vector<int> >::iterator row;
        vector<int>::iterator col;
        for (row = ans.begin(); row != ans.end(); row++) {
            for (col = row->begin(); col != row->end(); col++) {
                cout << *col<<" " ;
            }
            cout << ",";
        }
        cout << endl;

        dfs(candidates, target - candidates[i], i, d + 1, n, cur, ans);
        cur.pop_back();
    }


}


//without ordering the output
void dfs(vector<int>& candidates, int target, int s, vector<int>& cur, vector<vector<int>>& ans)
{
    if (target == 0) {
        ans.push_back(cur);
        return;
    }

    for (int i = s; i < candidates.size(); ++i) {
        if (candidates[i] > target)
        {
            break;//could change to return
        }
        cur.push_back(candidates[i]);

        vector<int>::iterator iter;
        for (iter = candidates.begin(); iter != candidates.end(); iter++) {

            cout << *iter << ",";
        }
        //cout << "  target: " << target << " s: " << 0 << "  d + 1: " << 0 << "  n:" << n << "  cur: ";
        cout << "  target: " << target << "  s:" << i << "  cur: ";

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
        dfs(candidates, target - candidates[i], i, cur, ans);
        cur.pop_back();
    }
}



