//https://leetcode.com/problems/implement-stack-using-queues/description/
//Implement the following operations of a stack using queues.
//
//push(x) --Push element x onto stack.
//pop() --Removes the element on top of the stack.
//top() --Get the top element.
//empty() --Return whether the stack is empty.
//Example:
//
//MyStack stack = new MyStack();
//
//stack.push(1);
//stack.push(2);
//stack.top();   // returns 2
//stack.pop();   // returns 2
//stack.empty(); // returns false
//Notes:
//
//You must use only standard operations of a queue -- which means only push to back, peek / pop from front, size, and is empty operations are valid.
//Depending on your language, queue may not be supported natively.You may simulate a queue by using a list or deque(double - ended queue), as long as you use only standard operations of a queue.
//You may assume that all operations are valid(for example, no pop or top operations will be called on an empty stack).

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

class MyStack2 {
private:
	queue<int> q;
public:
	/** Initialize your data structure here. */

	MyStack2() {

	}

	/** Push element x onto stack. */
	void push(int x) {
		q.push(x);
		for (int i = 1; i<q.size(); i++) {
			q.push(q.front());  // everytime, when you push a value, you travers the whole queue. 
			q.pop();
		}
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int n = q.front();
		q.pop();
		return n;
	}

	/** Get the top element. */
	int top() {
		return q.front();
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return q.empty();
	}
};

class MyStack3 {
public:
	queue<int>q1;


	/** Initialize your data structure here. */
	MyStack3() {

	}

	/** Push element x onto stack. */
	void push(int x) {
		q1.push(x);

	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		queue<int>q2;
		while (q1.size()>1) { // until the size of q1 only have one value left. 
			q2.push(q1.front());
			q1.pop();
		}
		int ans = q1.front();
		q1.pop();
		q1 = q2;
		return ans;
	}

	/** Get the top element. */
	int top() {
		int ans = pop();
		q1.push(ans);
		return ans;
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return q1.empty();
	}
};
// queue do not have clear, push_back, pop_front, only have push, pop, and front. 
class MyStack4 {
public:
	deque<int>q1;
	deque<int>q2;
	/** Initialize your data structure here. */
	MyStack4() {}

	/** Push element x onto stack. */
	void push(int x) {
		q1.push_back(x);
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		while (q1.size() > 1) {
			q2.push_back(q1.front()), q1.pop_front();
		}
		int num = q1.front();
		q1.pop_front();
		q1 = q2;
		q2.clear();
		return num;
	}

	/** Get the top element. */
	int top() {
		int num = pop();
		q1.push_back(num);
		return num;
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return q1.empty();
	}
};



int main()
{
	
	
	MyStack3 question;
	question.push(1);
	question.push(2);
	question.push(3);
	question.push(4);


	question.top();
	question.pop();

	question.push(5);
	question.push(6);
	question.push(7);

	question.pop();

	return 0;
}

