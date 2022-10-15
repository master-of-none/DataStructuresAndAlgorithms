//
//  main.cpp
//  stackNormal
//
//  Created by Shrikrishna Bhat on 10/14/22.
//

#include <iostream>
#include <limits.h>
using namespace std;

struct Stack {
	int top;
	int capacity;
	int *array;
};

struct Stack *createStack(int);
int isEmpty(struct Stack*);
int size(struct Stack*);
int isFull(struct Stack*);
void push(struct Stack*, int);
int pop(struct Stack*);
int peek(struct Stack*);
void deleteStack(struct Stack*);
void print(struct Stack*);

int main(int argc, const char * argv[]) {
	// insert code here...
	//std::cout << "Hello, World!\n";
	
	int capacity,data,choice;
	bool flag = true;
	
	cout << "Enter Capacity " << endl;
	cin >> capacity;
	
	//create stack
	struct Stack *stk = createStack(capacity);
	
	do{
		cout << "Enter 1 to insert, 2 to pop, 3 to print, 4 Other operations"<< endl;
		cin >> choice ;
		
		switch (choice) {
			case 1:
				cout << "Enter Data to be pushed " << endl;
				cin >> data;
				push(stk,data);
				break;
				
			case 2:
				cout << "Popped Element is : " << pop(stk) << endl;
				break;
				
			case 3:
				if(isEmpty(stk))
					cout << "Stack is Empty " << endl;
				else
					print(stk);
				break;
			
			case 4:
				cout << "Other operations like Peek And Size of Stack" << endl;
				cout << "Top Element is : " << peek(stk) << endl;
				cout << "Size of the Stack is : " << size(stk) << endl;
				break;
				
			default:
				deleteStack(stk);
				flag=false;
				break;
		}
	}while(flag);
	
	return 0;
}

struct Stack *createStack(int capacity)
{
	struct Stack *S = new Stack();
	
	if(!S){
		cout << "Error in stack Creation " << endl;
		return NULL;
	}
	
	S->capacity = capacity;
	S->top = -1;
	S->array = new int[capacity];
	
	if(!S->array){
		cout << "Error in Stack Array Creation" << endl;
		return NULL;
	}
	
	return S;
}

int isEmpty(struct Stack *S)
{
	return (S->top == -1);
}

int size(struct Stack *S)
{
	return (S->top +1);
}

int isFull(struct Stack *S)
{
	return (S->top == S->capacity - 1);
}

void push(struct Stack *S, int data)
{
	if(isFull(S))
		cout << "Stack Overflow " << endl;
	else
		S->array[++S->top] = data;
	
}

int pop(struct Stack *S)
{
	if(isEmpty(S)){
		cout << "Stack Underflow " << endl;
		return INT_MIN;
	}
	
	else
		return( S->array[S->top--]);
}


int peek(struct Stack *S)
{
	if(isEmpty(S)){
		cout << "Stack Underflow " << endl;
		return INT_MIN;
	}
	
	else
		return( S->array[S->top]);
}

void deleteStack(struct Stack *S)
{
	if(S){
		if(S->array){
			delete S->array;
		}
		
		delete S;
	}
}

void print(struct Stack * S)
{
	if(isEmpty(S)){
		cout << "Stack Underflow " << endl;
		return;
	}
	
	cout << "Contents of Stack Are :" << endl;
	for(int i=S->top;i>=0;--i){
		cout << S->array[i] << " ";
	}
	cout << endl;
}
