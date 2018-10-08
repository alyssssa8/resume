//https://www.youtube.com/watch?v=kK9TBtQBmCg
//https://leetcode.com/problems/employee-importance/description/
//http://zxi.mytechroad.com/blog/searching/leetcode-690-employee-importance/
//
//You are given a data structure of employee information, which includes the employee's unique id, his importance value and his direct subordinates' id.
//
//For example, employee 1 is the leader of employee 2, and employee 2 is the leader of employee 3. They have importance value 15, 10 and 5, respectively.Then employee 1 has a data structure like[1, 15, [2]], and employee 2 has[2, 10, [3]], and employee 3 has[3, 5, []].Note that although employee 3 is also a subordinate of employee 1, the relationship is not direct.
//
//Now given the employee information of a company, and an employee id, you need to return the total importance value of this employee and all his subordinates.
//
//Example 1:
//Input: [[1, 5, [2, 3]], [2, 3, []], [3, 3, []]], 1
//	Output : 11
//	Explanation :
//	Employee 1 has importance value 5, and he has two direct subordinates : employee 2 and employee 3. They both have importance value 3. So the total importance value of employee 1 is 5 + 3 + 3 = 11.

#include <iostream>
using namespace std;

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
#include<unordered_map>
using namespace std;

// Employee info
class Employee {
public:
// It's the unique ID of each node.
// unique id of this employee
int id;
// the importance value of this employee
int importance;
// the id of direct subordinates
vector<int> subordinates;
};


class Solution3 {

public:
	int getImportance(vector<Employee*> employees, int id) {

		unordered_map<int, Employee*> newStorage;
		for (int i = 0; i < employees.size(); i++) {
			newStorage.emplace(employees[i]->id, employees[i]);
		}

		return dfs(newStorage, id);
	}
	int dfs(unordered_map<int, Employee*> newStorage, int id) {
		Employee* e = newStorage.at(id);
		int sum = e->importance;
		for (int i = 0; i < e->subordinates.size(); i++) {
			sum += dfs(newStorage, e->subordinates[i]); // 5 + 3 + 3
		}

		return sum; //when no more subordinates, just return the sum the curren id. 

	}
};

class Test2 {
public:
	int getImportance(vector<Employee*> employees, int id) {

		unordered_map<int, Employee*> newStorage;
		for (auto e : employees) {
			newStorage.emplace(e->id, e);
		}
		int sum = 0;
		queue<int>myQueue;
		myQueue.push(id);
		while (!myQueue.empty())
		{

			int tempValue = myQueue.front();
			myQueue.pop();

			Employee * e = newStorage[tempValue];
			sum += e->importance;

			for (int i = 0; i < e->subordinates.size(); i++)
			{
				myQueue.push(e->subordinates[i]);
			}
		}
		return sum;
	}
};


class Test {
public:
	int getImportance(vector<Employee*> employees, int id) {
	
		unordered_map<int, Employee*> newStorage;
		for (auto e : employees){
			newStorage.emplace(e->id, e);
		}
		return dfs( newStorage, id);
	}
	int dfs(unordered_map<int, Employee*> newStorage, int id){
		Employee* e = newStorage.at(id);
		int sum = e->importance;
		for (int subValue : e->subordinates) {
			sum += dfs( newStorage, subValue);
		}

		return sum;

	}
};

// Author: Huahua
// Running time: 13 ms
//BFS

class Solution {
public:
	int getImportance(vector<Employee*> employees, int id) {
		unordered_map<int, Employee*> es;
		for (auto e : employees)
			es.emplace(e->id, e);

		queue<int> q;
		q.push(id);
		int sum = 0;
		while (!q.empty()) {
			int eid = q.front(); q.pop();
			auto e = es[eid];
			sum += e->importance;
			for (auto rid : e->subordinates)
				q.push(rid);
		}
		return sum;
	}
};

//DFS
class Solution2 {
public:
	int getImportance(vector<Employee*> employees, int id) {
		unordered_map<int, Employee*> es;
		for (auto e : employees)
			es.emplace(e->id, e);
		return dfs(id, es);
	}
private:
	int dfs(int id, const unordered_map<int, Employee*>& es) {
		const auto e = es.at(id);
		int sum = e->importance;
		for (int rid : e->subordinates)
			sum += dfs(rid, es);
		return sum;
	}
};
int main()
{
	int id = 1;

	Employee employee1;
	employee1.id = 1;
	employee1.importance = 5;
	employee1.subordinates.push_back(2);
	employee1.subordinates.push_back(3);
	Employee employee2;
	employee2.id = 2;
	employee2.importance = 3;

	

	Employee employee3;
	employee3.id = 3;
	employee3.importance = 3;

	vector<Employee*> employees{&employee1, &employee2,&employee3 };

	Solution question;
	question.getImportance(employees, id);
	Solution2 question2;
	question2.getImportance(employees, id);
	Solution3 question3;
	question3.getImportance(employees, id);


	Test queston3;
	queston3.getImportance(employees, id);

	Test2 queston4;
	queston4.getImportance(employees, id);
	return 0;


}
