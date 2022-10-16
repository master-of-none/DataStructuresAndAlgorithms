//
//  main.cpp
//  stackLinkedList
//
//  Created by Shrikrishna Bhat on 10/15/22.
//

#include <iostream>
#include<stdlib.h>
#include <limits.h>
using namespace std;


class ListNode{
public:
	int data;
	ListNode *next;
	
};

class Stack {
public:
	ListNode *top;
};

Stack *createStack();
void push(Stack*,int);
int pop(Stack*);
int isEmpty(Stack*);
int peek(Stack*);
int size(Stack*);
void deleteStack(Stack*);
void print(Stack*);

int main(int argc, const char * argv[]) {
	// insert code here...
	//std::cout << "Hello, World!\n";
	
	int data,choice;
	bool flag = true;
	Stack *stk = createStack();
	
	do {
		cout << "Enter 1 to push, 2 to pop, 3 to print, 4 to other operations and other to exit" << endl;
		cin >> choice;
		
		switch (choice) {
			case 1:
				cout << "Enter Data " << endl;
				cin >> data;
				push(stk,data);
				break;
				
			case 2:
				cout << "Popped Element is " << pop(stk) << endl;
				break;
			
			case 3:
				if(isEmpty(stk))
					cout << "Stack is Empty " << endl;
				else
					print(stk);
				break;
			
			case 4:
				cout << "Top Element is " << peek(stk) << endl;
				cout << "Size of Stack is " << size(stk) << endl;
				break;
			default:
				deleteStack(stk);
				flag = false;
				break;
		}
	}while(flag);
	
	return 0;
}

Stack *createStack()
{
	Stack *stk;
	stk = new Stack();
	stk->top = NULL;
	
	return stk;
}

void push(Stack *stk,int data)
{
	ListNode *temp;
	temp = new ListNode();
	
	if(!temp){
		cout << "Stack or Heap Overflow" << endl;
		return;
	}
	
	temp->data = data;
	temp->next = stk->top;
	stk->top = temp;
}

int size(Stack *stk)
{
	int count = 0;
	ListNode *temp;
	
	if(isEmpty(stk))
		return 0;
	
	temp = stk->top;
	
	while(temp){
		count ++;
		temp = temp->next;
	}
	return count;
}

int isEmpty(Stack *stk)
{
	return stk->top == NULL;
}

int pop(Stack *stk)
{
	int data;
	ListNode *temp;
	
	if(isEmpty(stk)){
		return INT_MIN;
	}
	temp = stk->top;
	
	stk->top = stk->top->next;
	data = temp->data;
	delete (temp);
	
	return data;
}

int peek(Stack *stk)
{
	if(isEmpty(stk))
		return INT_MIN;
	return stk->top->data;
}

void deleteStack(Stack *stk)
{
	ListNode *temp, *p;
	
	p = stk->top;
	
	while (p) {
		temp = p->next;
		p = p->next;
		delete temp;
	}
	delete stk;
}

void print(Stack *stk)
{
	ListNode *temp;
	if(isEmpty(stk)){
		cout << "Empty Stack " << endl;
	}
	
	else{
		cout << "Elements in Stack are : " << endl;
		temp = stk->top;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
}
