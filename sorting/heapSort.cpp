#include<iostream>
using namespace std;

void heapify(int [], int, int);
void heapSort(int [],int);
void printArray(int [], int);

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

    cout << "Unsorted Array" << endl;
    printArray(array,n);
    cout << endl;

    heapSort(array,n);
    cout << "Sorted Array" << endl;
    printArray(array,n);
    cout << endl;
}

void printArray(int array[],int n)
{
    for(int i=0;i<n;i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

void heapSort(int arr[], int n)
{
    for(int i = n/2-1; i>=0; i--)
        heapify(arr, n, i);
    
    for(int i=n-1; i>=0; i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left<n && arr[left] > arr[largest])
        largest = left;
    
    if(right<n && arr[right] > arr[largest])
        largest = right;
    
    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}