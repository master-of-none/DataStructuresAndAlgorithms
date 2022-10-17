//
//  main.cpp
//  binaryHeap
//
//  Created by Shrikrishna Bhat on 10/17/22.
//

#include <iostream>
using namespace std;
void swap(int *,int*);
void heapify(int [],int,int);
void buildHeap(int [],int);
void printHeap(int [],int);

int main(int argc, const char * argv[]) {
	// insert code here...
	//std::cout << "Hello, World!\n";
	
	int size;
	cout << "Enter Size of the Array : " << endl;
	cin >> size;
	
	int array[size];
	
	for(int i=0;i<size;i++){
		cout << "Enter " << i << "th element " << endl;
		cin >> array[i];
	}
	
	buildHeap(array,size);
	printHeap(array,size);
	
	return 0;
}

void buildHeap(int arr[], int N)
{
	int startIdx = (N/2) - 1;
	
	for(int i=startIdx; i>=0; i--){
		heapify(arr, N, i);
	}
}

void printHeap(int arr[],int N)
{
	cout << "Array Representation of Heap is : " << endl;
		
	for(int i=0;i<N;i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

void heapify(int arr[], int N, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	
	if(l < N && arr[l] > arr[largest])
		largest = l;
	
	if(r < N && arr[r] > arr[largest])
		largest = r;
	
	if(largest != i){
		swap(&arr[i],&arr[largest]);
		
		heapify(arr,N,largest);
	}
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
