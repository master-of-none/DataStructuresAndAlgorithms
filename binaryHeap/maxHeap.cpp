#include<iostream>
#include<vector>
using namespace std;

void heapify(int [], int, int);
void buildHeap(int [], int);
void printHeap(int [], int);

int main()
{
    int n;
    cout << "Enter size of array " << endl;
    cin >> n;
    int array[n];

    cout << "Enter array elements"<<endl;;

    for(int i=0; i<n;i++){
        cin >> array[i];
    }

    /*
        Example Heap
        Binary Tree Representation of input array
                  1
        		 / \
         		 3	 5
         	 / \	 / \
         	 4	 6 13 10
          / \ / \
         9 8 15 17
    */

    buildHeap(array, n);
    printHeap(array, n);

    /*
        Final heap
            17
	 	    / \
	 	    15	 13
	 		/ \	 / \
	 	    9  6 5 10
	 	    / \ / \
	 	    4 8 3 1
    */

    return 0;
}
void printHeap(int arr[], int N)
{
    cout << "Array Representation of Heap is : " << endl;

    for(int i=0; i < N; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void buildHeap(int arr[], int N)
{
    int start = (N/2) - 1;

    for(int i = start; i>=0; i--){
        heapify(arr, N, i);
    }
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
        swap(arr[i], arr[largest]);
        heapify(arr, N, largest);
    }    

}