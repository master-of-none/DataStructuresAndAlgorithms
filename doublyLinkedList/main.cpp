//
//  main.cpp
//  doublyLinkedList
//
//  Created by Shrikrishna Bhat on 10/13/22.
//

#include <iostream>
using namespace std;
class DLLNode{
	public:
		int data;
		DLLNode *next;
		DLLNode *prev;
};
void print(DLLNode *head);
DLLNode *insertAtBeginning(DLLNode *&,int);
DLLNode *insertAtEnd(DLLNode *&,int);
DLLNode *insertAtPosition(DLLNode *&,int,int);
void deleteFront(DLLNode *&);
void deleteLast(DLLNode *&);

int main(int argc, const char * argv[]) {
	// insert code here...
	//std::cout << "Hello, World!\n";
	
	DLLNode *head = NULL;
	
	int choice,data,position;
	bool flag = true;
	do {
		cout << "Enter 1 to insert at Beginning, 2 to insert at end, 3 to print, 5 to insert at given position " << endl;
		cout << "Enter 6 to delete first node, 7 to delete last node, 8 to delete from intermediate, Anything else to exit " << endl;
		cin >> choice;
		
		switch (choice) {
			case 1:
				cout << "Enter Data " << endl;
				cin >> data;
				head = insertAtBeginning(head,data);
				break;
				
			case 2:
				cout << "Enter Data " << endl;
				cin >> data;
				head = insertAtEnd(head,data);
				break;
			
			case 3:
				print(head);
				break;
				
			case 5:
				cout << "Enter Data " << endl;
				cin >> data;
				cout << "Enter Position " << endl;
				cin >> position;
				head = insertAtPosition(head,data,position);
				break;
				
			case 6:
				deleteFront(head);
				break;
				
			case 7:
				deleteLast(head);
				break;
			
			case 8:
				
				break;
				
			default:
				flag = false;
				break;
		}
	}while(flag);
	
	
	return 0;
}

void print(DLLNode *head)
{
	DLLNode *cur = head;
	
	if(head == NULL)
		cout << "List is empty " << endl;
	
	cout << "LIST IS " << endl;
	while (cur != NULL) {
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << endl;
}

DLLNode* insertAtBeginning(DLLNode *&head, int data)
{
	DLLNode *current = head;
	DLLNode *newNode = new DLLNode();
	
	if(!newNode){
		cout << "Memory Error" << endl;
		return NULL;
	}
	newNode->prev = NULL;
	newNode->data = data;
	newNode->next = NULL;
	
	if(current == NULL){
		head = newNode;
		return head;
	}
	newNode->next = head;
	head->prev=newNode;
	head = newNode;
	return head;
}
DLLNode *insertAtEnd(DLLNode *&head ,int data)
{
	DLLNode *current = head;
	DLLNode *newNode = new DLLNode();
	
	if (!newNode) {
		cout << "Memory Error" << endl;
		return NULL;
	}
	
	newNode->prev = NULL;
	newNode->data = data;
	newNode->next = NULL;
	
	if(head == NULL){
		head = newNode;
		return head;
	}
	
	while (current->next!=NULL) {
		current = current->next;
	}
	
	newNode->prev = current;
	current->next = newNode;
	return head;
}

DLLNode *insertAtPosition(DLLNode *&head, int data, int position)
{
	int k = 1;
	DLLNode *temp,*newNode;
	newNode = new DLLNode();
	
	if(!newNode){
		cout << "Memory Error\n";
		return head;
	}
	
	newNode->prev = NULL;
	newNode->data = data;
	newNode->next = NULL;
	
	if(position == 1){
		newNode->next = head;
		newNode->prev = NULL;
		
		if(head){
			head->prev = newNode;
		}
		head = newNode;
		return head;
	}
	
	temp = head;
	
	while (k<position-1 && temp->next!=NULL) {
		temp=temp->next;
		k++;
	}
	
	if(k<position-1){
		cout << "Position Does Not Exist " << endl;
		return head;
	}
	
	newNode->next = temp->next;
	newNode->prev = temp;
	
	if(temp->next)
		temp->next->prev = newNode;
	
	temp->next = newNode;
	return head;
}

void deleteFront(DLLNode *&head)
{
	DLLNode *temp = head;
	
	if(head == NULL){
		cout << "List Empty " << endl;
		return;
	}
	
	temp = head;
	head = head->next;
	head->prev = NULL;
	delete temp;
	
	return;
}

void deleteLast(DLLNode *&head)
{
	DLLNode *temp = head;
	DLLNode *current = head;

	if(head == NULL){
		cout << "List Empty" << endl;
		return;
	}
	
	while (current->next != NULL) {
		current = current->next;
	}
	temp = current->prev;
	//cout << "Address of current and current prev : " << current << current->prev << endl;
	//cout << "Current Next Value : " << current->next << endl;
	temp->next = current->next;
	
	delete current;
	
	return;
}

