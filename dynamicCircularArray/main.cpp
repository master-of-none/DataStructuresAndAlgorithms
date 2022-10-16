//
//  main.cpp
//  queueNormal
//
//  Created by Shrikrishna Bhat on 10/16/22.
//

#include <iostream>
#include <stdlib.h>
using namespace std;
class Queue {
public:
	int front;
	int rear;
	int capacity;
	int size;
	int *array;
	
	~Queue()
	{
		cout << "Object Deleted " << endl;
	}
	
};


Queue *createQueue (Queue* Q, int capacity);
int size(Queue *Q);
int frontElement(Queue *Q);
int rearElement(Queue *Q);
int isFull(Queue* Q);
void enQueue(Queue* Q,int data);
int deQueue(Queue *Q);
void printQueue(Queue* Q);
void deleteQueue(Queue *Q);
void resizeQueue(Queue *Q);

int main(int argc, const char * argv[]) {
	// insert code here...
	//std::cout << "Hello, World!\n";
	
	Queue *Q = NULL;
	
	cout << "Enter Queue Capacity " << endl;
	int capacity;
	cin >> capacity;
	
	Q = createQueue(Q,capacity);
	int choice,data;
	bool flag = true;
	
	do{
		cout << "Enter 1 to enQueue, 2 to deQueue, 3 to print, 4 for other operations " << endl;
		cin >> choice;
		switch (choice) {
			case 1:
				cout << "Enter data " << endl;
				cin >> data;
				enQueue(Q,data);
				break;
				
			case 2 :
				cout << "Dequeued Element is " << deQueue(Q) << endl;
				break;
			
			case 3:
				printQueue(Q);
				break;
			case 4:
				cout << "Size of queue is " << size(Q) << endl;
				break;
			default:
				deleteQueue(Q);
				flag = false;
				break;
		}
	}while(flag);
	
	return 0;
}

Queue *createQueue (Queue* Q, int capacity)
{
	Q = new Queue();
	
	if(!Q){
		return NULL;
	}
	Q->capacity = capacity;
	Q->front = Q->rear = -1;
	Q->size = 0;
	Q->array = new int[capacity];
	
	if(!Q->array)
		return NULL;
	return Q;
}

int size(Queue *Q)
{
	return Q->size;
}

int frontElement(Queue *Q)
{
	return Q->array[Q->front];
}

int rearElement(Queue *Q)
{
	return Q->array[Q->rear];
}

int isEmpty(Queue* Q)
{
	return (Q->size ==0);
}

int isFull(Queue* Q)
{
	return (Q->size == Q->capacity);
}

void enQueue(Queue* Q,int data)
{
	if(isFull(Q)){
		resizeQueue(Q);
	}
	
	else{
		Q->rear = (Q->rear+1) % Q->capacity;
		Q->array[Q->rear] = data;
		
		if(Q->front == -1)
			Q->front = Q->rear;
		
		Q->size++;
	}
}

int deQueue(Queue *Q)
{
	int data = INT_MIN;
	
	if(isEmpty(Q)){
		cout << "Queue Underflow " << endl;
		return data;;
	}
	
	data = Q->array[Q->front];
	
	//Front increases and Reaches
	if(Q->front == Q->rear){
		Q->front = Q->rear = -1;
		Q->size = 0;
	}
	
	else{
		Q->front = (Q->front +1) % Q->capacity;
		Q->size--;
	}
	return data;
}

void printQueue(Queue* Q)
{
	if (Q->front == - 1)
	   cout<<"Queue is empty"<<endl;
	   
	else {
		  cout<<"Queue elements are : ";
		  
		for (int i = Q->front; i <= Q->rear; i++)
			  cout<<Q->array[i] << " ";
		
		cout<<endl;
	   }
}

void deleteQueue(Queue *Q)
{
	if(Q){
		if(Q->array)
			delete Q->array;
		delete Q;
	}
}

void resizeQueue(Queue *Q)
{
	int size = Q->capacity;
	Q->capacity = Q->capacity * 2;
	Q->array = (int*) realloc(Q->array,sizeof(int) * Q->capacity);
	
	if(!Q->array){
		cout << "Memory Error" << endl;
		return;
	}
	
	if(Q->front > Q->rear){
		for(int i=0; i<Q->front;i++) {
			Q->array[i+size] = Q->array[i];
		}
		Q->rear = Q->rear + size;
	}
}
