//https://www.jiuzhang.com/solutions/clone-graph/
//http://www.lintcode.com/en/problem/clone-graph/
//https://leetcode.com/problems/clone-graph/description/
//
//Clone an undirected graph.Each node in the graph contains a label and a list of its neighbors.
//
//How we serialize an undirected graph :
//
//Nodes are labeled uniquely.
//
//We use # as a separator for each node, and, as a separator for node label and each neighbor of the node.
//
//As an example, consider the serialized graph{ 0,1,2#1,2#2,2 }.
//
//The graph has a total of three nodes, and therefore contains three parts as separated by #.
//
//First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
//Second node is labeled as 1. Connect node 1 to node 2.
//Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self - cycle.
//Visually, the graph looks like the following :
//
//    1
// /     \
///       \
//0 -- - 2
//      / \
//      \_ /


#include <iostream>
#include <math.h>
#include <algorithm> 
#include<vector>
#include<string>
#include <queue>
#include <stack>
#include <list>
#include <map>   //hash table
#include <unordered_map>


using namespace std;


// Definition for undirected graph.
 struct UndirectedGraphNode {
     int label;
     vector<UndirectedGraphNode *> neighbors;
     UndirectedGraphNode(int x) : label(x)
     {};
 };
 UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node);
 UndirectedGraphNode *cloneGraph2(UndirectedGraphNode *node);

 UndirectedGraphNode *clone(UndirectedGraphNode *node, map<int, UndirectedGraphNode*> &table);


 class Solution {
 public:
	 UndirectedGraphNode * cloneGraph(UndirectedGraphNode *node) {
		 map<int, UndirectedGraphNode*>table;
		 return dfs(node, table);
	 }

	 UndirectedGraphNode* dfs(UndirectedGraphNode* node, map<int, UndirectedGraphNode *> &table) {
		 if (node == NULL) {
			 return NULL;
		 }
		 if (table.find(node->label) != table.end()) {
			 return table[node->label];
		 }
		 UndirectedGraphNode* newNode = new UndirectedGraphNode(node->label);
		 table[newNode->label] = newNode;
		 for (int i = 0; i < node->neighbors.size(); i++) {
			 UndirectedGraphNode* neighbor = dfs(node->neighbors[i], table);
			 newNode->neighbors.push_back(neighbor);
		 }
		 return newNode;
	 }
 };


 int main()
 {

    
    
     UndirectedGraphNode graph1(1);
     UndirectedGraphNode graph2(2);
     UndirectedGraphNode graph3(3);
     //vector<UndirectedGraphNode *> result;

     graph1.neighbors.push_back(&graph2);
     graph1.neighbors.push_back(&graph3);
     
	 cloneGraph2(&graph1);
     
    

     return 0;
 }

 //DFS
 UndirectedGraphNode *cloneGraph2(UndirectedGraphNode *node)
 {
     map<int, UndirectedGraphNode*> visitTable;
     return clone(node, visitTable);
 }


 UndirectedGraphNode *clone(UndirectedGraphNode *node, map<int, UndirectedGraphNode*> &table)
 {
     if (node == NULL)
         return NULL;

     if (table.find(node->label) != table.end())
         return table[node->label];

     UndirectedGraphNode *newnode = new UndirectedGraphNode(node->label);
     table[newnode->label] = newnode;

     for (int i = 0; i<node->neighbors.size(); i++)
     {
         UndirectedGraphNode *neighbor = clone(node->neighbors[i], table);
         newnode->neighbors.push_back(neighbor);
     }
     return newnode;
 }

//BFS
 UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node) {
     if (!node) {
         return nullptr;
     }
     UndirectedGraphNode *p1 = node;
     UndirectedGraphNode *p2 = new UndirectedGraphNode(node->label);
     unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> map;
     queue<UndirectedGraphNode*> q;
     q.push(node);
     map[node] = p2;

     while (!q.empty()) {
         p1 = q.front();
         p2 = map[p1];
         q.pop();
         for (int i = 0; i<p1->neighbors.size(); i++) 
         {
             UndirectedGraphNode *nb = p1->neighbors[i];
             if (map.count(nb)) {
                 p2->neighbors.push_back(map[nb]);
             }
             else {
                 UndirectedGraphNode *temp = new UndirectedGraphNode(nb->label);
                 p2->neighbors.push_back(temp);
                 map[nb] = temp;
                 q.push(nb);
             }
         }
     }

     return map[node];
 }