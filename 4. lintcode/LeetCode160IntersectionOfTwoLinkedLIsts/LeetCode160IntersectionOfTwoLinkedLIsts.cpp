//https://leetcode.com/problems/intersection-of-two-linked-lists/description/
//Write a program to find the node at which the intersection of two singly linked lists begins.
//
//
//For example, the following two linked lists :
//
//A:          a1 ¡ú a2
//	¨K
//	c1 ¡ú c2 ¡ú c3
//	¨J
//	B : b1 ¡ú b2 ¡ú b3
//	begin to intersect at node c1.
//
//
//	Notes :
//
//	If the two linked lists have no intersection at all, return null.
//	The linked lists must retain their original structure after the function returns.
//	You may assume there are no cycles anywhere in the entire linked structure.
//	Your code should preferably run in O(n) time and use only O(1) memory.



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
#include<set>
using namespace std;





//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:


	ListNode * getIntersectionNode(ListNode *headA, ListNode *headB)
	{
		ListNode *p1 = headA;
		ListNode *p2 = headB;

		if (p1 == NULL || p2 == NULL) return NULL;

		while ( p1 != p2) {
			p1 = p1->next;
			p2 = p2->next;
		
			if (p1 == p2) { // when both are NULL or same.

				return p1;// note is one the note book(white folder)
			}

			if (p1 == NULL) {
				p1 = headB;
			}

			if (p2 == NULL) {
				p2 = headA;
			}

			cout << "p1: " << p1->val << "  p2: " << p2->val << endl;

		}

		return p1; // must have this return 
		/*Intersected at '1': [1] [1]*/
	}
};


int main()
{


	//ListNode head6(1); //only a variable

	ListNode * head5 = new ListNode(15); //this is a pointer, 

	ListNode * head4 = new ListNode(14);
	head4->next = head5;
	ListNode * head3 = new ListNode(13);
	head3->next = head4;
	ListNode * head2 = new ListNode(12);
	head2->next = head3;
	ListNode * head = new ListNode(11);
	head->next = head2;


	ListNode * head11 = new ListNode(26);
	ListNode * head10 = new ListNode(25);
	head10->next = head11;
	ListNode * head9 = new ListNode(24);
	head9->next = head10;
	ListNode * head8 = new ListNode(23);
	head8->next = head9;
	ListNode * head7 = new ListNode(22);
	head7->next = head8;
	ListNode * head6 = new ListNode(21);
	head6->next = head7;

	Solution question;
	question.getIntersectionNode(head, head6);



	return 0;
}