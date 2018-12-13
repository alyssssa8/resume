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




// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        traversal(root, res);
        return res;
    }

    void traversal(Node* n, vector<int> &res)
    {
        if (!n)
            return;

        for (auto i : n->children) {
            traversal(i, res);
        }
        res.push_back(n->val);
    }
};

class Solution {
public:
    vector<int> postorder(Node* root) {
        if (root == NULL) {
            return {};
        }
        vector<int> res;
        stack<Node*> stk;
        stk.push(root);
        while (!stk.empty())
        {
            Node* temp = stk.top();
            stk.pop();
            for (int i = 0; i < temp->children.size(); i++)
            {
                stk.push(temp->children[i]);
            }
            res.push_back(temp->val);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

class Solution {
public:
    vector<int> postorder(Node* root) {

        stack<Node*> s;
        s.push(root);
        vector<int> result;
        while (s.empty() == false && root) {
            Node* n = s.top(); {
                s.pop();
            }

            for (auto i : n->children) {
                s.push(i);
            }
            result.push_back(n->val);


        }
        reverse(result.begin(), result.end());
        return result;

    }
};

class Solution {
public:
    vector<int> postorder(Node* root) {
        stack<Node*> s; 
        s.push(root);
        vector<int> result;
        while (!s.empty() && root) {
            Node * n = s.top(); s.pop();
            result.insert(result.begin(), n->val);
            for (auto & ch : n->children) s.push(ch);
        }
        return result;
    }
};

// Definition for a Node.
class Node { 
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};



int main()
{

    Node second;
    Node third;
    Node fourth;
    //vector <Node*> child1({ second, third,fourth });
    Node first( 2, {&second,&third,&fourth} );

   

    vector<int>nums({ 3, 1 ,0 });
    Solution question; 
    question.postorder(&first,);
    Solution question2;
    question2.postorder(&first);

    return 0;
}