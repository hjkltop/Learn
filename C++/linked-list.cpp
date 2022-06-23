#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next = nullptr;
};

class Solution
{
public:
	int reverseList(ListNode *head)
	{
		
		return head==nullptr ? 1:0;
	}


};
int main()
{
	ListNode a;
	ListNode b;
	ListNode c;
	ListNode d;
	ListNode e;

	a.val = 1;
	b.val = 2;
	c.val = 3;
	d.val = 4;
	e.val = 5;

	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	ListNode *head = &a;
	Solution sol;
int 	x = sol.reverseList(head);
cout<< x<< endl; 

	return head ==nullptr ? -9:0 ;
}