//
//  main.cpp
//  queueLinkedList
//
//  Created by Shrikrishna Bhat on 10/15/22.
//

#include <iostream>
using namespace std;

class ListNode {
public:
	int data;
	ListNode *next;
	
	~ListNode()
	{
		cout << "Deleting List Node Object " << endl;
	}
};

class Queue {
public:
	ListNode *front;
	ListNode *rear;
	
	~Queue()
	{
		cout << "Deleting Queue Object" << endl;
	}
};

Queue *createQueue(Queue* Q, int capacity);
int size(Queue *Q);
int frontElement(Queue *Q);
int rearElement(Queue *Q);
void isEmpty(Queue *Q);
void enQueue(Queue *Q,int num);
void deQueue(Queue *Q);
void printQueue(Queue *Q);
void deleteQueue(Queue* Q);

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
				deQueue(Q);
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

Queue *createQueue(Queue* Q, int capacity)
{
	ListNode *temp;
	Q = new Queue();
	
	if(!Q){
		cout << "Memory Error " << endl;
		return NULL;
	}
	temp = new ListNode();
	
	Q->front = Q->rear = NULL;
	return Q;
}

int size(Queue *Q)
{
	ListNode *temp = Q->front;
	int count = 0;
	
	if(Q->front == NULL && Q->rear == NULL)
		return 0;
	
	while (temp!=Q->rear) {
		count++;
		temp = temp->next;
	}
	if(temp == Q->rear)
		count ++;
	
	return count;
}

int frontElement(Queue *Q)
{
	return Q->front->data;
}

int rearElement(Queue *Q)
{
	return Q->rear->data;
}

void isEmpty(Queue *Q)
{
	if(Q->front == NULL && Q->rear == NULL)
		cout << "Empty Queue" << endl;
	
	else
		cout << "Not an empty Queue" << endl;
}

void enQueue(Queue *Q,int num)
{
	ListNode *temp;
	temp = new ListNode();
	temp->data = num;
	temp->next = NULL;
	
	if(Q->rear == NULL){
		Q->front = Q->rear = temp;
	}
	else {
		Q->rear->next = temp;
		Q->rear = temp;
	}
}

void deQueue(Queue *Q)
{
	ListNode *temp;
	
	if(Q->front == NULL){
		cout << "Empty Queue " << endl;
		return;
	}
	else{
		temp = Q->front;
		Q->front = Q->front->next;
		
		if(Q->front == NULL)
			Q->rear = NULL;
		
		cout << "Removed Element is : " << temp->data << " ";
		delete temp;
	}
}

void printQueue(Queue *Q)
{
	ListNode *temp = Q->front;
	
	if((Q->front == NULL) && (Q->rear == NULL)){
		cout << "Empty Queue" << endl;
		return;
	}
	
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

void deleteQueue(Queue* Q)
{
	ListNode *temp;
	
	while (Q->front) {
		temp = Q->front;
		cout << "Deleted element is : " << temp->data << " ";
		Q->front = Q->front->next;
		delete temp;
	}
	delete Q;
}
