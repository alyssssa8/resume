//https://leetcode.com/problems/course-schedule-ii/description/
//https://www.youtube.com/watch?v=Qqgck2ijUjU
//http://zxi.mytechroad.com/blog/graph/leetcode-210-course-schedule-ii/
//There are a total of n courses you have to take, labeled from 0 to n - 1.
//
//Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair : [0, 1]
//
//Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.
//
//There may be multiple correct orders, you just need to return one of them.If it is impossible to finish all courses, return an empty array.
//
//For example :
//
//2, [[1, 0]]
//There are a total of 2 courses to take.To take course 1 you should have finished course 0. So the correct course order is[0, 1]
//
//4, [[1, 0], [2, 0], [3, 1], [3, 2]]
//There are a total of 4 courses to take.To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after 
//you finished course 0. So one correct course order is[0, 1, 2, 3].Another correct ordering is[0, 2, 1, 3].


//
//
//#include <iostream>
//#include <math.h>
//#include <algorithm> 
//#include<vector>
//#include<string>
//#include <queue>
//#include <stack>
//#include <list>
//#include <map>   //hash table
//
//
//
//int main()
//{
//
//
//
//    return 0;
//}

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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	vector<vector<int>> newValueStore;
	vector<int>ans;
	vector<int>valueStatus;
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		newValueStore = vector<vector<int>>(numCourses);
		valueStatus = vector<int>(numCourses);
		for (int i = 0; i < prerequisites.size(); i++) {
			newValueStore[prerequisites[i].second].push_back(prerequisites[i].first);
		}

		for (int i = 0; i <numCourses; i++) {
			if (dfs(i)) {
				return {};
			}
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
	bool dfs(int i) {
		if (valueStatus[i] == 1) {
			return true;
		}
		if (valueStatus[i] == 2) {
			return false;
		}
		else {
			valueStatus[i] = 1;
			for (int j = 0; j <newValueStore[i].size(); j++) {
				if (dfs(newValueStore[i][j]) == true) {
					return true;
				}
			}
			valueStatus[i] = 2;
			ans.push_back(i);
			return false;
		}
	}

};

class Test {
private: 
	vector<vector<int>> newVectorStore;
	vector<int> ans;

public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		newVectorStore = vector<vector<int>>(numCourses);
		vector<int>valueStatus(numCourses);

		for (const auto &temp : prerequisites)
		{
			newVectorStore[temp.second].push_back(temp.first);
		}

		for (int i = 0; i < numCourses; i++)
		{
			if (dfs(i, valueStatus))
			{
				return {}; // have cycle, return empty.
			}
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}

	bool dfs(int i, vector<int>& valueStatus)
	{
		if (valueStatus[i] == 1)
		{
			return true;
		}
		else if (valueStatus[i] == 2)
		{
			return false;
		}
		else
		{
			valueStatus[i] = 1;

			for (const int temp : newVectorStore[i])
			{
				if (dfs(temp, valueStatus))
				{
					return true;
				}
			}
			valueStatus[i] = 2;
			ans.push_back(i);
			return false;
		}




	}

};


vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites);
bool dfs(int cur, vector<vector<int>>& graph, vector<int>& v, vector<int>& ans);



int main()
{
    int numCourses = 4;
    vector<pair<int, int>>prerequisites({ { 1,0 }, { 2,0 },{3,1 },{3,2} });
    vector<pair<int, int>>::iterator iter;
    pair<int, int>  temp ;
    for (iter = prerequisites.begin(); iter != prerequisites.end(); iter++)
    {
        temp = *iter;
        cout << " 1: "<< temp.first<<" 2: " << temp.second<< endl; // if vector is a struct, (*iter).member or iter->member
        cout << "________________"<<endl;

    }

    findOrder(numCourses, prerequisites);
 


    
    
    return 0;
}
vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites)
{
    vector<vector<int>> graph(numCourses);
    for (const auto& p : prerequisites)
    {
        graph[p.second].push_back(p.first); // hash table 
        cout << "p.second: " << p.second << "p.first:" << p.first << endl;
        cout << "____________________________" << endl;
    }
    //graph[0]=1,2
    //graph[1]=3
    //graph[2]=3

    // states: 0 = unkonwn, 1 == visiting, 2 = visited
    vector<int> v(numCourses, 0);
    vector<int> ans;

    for (int i = 0; i < numCourses; ++i)
    {
        if (dfs(i, graph, v, ans)) return {};
    }


    reverse(ans.begin(), ans.end());
    return ans;
}

bool dfs(int cur, vector<vector<int>>& graph, vector<int>& v, vector<int>& ans)
{
    if (v[cur] == 1)
    {
        return true;
    }

    if (v[cur] == 2)
    {
        return false;
    }

    v[cur] = 1;

    for (const int t : graph[cur])
    {
        if (dfs(t, graph, v, ans))
        {
            return true;
        }
    }

    v[cur] = 2;
    ans.push_back(cur);

    return false;
}