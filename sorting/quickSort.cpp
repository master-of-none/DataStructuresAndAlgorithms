#include<iostream>
using namespace std;

void printArray(int array[], int n);
void quickSort(int array[], int low, int high);
int partition(int array[], int low, int high);
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

    quickSort(array,0,n-1);

    cout << "Sorted Array" << endl;
    printArray(array,n);
    cout << endl;
}

void printArray(int array[], int n)
{
     for(int i=0;i<n;i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

void quickSort(int array[], int low, int high)
{
    if(low < high){
        int pi = partition(array,low,high);

        quickSort(array, low, pi - 1);

        quickSort(array, pi + 1, high);
    }
}

int partition(int array[], int low, int high)
{
    int pivot = array[high];

    int i = (low - 1);

    for(int j = low; j < high; j++){
        if(array[j] <= pivot){
            i++;

            swap(array[i], array[j]);
        }
    }

    swap(array[i+1], array[high]);

    return (i+1);
}