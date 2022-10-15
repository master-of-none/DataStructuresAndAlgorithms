//
//  main.cpp
//  singlyLinkedList
//
//  Created by Shrikrishna Bhat on 10/13/22.
//

#include <iostream>
using namespace std;

//Class declaration
class ListNode {
    public :
        int data;
        ListNode *next;
};

//Functions
ListNode *insertAtBeginning(ListNode*,int);
ListNode *insertAtEnd(ListNode*,int);
void print(ListNode*);
int length(ListNode*);
ListNode *insertAtGivenPosition(ListNode*,ListNode*,int);
void deleteFirst(ListNode*&);
void deleteLast(ListNode*&);
void deleteAtGivenPosition(ListNode*&,int);

//Main Function
int main(int argc, const char * argv[]) {
    // insert code here...
    
    int data,count,choice,n,position;
    bool flag = true;
	ListNode *head = NULL;
	
	do {
		cout << "Enter 1 to insert at Beginning, 2 to insert at end, 3 to print, 4 to count, 5 to insert at given position " << endl;
		cout << "Enter 6 to delete first node, 7 to delete last node, 8 to delete from intermediate, Anything else to exit " << endl;
		cin >> choice;
		
		switch (choice) {
			case 1:
				cout << "Enter Data "<< endl;
				cin >> data;
				head = insertAtBeginning(head, data);
				break;
				
			case 2:
				cout << "Enter Data "<< endl;
				cin >> data;
				head = insertAtEnd(head, data);
				break;
			
			case 3:
				print(head);
				break;
				
			case 4:
				count = length(head);
				cout << "Length of the Linked List is : " << count << endl;
				break;
				
			case 5:
				ListNode* new_node;
				new_node = new ListNode();
				cout << "Enter Data " << endl;
				cin >> data;
				new_node->data = data;
				new_node->next = NULL;
				cout << "Enter position " << endl;
				cin >> n;
				head = insertAtGivenPosition(head,new_node,n);
				break;
				
			case 6:
				deleteFirst(head);
				break;
				
			case 7:
				deleteLast(head);
				break;
			
			case 8:
				cout << "Enter the position " << endl;
				cin >> position;
				deleteAtGivenPosition(head,position);
				break;
				
			default:
				flag = false;
				break;
		}
	}while(flag);
    
    return 0;
}

ListNode *insertAtBeginning(ListNode* head,int data)
{
	ListNode *temp;
	temp = new ListNode();

	temp->data = data;
	temp->next = NULL;
	
	if(head == NULL){
		head = temp;
		head->next = NULL;
	}
	
	else{
		temp->next = head;
		head = temp;
	}
	
	return head;
}

ListNode *insertAtEnd(ListNode* head,int data)
{
	ListNode *temp,*cur;
	
	temp = new ListNode();
	temp->data = data;
	temp->next = NULL;
	
	cur = head;
	
	if(cur == NULL){
		head = temp;
		//cout << "checking head->next value : " << head->next<<endl;
	}
	
	else{
		while (cur->next != NULL) {
			cur = cur->next;
		}
		
		cur->next = temp;
	}
	
	return head;
}

void print(ListNode* head)
{
	ListNode* cur = head;
	
	for(cur=head; cur!=NULL; cur=cur->next){
		cout << cur->data << " ";
	}
	cout << endl;
}


int length(ListNode* head)
{
	ListNode *cur = head;
	int count = 0;
	
	while (cur!=NULL) {
		cur = cur->next;
		count++;
	}
	return count;
}

ListNode* insertAtGivenPosition(ListNode* head, ListNode* new_node, int n)
{
	ListNode* pred = head;
	
	if(n <= 1){
		new_node -> next = head;
		return new_node;
	}
	
	while (--n && pred != NULL) {
		pred = pred->next;
	}
	
	if(pred == NULL){
		return NULL;
	}
	
	new_node->next = pred->next;
	pred->next = new_node;
	
	return head;
}

void deleteFirst(ListNode *&head)
{
	ListNode* temp;
	
	if(head == NULL){
		return;
	}
	
	temp = head;
	head = head->next;
	delete temp;
	return;
}

void deleteLast(ListNode *&head)
{
	ListNode *temp = NULL;
	ListNode *current = head;
	
	if(head == NULL)
		return;
	
	while (current->next) {
		temp = current;
		current = current->next;
	}
	temp->next = NULL;
	delete current;
}

void deleteAtGivenPosition(ListNode *&head,int position)
{
	int k = 1;
	ListNode *p, *q=NULL;
	
	if(head == NULL){
		cout << "List Empty" << endl;
		return;
	}
	
	p = head;
	
	if(position == 1){
		head = head->next;
		free(p);
		return;
	}
	
	else{
		while (p!=NULL && k<position) {
			k++;
			q = p;
			p = p->next;
		}
		
		if(p == NULL){
			cout << "Position does not exist " << endl;
			return;
		}
		else{
			q->next = p->next;
			free(p);
		}
		return;
	}
}
