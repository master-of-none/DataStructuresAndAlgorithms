#include<iostream>
#include<stdlib.h>

using namespace std;
void printArray(int[],int);
void insertionSort(int[],int);
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

    printArray(array,n);
    cout << endl;

    insertionSort(array,n);

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

void insertionSort(int array[], int n)
{
    for(int i=1; i<n; i++){
        for(int j=i; j>0 && array[j] < array[j-1]; j--) {
            swap(array[j],array[j-1]);

        }
    }
}