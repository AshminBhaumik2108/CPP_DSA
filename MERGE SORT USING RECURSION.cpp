// MERGE SORT USING RECURSION:-
/*
#include<iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high){
	int i, j, k=0;
	int n1 = mid - low + 1;
	int n2 = high - mid;
	// create temp arrays
	int L[n1], R[n2];

		for(i=low;i<=mid;i++)
		{
		    L[k++]=arr[i];
		}
		k=0;
		for(i=mid+1;i<=high;i++)
		{
		    R[k++]=arr[i];
		}

	i = 0;	j = 0;	k = low;        //important
	while (i < n1 && j < n2)
	{
		if (L[i] < R[j])
		{
			arr[k++] = L[i];
			i++;
		}
		else
		{
			arr[k++] = R[j];
			j++;
		}

	}
	// Copy the remaining elements of L[], if there are any
	while (i < n1)
	{
		arr[k++] = L[i];
		i++;
	}
	// Copy the remaining elements of R[], if there are any
	while (j < n2)
	{
		arr[k++] = R[j];
		j++;
	}
}
void mergeSort(int arr[], int low, int high){
	if (low < high) {
		int mid = (low + high)/ 2;
		mergeSort(arr, low, mid);
		mergeSort(arr, mid + 1, high);
		merge(arr, low, mid, high);
	}
}
int main()
{
	int n;
	cout<<"Enter the range: ";
	cin>>n;
	int arr[n];
	cout<<"Enter the elements: ";
	for(int i=0;i<n;i++)
	{
	    cin>>arr[i];
	}
	mergeSort(arr, 0, n-1);
	cout<<"\nSorted array is: ";
    for(int i=0;i<n;i++)
	cout<<arr[i]<<" ";
	return 0;
}*/

/*
#include<iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high)
{
    int n1 = mid-low+1;
    int n2 = high-mid;
    int i, j, k=0;
    int L[n1], R[n2];

    for(i=low; i<=mid; i++)
    {
        L[k++] = arr[i];
    }
    k=0;
    for(i=mid+1; i<=high; i++)
    {
        R[k++] = arr[i];
    }

    i=0; j=0; k=low;

    while(i<n1 && j<n2)
    {
        if(L[i] < R[j])
        {
            arr[k++] = L[i];
            i++;
        }
        else
        {
            arr[k++] = R[j];
            j++;
        }
    }

    while(i<n1)
    {
        arr[k++] = L[i];
        i++;
    }

    while(j<n2)
    {
        arr[k++] = R[j];
        j++;
    }
}

void mergesort(int arr[], int low, int high)
{
   if(low < high) // important
    {
        int mid = (low+high)/2;
        mergesort(arr, low, mid);
        mergesort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{
	int n;
	cout<<"Enter the range: ";
	cin>>n;
	int arr[n];
	cout<<"Enter the elements: ";
	for(int i=0;i<n;i++)
	{
	    cin>>arr[i];
	}
	mergesort(arr, 0, n-1);
	cout<<"\nSorted array is: ";
    for(int i=0;i<n;i++)
	cout<<arr[i]<<" ";
	return 0;
} */


// ONLY FOR CHECKING THE ELEMENTS TRICK:-
/*
#include<iostream>
using namespace std;

void display(int arr[])
{
    cout<<"Enter the changing element: ";
    int n; cin>>n;
    arr[1] = n;
}

int main()
{
    int n; cout<<"Enter total: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements: ";
    for(int i=0; i<n; i++)
    {
        cout<<"*: ";
        cin>>arr[i];
    }
    display(arr);
    cout<<endl<<"Elements to display: "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
} */


#include<iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high)
{
    int n1, n2;
    n1 = mid-low+1;
    n2 = high-mid;
    int a1[n1], a2[n2];
    int i, j, k=0;

    for(i=low; i<=mid; i++)
    {
        a1[k++] = arr[i];
    }
    k=0;
    for(i=mid+1; i<=high; i++)
    {
        a2[k++] = arr[i];
    }

    //CHANGING THE ELEMENTS ***important....
    i=0, j=0, k=low;

    while(i<n1 && j<n2)
    {
        if(a1[i] < a2[j])
        {
            arr[k++] = a1[i++];
        }
        else
        {
            arr[k++] = a2[j++];
        }
    }
    while(i<n1)
    {
        arr[k++] = a1[i++];
    }
    while(j<n2)
    {
        arr[k++] = a2[j++];
    }
}

void mergesort(int arr[], int low, int high)
{
    if(low < high)
    {
        int mid = (low+high)/2;
        mergesort(arr, low, mid);
        mergesort(arr, mid+1, high);

        merge(arr, low, mid, high);
    }
}

int main()
{
    int n;
    cout<<"Enter the Number of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements: "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<"*: ";
        cin>>arr[i];
    }
    mergesort(arr, 0, n-1);
    cout<<"The elements in Sorted order: ";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}


















