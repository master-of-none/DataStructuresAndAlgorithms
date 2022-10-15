//
//  main.cpp
//  circularLinkedList
//
//  Created by Shrikrishna Bhat on 10/14/22.
//

#include <iostream>
using namespace std;

/*class CLLNode{
	public:
		int data;
		CLLNode *next;
};
*/

struct CLLNode {
	int data;
	struct CLLNode *next;
};
struct CLLNode *head = NULL;

void print(CLLNode *);
void insertAtEnd(CLLNode**,int);
void insertAtBeginning(CLLNode**,int);

int main(int argc, const char * argv[]) {
	// insert code here...
	//std::cout << "Hello, World!\n";
	
	//head->next = head;
	
	int choice,data;
	bool flag = true;
	do {
		cout << "Enter 1 to insert at Beginning, 2 to insert at end, 3 to print" << endl;
		cout << "Enter 4 to delete first node, 5 to delete last node, Anything else to exit " << endl;
		cin >> choice;
		
		switch (choice) {
			case 1:
				cout << "Enter Data " << endl;
				cin >> data;
				insertAtBeginning(&head,data);
				break;
				
			case 2:
				cout << "Enter Data " << endl;
				cin >> data;
				insertAtEnd(&head, data);
				break;
			
			case 3:
				print(head);
				break;
				
			case 4:
				//deleteFront(head);
				break;
				
			case 5:
				//deleteLast(head);
				break;
			
			case 6:
				
				break;
				
			default:
				flag = false;
				break;
		}
	}while(flag);
	
	return 0;
}

void print(struct CLLNode *head)
{
	struct CLLNode *cur = head;
	if(head == NULL){
		cout << "Empty List " << endl;
		return;
	}
	
	do{
		cout << cur->data << " ";
		cur = cur->next;
	}while(cur!=head);
	cout << endl;
}

void insertAtEnd(struct CLLNode **head, int data)
{
	struct CLLNode *current = *head;
		struct CLLNode *newNode = (struct CLLNode *) (malloc(sizeof(struct CLLNode)));
		if(!newNode) {
			printf("Memory Error");
			return;
		}
		newNode->data = data;
		while (current->next != *head)
			current = current->next;

		newNode->next = newNode;

		if(*head ==NULL)
			*head = newNode;
		else {
			newNode->next = *head;
			current->next = newNode;
		}
}

void insertAtBeginning(struct CLLNode **head, int data)
{
	struct CLLNode *current = *head;
	struct CLLNode *newNode = new CLLNode;
	
	if(!newNode){
		cout << "Memory Error" << endl;
		return;
	}
	newNode->data = data;
	newNode->next = newNode;
	
	if(current == NULL){
		*head = newNode;
		return;
	}
	while(current->next != *head){
		current = current->next;
	}
	newNode->next = *head;
	current->next = newNode;
	*head=newNode;
}
