// WAP to delete the root of a maxheap by creating it..............
/
#include<iostream>
using namespace std;

void hipify(int a[], int n, int index)
{
    int largeindex = index;
    int L = 2*index+1;
    int R = 2*index+2;

    if(L<n && a[L]>a[largeindex])
    {
        largeindex = L;
    }
    if(R<n && a[R]>a[largeindex])
    {
        largeindex = R;
    }
    if(largeindex != index)
    {
        swap(a[largeindex], a[index]);
        hipify(a, n, largeindex);
    }

}

void build_heap(int a[], int n)
{
    int k;
    for(k=(n/2)-1; k>=0; k--)
    {
        hipify(a, n, k);
    }
}

int main()
{
    int a[30], n;
    cout<<"Enter range: ";
    cin>>n;
    cout<<"Enter all the elements: ";
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    build_heap(a, n);
    cout<<"Max heap created Successfully......"<<endl;
    cout<<"MAXheap: ";
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    //sort....
    for(int i = n-1; i>0; i--)
    {
        swap(a[i], a[0]);
        hipify(a, i, 0);
    }
    cout<<"\nSorted Heap: ";
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
} */

// Process of Sorting heap in 2nd way.............

/*
#include<iostream>
using namespace std;

void hipify(int a[], int n, int index)
{
    int largeindex = index;
    int L = 2*index+1;
    int R = 2*index+2;

    if(L<n && a[L]>a[largeindex])
    {
        largeindex = L;
    }
    if(R<n && a[R]>a[largeindex])
    {
        largeindex = R;
    }
    if(largeindex != index)
    {
        swap(a[largeindex], a[index]);
        hipify(a, n, largeindex);
    }

}

void build_heap(int a[], int n)
{
    int k;
    for(k=(n/2)-1; k>=0; k--)
    {
        hipify(a, n, k);
    }

    cout<<"MaxHeap: ";
    for(int i=n-1; i>=0; i--)
    {
        cout<<a[i]<<" ";
    }
    // sorting an  element:-
    for(int i = n-1; i>0; i--)
    {
        swap(a[i], a[0]);
        hipify(a, i, 0);
    }
}

int main()
{
    int a[30], n;
    cout<<"Enter range: ";
    cin>>n;
    cout<<"Enter all the elements: ";
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    build_heap(a, n);

    //delete....
    cout<<"\nSorted Heap: ";
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";

    }
} */


// WAP to delete the root of a maxheap by creating it..............
/*
#include<iostream>
using namespace std;

void min_hipify(int a[], int n, int index)
{
    int largeindex = index;
    int L = 2*index+1;
    int R = 2*index+2;

    if(L<n && a[L]<a[largeindex])
    {
        largeindex = L;
    }
    if(R<n && a[R]<a[largeindex])
    {
        largeindex = R;
    }
    if(largeindex != index)
    {
        swap(a[largeindex], a[index]);
        min_hipify(a, n, largeindex);
    }

}

void build_heap(int a[], int n)
{
    int k;
    for(k=(n/2)-1; k>=0; k--)
    {
        min_hipify(a, n, k);
    }
}

int main()
{
    int a[30], n;
    cout<<"Enter range: ";
    cin>>n;
    cout<<"Enter all the elements: ";
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    build_heap(a, n);
    cout<<"Max heap created Successfully......"<<endl;
    cout<<"MAXheap: ";
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    //sort....
    for(int i = n-1; i>0; i--)
    {
        swap(a[i], a[0]);
        min_hipify(a, i, 0);
    }
    cout<<"\nSorted Heap: ";
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
} */

// Delete an element .....

#include<iostream>
using namespace std;

void min_hipify(int a[], int n, int index)
{
    int largeindex = index;
    int L = 2*index+1;
    int R = 2*index+2;

    if(L<n && a[L]>a[largeindex])
    {
        largeindex = L;
    }
    if(R<n && a[R]>a[largeindex])
    {
        largeindex = R;
    }
    if(largeindex != index)
    {
        swap(a[largeindex], a[index]);
        min_hipify(a, n, largeindex);
    }

}

void build_heap(int a[], int n)
{
    int k;
    for(k=(n/2)-1; k>=0; k--)
    {
        min_hipify(a, n, k);
    }
}

void delete_heap(int a[], int del, int n)
{
    int index;
    for(int i=0; i<n; i++)
    {
        if(a[i] == del)
        {
            index = i;
            swap(a[i], a[n-1]);
        }
    }
    min_hipify(a, n, index);
}

int main()
{
    int a[30], n;
    cout<<"Enter range: ";
    cin>>n;
    cout<<"Enter all the elements: ";
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    build_heap(a, n);
    cout<<"Heapified: ";
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\nEnter element to delete: ";
    int del; cin>>del;
    delete_heap(a, del, n);
    cout<<"\nDelete Element Heap: ";
    for(int i=0; i<n-1; i++)
    {
        cout<<a[i]<<" ";
    }
}


















