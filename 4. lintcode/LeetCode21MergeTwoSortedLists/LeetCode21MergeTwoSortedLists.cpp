//https://leetcode.com/problems/merge-two-sorted-lists/description/
//https://www.youtube.com/watch?v=qckKEYP9bBA
//http://zxi.mytechroad.com/blog/leetcode/leetcode-21-merge-two-sorted-lists/
//Given a linked list, determine if it has a cycle in it.
//
//Follow up :
//Can you solve it without using extra space ?


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
#include <unordered_set>
#include <set>
using namespace std;





//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};



class Solution2 {
public:
	ListNode * mergeTwoLists(ListNode* l1, ListNode* l2) {


		ListNode dummy(0);
		ListNode* tail = &dummy; // do not know which one the ha
		while (l1 && l2) {
			if (l1->val < l2->val) {
				tail->next = l1;
				l1 = l1->next;
			}
			else {
				tail->next = l2;
				l2 = l2->next;
			}
			tail = tail->next;
		}

		if (l1) tail->next = l1;
		if (l2) tail->next = l2;

		return dummy.next;

	}
};


class Solution {
public:
	ListNode * mergeTwoLists(ListNode* l1, ListNode* l2) {

		if (!l1 || !l2) return l1 ? l1 : l2;
		if (l1->val < l2->val) {
			l1->next = mergeTwoLists(l1->next, l2);
			return l1;
		}
		else {
			l2->next = mergeTwoLists(l1, l2->next);
			return l2;
		}
	}
};

int main()
{

	//ListNode head6(1); //only a variable
	ListNode * head7 = new ListNode(4);
	
	ListNode * head6 = new ListNode(5); //this is a pointer, 
	//head6->next = head7;
	ListNode * head4 = new ListNode(7);

	ListNode * head3 = new ListNode(4);
	//head3->next = head4;
	ListNode * head2 = new ListNode(2);
	head2->next = head3;

	ListNode * head = new ListNode(1);
	head->next = head2;


	//Solution question;
	//question.mergeTwoLists(head , head);

	//Solution2 question2;
	//question2.mergeTwoLists(head, head);

	
	return 0;
}