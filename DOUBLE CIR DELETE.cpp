
#include<bits/stdc++.h>
using namespace std;

struct link
{
    int data;
    struct link *next;
    struct link *prev;
};

struct link *start = NULL;
struct link *node;
struct link *current;

void create()
{
    int n;
    cout<<"Enter number of node: "; cin>>n;
    cout<<"Enter Elements: ";
    for(int i=0; i<n; i++)
    {
        node = (struct link *)malloc(sizeof(struct link));
        cin>>node->data;
        if(start == NULL)
        {
            start = node;
            current = node;
            node->next = start;
            node->prev = start;
        }
        else
        {
            current->next = node;
            node->prev = current;
            node->next = start;
            start->prev = node;
            current = node;
        }
    }

}


int loc;
void del()
{
    cout<<"Enter Location: ";
    cin>>loc;
    cout<<"Location: "<<loc<<endl;
    if(loc == 1)
    {
        struct link *ptr = start->prev;
        struct link *cur = start;
        ptr->next = cur->next;
        cur->next->prev = ptr;
        start = ptr->next;
    }
    else
    {
        struct link *ptr = start;
        struct link *cur = ptr->next;
        for(int i=0; i<loc-2; i++)
        {
            ptr = ptr->next;
            cur = cur->next;
        }
        ptr->next = cur->next;
        cur->next->prev = ptr;
    }

}

void display()
{
    struct link *ptr = start;
    do
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    } while(ptr != start);
    cout<<endl<<"Reverse: "<<endl;
    struct link *ptr1 = start->prev;
    do
    {
        cout<<ptr1->data<<" ";
        ptr1 = ptr1->prev;
    } while(ptr1 != start->prev);
}

int main()
{
    create();
    del();
    display();
    return 0;
}

// UNION:-
/*
#include <iostream>
using namespace std;

// Defining a Union
union GFG {
    int Geek1;
    char Geek2;
    float Geek3;
};

// Driver Code
int main()
{
    // Initializing Union
    GFG G1;

    G1.Geek1 = 34;

    // Printing values
    cout << "The first value at "
         << "the allocated memory : " << G1.Geek1 << endl;

    G1.Geek2 = 'G';

    cout << "The next value stored "
         << "after removing the "
         << "previous value : " << G1.Geek2 << endl;

    G1.Geek3 = 34.34;

    cout << "The Final value value "
         << "at the same allocated "
         << "memory space : " << G1.Geek3 << endl;
    return 0;
} */















