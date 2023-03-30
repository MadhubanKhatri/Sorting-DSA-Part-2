In the last post of Data Structure & Algorithm series, we discussed what is Algorithm, What is Sorting & Types of Sorting algorithm. We discussed **Bubble Sort**, **Selection Sort** and **Insertion Sort**.

In this post, we will discuss **Merge Sort**, **Quick Sort** and **Shell Short**. So let's start...

---

## 1.) Merge Sort
Merge Sort is one of the most popular sorting algorithms that is based on the principle of _Divide and Conquer Algorithm_.

Here, a problem is divided into multiple sub-problems. Each sub-problem is solved individually. Finally, sub-problems are combined to form the final solution.

![Merge Sort](https://dev-to-uploads.s3.amazonaws.com/uploads/articles/x6dmhykreq80h1qblcfz.png)
```c
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
```
---
## 2.) Quick Sort
Quicksort is a sorting algorithm based on the divide and conquer approach where

An array is divided into subarrays by selecting a pivot element (element selected from the array).

While dividing the array, the pivot element should be positioned in such a way that elements less than pivot are kept on the left side and elements greater than pivot are on the right side of the pivot.
The left and right subarrays are also divided using the same approach. This process continues until each subarray contains a single element.
At this point, elements are already sorted. Finally, elements are combined to form a sorted array.
```c
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
```

---
## 3.) Shell Sort
Shell sort is a generalized version of the insertion sort algorithm. It first sorts elements that are far apart from each other and successively reduces the interval between the elements to be sorted.

The interval between the elements is reduced based on the sequence used.The performance of the shell sort depends on the type of sequence used for a given input array.
```c
// C++ implementation of Shell Sort
#include <iostream>
using namespace std;

/* function to sort arr using shellSort */
int shellSort(int arr[], int n)
{
	for (int gap = n/2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < n; i++)
		{
			int temp = arr[i];
			int j;			
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
				arr[j] = arr[j - gap];
			arr[j] = temp;
		}
	}
	return 0;
}

void printArray(int arr[], int n)
{
	for (int i=0; i<n; i++)
		cout << arr[i] << " ";
}

int main()
{
	int arr[] = {12, 34, -50, 3}, i;
	int n = sizeof(arr)/sizeof(arr[0]);

	cout << "Array before sorting: \n";
	printArray(arr, n);

	shellSort(arr, n);

	cout << "\nArray after sorting: \n";
	printArray(arr, n);

	return 0;
}
```

---
I hope you understand what is Algorithm, Sorting and Types of Sorting. We will discuss more about Data Structure & Algorithm in next few posts.
