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

class MyHashMap {
public:
    /** Initialize your data structure here. */
    map<int, int>myMap;
    MyHashMap() {

    }
    /** value will always be non-negative. */
    void put(int key, int value) {
        myMap[key] = value;
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        if (myMap.find(key) == myMap.end() || myMap[key] == -1) {
            return -1;
        }
        return myMap[key];

    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {

        myMap[key] = -1;
    }
};


struct hashNode {
    std::list<pair<int, int>> _list;

    std::list<pair<int, int>>::iterator myFind(int key) {
        return std::find_if(
            _list.begin(), _list.end(),
            [key](pair<int, int> a) { return (a.first == key); });
    }
};

class MyHashMap2 {
public:
    /** Initialize your data structure here. */
    MyHashMap2() {
        _v = vector<hashNode>(_size);
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        int k = hash(key);
        auto it = _v[k].myFind(key);
        if (it == _v[k]._list.end()) {
            _v[k]._list.push_back(make_pair(key, value));
        }
        else {
            it->second = value;
        }
    }

    /** Returns the value to which the specified key is mapped, or -1 if
     * this map contains no mapping for the key */
    int get(int key) {
        int k = hash(key);
        auto it = _v[k].myFind(key);

        if (it == _v[k]._list.end()) {
            return -1;
        }
        else {
            return it->second;
        }
    }

    /** Removes the mapping of the specified value key if this map
     * contains a mapping for the key */
    void remove(int key) {
        int k = hash(key);
        auto it = _v[k].myFind(key);

        if (it != _v[k]._list.end()) {
            _v[k]._list.erase(it);
        }
    }

    int hash(int key) {
        return key % _size;
    }


    std::vector<hashNode> _v;
    int _size = 100;
};

int main()
{
    MyHashMap* hashMap = new MyHashMap();
    hashMap->put(1, 1);
    hashMap->put(2, 2);
    hashMap->get(1);            // returns 1
    hashMap->get(3);            // returns -1 (not found)
    hashMap->put(2, 1);          // update the existing value
    hashMap->get(2);            // returns 1 
    hashMap->remove(2);          // remove the mapping for 2
    hashMap->get(2);            // returns -1 (not found) 
    return 0;
}