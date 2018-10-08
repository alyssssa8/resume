//https://leetcode.com/problems/delete-node-in-a-linked-list/description/
//
//Write a function to delete a node(except the tail) in a singly linked list, given only access to that node.
//
//Given linked list -- head = [4, 5, 1, 9], which looks like following :
//
//4 -> 5 -> 1 -> 9
//Example 1 :
//
//	Input : head = [4, 5, 1, 9], node = 5
//	Output : [4, 1, 9]
//	Explanation : You are given the second node with value 5, the linked list
//	should become 4 -> 1 -> 9 after calling your function.
//	Example 2 :
//
//	Input : head = [4, 5, 1, 9], node = 1
//	Output : [4, 5, 9]
//	Explanation : You are given the third node with value 1, the linked list
//	should become 4 -> 5 -> 9 after calling your function.
//	Note :
//	The linked list will have at least two elements.
//	All of the nodes' values will be unique.
//	The given node will not be the tail and it will always be a valid node of the linked list.
//	Do not return anything from your function.
//



#include <iostream>
#include <math.h>
#include <algorithm>
#include<vector>
#include<string>
#include <queue>
#include <stack>
#include <list>
#include <map>   //
table
#include<unordered_map>
#include <vector>
#include <unordered_set>
#include <set>
using namespace std;





//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	void deleteNode(ListNode* node) {
		*node = *node->next;		
	}
};
class Solution {
public:
	void deleteNode(ListNode* node) {

		if (node == NULL || node->next == NULL) {
			return;
		}
		node->val = node->next->val;
		node->next = node->next->next;
	}
};

int main()
{

	//ListNode head6(1); //only a variable
	ListNode * head7 = new ListNode(4);

	ListNode * head6 = new ListNode(5); //this is a pointer, 
										//head6->next = head7;
	ListNode * head4 = new ListNode(4);
	head4->next = head6;
	ListNode * head3 = new ListNode(3);
	head3->next = head4;
	ListNode * head2 = new ListNode(2);
	head2->next = head3;

	ListNode * head = new ListNode(1);
	head->next = head2;


	Solution question;
	question.deleteNode(head);

	//Solution2 question2;
	//question2.mergeTwoLists(head, head);


	return 0;
}