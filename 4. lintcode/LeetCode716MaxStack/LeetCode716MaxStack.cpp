//Design a max stack that supports push, pop, top, peekMax and popMax.
//
//push(x) --Push element x onto stack.
//pop() --Remove the element on top of the stack and return it.
//top() --Get the element on the top.
//peekMax() --Retrieve the maximum element in the stack.
//popMax() --Retrieve the maximum element in the stack, and remove it.If you find more than one maximum elements, only remove the top - most one.
//
//
//Example 1:
//
//MaxStack stack = new MaxStack();
//stack.push(5);
//stack.push(1);
//stack.push(5);
//stack.top(); -> 5
//stack.popMax(); -> 5
//stack.top(); -> 1
//stack.peekMax(); -> 5
//stack.pop(); -> 1
//stack.top(); -> 5




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



class MaxStack {
private:
    stack<int>myStack;
    stack<int>myMax;
public:

    /** initialize your data structure here. */
    MaxStack() {
    }

    void push(int x) {
        if (myMax.empty() || myMax.top() <= x) {
            myMax.push(x);
        }
        myStack.push(x);
    }

    int pop() {
        int returnVal = myStack.top();
        if (myStack.top() == myMax.top()) {
            myMax.pop();
        }

        myStack.pop();
        return returnVal;

    }

    int top() {
        return myStack.top();

    }

    int peekMax() {
        return myMax.top();
    }

    int popMax() {
        int returnVal = myMax.top();
        stack<int>temp;

        while (myMax.top() != myStack.top()) {
            temp.push(myStack.top());
            myStack.pop();
        }
        myMax.pop();
        myStack.pop();
        while (!temp.empty()) {
            myStack.push(temp.top());
            if (myMax.empty() || temp.top() >= myMax.top()) {
                myMax.push(temp.top());
            }
            temp.pop();
        }


        return returnVal;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */

class MaxStack2 {
public:
    list<int> v;
    map<int, vector<list<int>::iterator>> mp;

    MaxStack2() {
    }

    void push(int x) {
        v.insert(v.begin(), x);
        mp[x].push_back(v.begin());
    }

    int pop() {
        int x = *v.begin();
        mp[x].pop_back();
        if (mp[x].empty()) mp.erase(x);
        v.erase(v.begin());
        return x;
    }

    int top() {
        return *v.begin();
    }

    int peekMax() {
        return mp.rbegin()->first;
    }

    int popMax() {
        int x = mp.rbegin()->first;
        auto it = mp[x].back();
        mp[x].pop_back();
        if (mp[x].empty()) mp.erase(x);
        v.erase(it);
        return x;
    }
};
int main()
{
    MaxStack* hashMap = new MaxStack();
    hashMap->push(5);
    hashMap->push(1);
    hashMap->push(5);       
    hashMap->top();           //-->5     
    hashMap->popMax();        //-->5    
    hashMap->top();           //-->1   
    hashMap->peekMax();       //-->5        
    hashMap->pop();           //-->1   
    hashMap->top();           //-->5  
    return 0;
}