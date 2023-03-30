#include <iostream>
using namespace std;
void show(int arr[], int size)
{
    for(int i=0; i<size; i++)
    {
        cout<<arr[i]<<", ";
    }
}
void swap(int arr[], int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
int partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int i=l-1;
    for(int j=l; j<r; j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i+1, r);
    return i+1;
}

void quickSort(int arr[], int l, int r)
{
    if(l<r)
    {
        int pi = partition(arr, l, r);
        quickSort(arr, l, pi-1);
        quickSort(arr, pi+1, r);
    }
}
int main() {
    int arr[5];
    cout<<"Enter elements in Array: "<<endl;
    for(int i=0; i<5; i++)
    {
        cin>>arr[i];
    }
    cout<<"Original array is : "<<endl;
    show(arr, 5);
    cout<<endl;
    cout<<"Sorted array is: "<<endl;
    quickSort(arr, 0, 4);
    show(arr, 5);

    return 0;
}