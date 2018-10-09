//https://leetcode.com/problems/course-schedule/description/
//https://www.youtube.com/watch?v=M6SBePBMznU&t=492s
//http://zxi.mytechroad.com/blog/graph/leetcode-207-course-schedule/
//There are a total of n courses you have to take, labeled from 0 to n - 1.
//
//Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair : [0, 1]
//
//Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses ?
//
//Example 1 :
//
//	Input : 2, [[1, 0]]
//	Output : true
//	Explanation : There are a total of 2 courses to take.
//	To take course 1 you should have finished course 0. So it is possible.
//	Example 2 :
//
//	Input : 2, [[1, 0], [0, 1]]
//	Output : false
//	Explanation : There are a total of 2 courses to take.
//	To take course 1 you should have finished course 0, and to take course 0 you should
//	also have finished course 1. So it is impossible.
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
#include <vector>
using namespace std;

class Solution3 {
private:
	vector<vector<int>>newVectorStore;
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		newVectorStore = vector<vector<int>>(numCourses);
		for (int i = 0; i <prerequisites.size(); i++) {
			newVectorStore[prerequisites[i].first].push_back(prerequisites[i].second);
		}
		vector<int>valueStatus(numCourses);
		for (int i = 0; i < numCourses; i++) {
			if (dfs(i, valueStatus)) {
				return false;
			}
		}
		return true;
	}
	bool dfs(int i, vector<int> &  valueStatus) {
		if (valueStatus[i] == 1) {
			return true;
		}
		if (valueStatus[i] == 2) {
			return false;
		}
		else {
			valueStatus[i] = 1;
			for (int j = 0; j < newVectorStore[i].size(); j++) {
				if (dfs(newVectorStore[i][j], valueStatus)) {
					return true;
				}
			}
		}
		valueStatus[i] = 2;
		return false;
	}
};

class Test {
private:
	vector<vector<int>>newVectorStore;
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {

		newVectorStore = vector<vector<int>>(numCourses);
		pair<int, int>temp;
		/*for (const auto& temp : prerequisites)
		{
			newVectorStore[temp.first].push_back(temp.second);
		}
*/
		for (int i = 0; i < prerequisites.size(); i++) {
			newVectorStore[prerequisites[i].first].push_back(prerequisites[i].second); //for [[1,0], [0,1],newVectorStore[0] = 1, newVectorStore[1] = 0
			cout << "prerequisites[i].first: " << prerequisites[i].first << " prerequisites[i].second: " << prerequisites[i].second << endl;
		}
		vector<int>valueStatus(numCourses);
		for (int i = 0; i < numCourses; i++){
			if (dfs(i, valueStatus)){
				return false;
			}
		}
		return true;
	}

	bool dfs(int i, vector<int> &valuestatus){
		if (valuestatus[i] == 1){
			return true; //have cycle
		}
		else if (valuestatus[i] == 2){
			return false;
		}
		else{
			valuestatus[i] = 1;
			/*for (const int temp : newVectorStore[i])
			{
				if (dfs(temp, valuestatus))
				{
					return true;
				}
			}*/
			for (int j = 0; j < newVectorStore[i].size(); j++) {
				cout << "newVectorStore[i][j]: " << newVectorStore[i][j] << endl;
				if (dfs(newVectorStore[i][j], valuestatus)) {
					return true;
				}
			}
			valuestatus[i] = 2;
			return false;
		}
	}
};




class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {

		graph_ = vector<vector<int>>(numCourses);
		/*for (int i = 0; i <prerequisites.size(); i++)
		{
		graph_[prerequisites[i].first].push_back(prerequisites[i].second);
		}*/

		for (const auto& p : prerequisites) {
			
			graph_[p.first].push_back(p.second);

		}

		// states: 0 = unkonwn, 1 == visiting, 2 = visited
		vector<int> v(numCourses, 0);///v[0]=0,v.[1]=0

		for (int i = 0; i < numCourses; ++i)
			if (dfs(i, v)) return false;  //false: cycle

		return true;  //true: no cycle
	}

private:
	vector<vector<int>> graph_;
	bool dfs(int cur, vector<int>& v) {

		if (v[cur] == 1)
		{
			return true;  //cycle
		}
		if (v[cur] == 2)
		{
			return false;  //ok
		}

		v[cur] = 1;

		for (const int t : graph_[cur])
		{
			if (dfs(t, v))
			{
				return true;  //cycle
			}
		}

		v[cur] = 2;

		return false;//ok

	}
};

int main()
{
	Solution question;
	int numCourses = 8;
	vector<pair<int, int>> prerequisites({ { 1,0 }, { 2,6 },{ 1,7 },{ 6,4 },{7,0},{ 0,5 } });
	//vector<pair<int, int>> prerequisites({ { 1,0 },{ 1,0 } });
	vector<pair<int, int>>::iterator iter;
	pair<int, int>  temp;

	for (iter = prerequisites.begin(); iter != prerequisites.end(); iter++)
	{
		temp = *iter;
		cout << " 1: " << temp.first << " 2: " << temp.second << endl; // if vector is a struct, (*iter).member or iter->member
		cout << "________________" << endl;

	}

	question.canFinish(numCourses,prerequisites);

	Test question2;
	question2.canFinish(numCourses,prerequisites);


	return 0;
}

