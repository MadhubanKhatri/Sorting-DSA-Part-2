#include<iostream>
using namespace std;

void merge(int arr[], int l, int mid, int r)
{
  int n1 = mid+1 - l;
  int n2 = r-mid;
  int a[n1], b[n2];  //temp arrays

  for(int i=0; i<n1; i++)
  {
    a[i] = arr[l+i];
  }
  for(int i=0; i<n2; i++)
  {
    b[i] = arr[mid+1+i];
  }

  int i=0;
  int j=0;
  int k=l;

  while(i<n1 && j<n2)
  {
    if(a[i]<b[j])
    {
      arr[k] = a[i];
      i++;
    }
    else
    {
      arr[k] = b[j];
      j++;
    }
    k++;
  }

  while(i<n1)
  {
    arr[k] = a[i];
    i++;
    k++;
  }

  while(j<n2)
  {
    arr[k] = b[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int l, int r)
{
  if(l<r)
  {
    int mid = (l+r)/2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);

    merge(arr, l, mid, r);
  }
}

int main()
{
  int arr[6] = {5,40,31,2,1,-2};
  mergeSort(arr, 0, 5);

  for (int i=0; i<6; i++)
  {
    cout<<arr[i]<<", ";
  }
  return 0;
}