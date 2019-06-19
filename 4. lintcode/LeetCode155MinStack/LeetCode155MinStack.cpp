//https://leetcode.com/problems/min-stack/description/
//
//Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
//
//push(x) --Push element x onto stack.
//pop() --Removes the element on top of the stack.
//top() --Get the top element.
//getMin() --Retrieve the minimum element in the stack.
//Example:
//MinStack minStack = new MinStack();
//minStack.push(-2);
//minStack.push(0);
//minStack.push(-3);
//minStack.getMin();   --> Returns - 3.
//minStack.pop();
//minStack.top();      --> Returns 0.
//minStack.getMin();   --> Returns - 2.




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


class MinStack {
private:
	stack<int> myStack;
	stack<int>myMin; //myMin is a stack
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		//if 3112, need to keep two 1 in the myMin, if one 1 poped, still min is 1. 
		if (myMin.empty() || myMin.top() >= x) { // if put empty  after ||, if it is empty, myMin.top() is not valid
			myMin.push(x);
		}

		myStack.push(x);


	}

	void pop() {
		if (myStack.top() == myMin.top()) {
			myMin.pop();
		}
		myStack.pop();


	}

	int top() {
		return myStack.top();

	}

	int getMin() {

		return myMin.top();

	}
};


int main()
{


	MinStack question;
    question.push(1);
	question.push(5);
	question.push(3);
	question.push(4);
	

	question.getMin();
	question.pop();
	question.push(5);

	return 0;
}