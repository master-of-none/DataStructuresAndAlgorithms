#include<iostream>
#include<stdlib.h>

using namespace std;
void printArray(int[],int);
void selectionSort(int[],int);
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

    cout << "Unsorted Array\n";
    printArray(array,n);
    cout << endl;

    selectionSort(array,n);

    cout << "Sorted Array\n";
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

void selectionSort(int array[], int n)
{
    int i,j;
    for(i=0;i <n; i++){
        int min = i;
        for(int j=i+1; j<n; j++){
            if(array[j] < array[min])
                min = j;
        }
        swap(array[i],array[min]);
    }
}