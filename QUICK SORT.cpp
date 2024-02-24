/*
#include<iostream>
using namespace std;
int i, j, pivot;

int partision(int a[], int low, int high)
{
    pivot = a[low];
    i=low;
    j=high;
    while(i<j) // REMEMBER
    {
      do
      {
        i++;
      }while(a[i]<pivot);
      do
      {
        j--;
      }while(a[j]>pivot);
      if(i<j)
      {
        swap(a[i], a[j]);
      }
    }
    swap(a[low], a[j]);
    return j;
}

void quicksort(int a[], int low, int high)
{
    if(low < high)
    {
        int j = partision(a, low, high);
        quicksort(a, low, j);
        quicksort(a, j+1, high);
    }
}

int main()
{
    int x;
    cout<<"Enter the Range: ";
    cin>>x;
    int n = x+1; int a[n];
    cout<<"Enter the elements: ";
    for(i=0; i<x; i++)
    {
        cin>>a[i];
    }
    a[i] = 999;

    quicksort(a, 0, n-1);

    cout<<"Sorted elements are: ";
    for(i=0; i<x; i++)
    {
        cout<<a[i]<<" ";
    }
} */

#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void recursiveQuickSort(int arr[], int n) {
    quickSort(arr, 0, n - 1);
}

int main() {
    int n;
    cin >> n;

    int years[n];

    for (int i = 0; i < n; i++) {
        cin >> years[i];
    }

    recursiveQuickSort(years, n);

    for (int i = 0; i < n; i++) {
        cout << years[i] << " ";
    }

    return 0;
}
























