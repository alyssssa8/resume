//https://leetcode.com/problems/reverse-linked-list/description/
//
//Reverse a singly linked list.
//
//Example :
//
//	Input : 1->2->3->4->5->NULL
//	Output : 5->4->3->2->1->NULL


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


//use this one 
class Solution6 {
public:
	ListNode * reverseList(ListNode* head) {
		ListNode* pre = NULL;
		ListNode* next;
		while (head != NULL) {
			next = head->next; // need to be carful when the value is changed. the value of head->next was changed. 
			head->next = pre;
			pre = head;
			head = next;
		}
		return pre;

	}
};

class Solution5 {
public:
	ListNode * reverseList(ListNode* head) {

		if (head == NULL)return NULL;
		ListNode *pre = new ListNode(0);
		pre->next = head;
		ListNode* start = head;
		ListNode* then = pre;
		while (start->next != NULL) {
			then = start->next;
			start->next = then->next;
			then->next = pre->next;
			pre->next = then;
		}
		return pre->next;
	}
};


class Solution4 {
public:
	ListNode * reverseList(ListNode* head) {

		if (head == NULL || head->next == NULL) return head;
		ListNode *curr = head->next;
		ListNode *prev = head;
		head->next = NULL;
		while (curr) {
			ListNode *temp = curr->next;
			curr->next = prev;
			prev = curr;
			curr = temp;
		}
		//curr->next = prev;
		
		return curr;
	}
};

class Solution2 {
public:
	ListNode * reverseList(ListNode* head) {

		if (head == NULL || head->next == NULL) return head;
		ListNode *res = reverseList(head->next);
		ListNode *curr = res;
		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = head;
		head->next = NULL;
		return res;
	}
};


class Solution3{
public:
	ListNode * reverseList(ListNode* head) {

		ListNode* temp = head;

		ListNode* tempHead = head;
		if (head == nullptr)
		{
			return head;
		}
		head = head->next;
		temp->next = NULL;
		while (head)
		{
			tempHead = head;
			head = head->next;
			tempHead->next = temp;
			temp = tempHead;

		}
		return tempHead;
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


	Solution2 question;
	question.reverseList(head);

	//Solution2 question2;
	//question2.mergeTwoLists(head, head);


	return 0;
}