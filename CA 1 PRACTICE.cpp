/*
#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Number of Elements in array: "; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<"Inserted array: "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    /// Selection sort.....
    for(int i=0; i<n; i++)
    {
        int small = arr[i];
        int loc = i;
        for(int j=i+1; j<n; j++)
        {
            if(arr[j]<small)
            {
                small = arr[j];
                loc = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[loc];
        arr[loc] = temp;
    }

    // Sorted Array:-
    cout<<endl<<"Sorted Array: ";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
} */

// INSERTION SORT:-
/*
#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter num: "; cin>>n; int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    cout<<"Inserted array: "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    //Insertion sort:-

    for(int i=0; i<n; i++)
    {
        int current = a[i];
        int j = i-1;
        while(a[j]>current && j>=0)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = current;
    }
    cout<<endl<<"Insertion sort: "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }

} */

//SORTING IN LINKED LIST:-

#include<iostream>
using namespace std;

struct link
{
    int data;
    struct link *next;
};

struct link *start = NULL;
struct link *node;
struct link *current;
int n;

void insert1()
{
    cout<<"Insert the number of items in linked list: "; cin>>n;
    for(int i=0; i<n; i++)
    {
        node = new link;
        cin>>node->data;
        node->next = NULL;
        if(start == NULL)
        {
            start = node;
            current = node;
        }
        else
        {
            current->next = node;
            current = node;
        }
    }
    cout<<"Insertion Linked List: ";
    struct link *ptr = start;
    while(ptr != NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
}

void Bubblesort()
{

    for(int i=0; i<n-2; i++)
    {
        struct link *ptr = start;
        struct link *cur = start->next;
        while(cur != NULL)
        {
            if(ptr->data > cur->data)
            {
                int temp = ptr->data;
                ptr->data = cur->data;
                cur->data = temp;
            }
            ptr = ptr->next;
            cur = cur->next;
        }
    }
    cout<<endl<<"Bubble Sort Linked List: ";
    struct link *ptr1 = start;
    while(ptr1 != NULL)
    {
        cout<<ptr1->data<<" ";
        ptr1 = ptr1->next;
    }
}


int main()
{
    insert1();
    Bubblesort();
}

















