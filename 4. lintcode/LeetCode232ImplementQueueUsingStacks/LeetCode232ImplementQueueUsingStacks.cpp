//https://leetcode.com/problems/implement-queue-using-stacks/submissions/1
//
//Implement the following operations of a queue using stacks.
//
//push(x) --Push element x to the back of queue.
//pop() --Removes the element from in front of queue.
//peek() --Get the front element.
//empty() --Return whether the queue is empty.
//Example:
//
//MyQueue queue = new MyQueue();
//
//queue.push(1);
//queue.push(2);
//queue.peek();  // returns 1
//queue.pop();   // returns 1
//queue.empty(); // returns false
//Notes:
//
//You must use only standard operations of a stack -- which means only push to top, peek / pop from top, size, and is empty operations are valid.
//Depending on your language, stack may not be supported natively.You may simulate a stack by using a list or deque(double - ended queue), as long as you use only standard operations of a stack.

//You may assume that all operations are valid(for example, no pop or peek operations will be called on an empty queue).

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


class MyQueue {
public:
	/** Initialize your data structure here. */
	stack<int> pushStack;
	stack<int> popStack;
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		pushStack.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		if (popStack.empty())
			populatePopStack();
		int val = popStack.top();
		popStack.pop();
		return val;
	}

	/** Gepusht the front element. */
	int peek() {
		if (popStack.empty())
			populatePopStack();
		return popStack.top();
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return (pushStack.empty() && popStack.empty());
	}

	void populatePopStack() {
		while (!pushStack.empty()) {
			int val = pushStack.top();
			pushStack.pop();
			popStack.push(val);
		}
	}
};



int main()
{

	vector<int>nums({ 3, 1 ,0 });
	MyQueue question;
	question.push(1);
	question.push(2);
	question.push(3);
	question.push(4);

	question.pop();

	question.push(5);
	question.push(6);
	question.push(7);

	question.pop();

	return 0;
}