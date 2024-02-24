// WAP to sort the elements of a single linked list:-
/*
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

void create()
{

    cout<<"*-: ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        node = new link();
        cin>>node->data;
        node->next = NULL;
        if(start == NULL)
        {
            current = node;
            start = node;
        }
        else
        {
            current->next = node;
            current = node;
        }
    }
}

void sorting()
{
    int temp;
    for(int i=0; i<n-1; i++)
    {
        link *ptr = start;
        current = ptr->next;
        while(current!=NULL)
        {
            if(current->data < ptr->data)
            {
                temp = current->data;
                current->data = ptr->data;
                ptr->data = temp;
            }
            ptr = ptr->next;
            current = current->next;
        }
    }
}

void display()
{
    struct link *p = start;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
}

int main()
{
    create();
    sorting();
    display();
} */

// WAP TO accept one sorted linked list from user then insert a number in its proper place

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

void create()
{

    cout<<"*-: ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        node = new link();
        cin>>node->data;
        node->next = NULL;
        if(start == NULL)
        {
            current = node;
            start = node;
        }
        else
        {
            current->next = node;
            current = node;
        }
    }
}

void sorting()
{
    struct link *ptr = start;
    struct link *node;
    current = ptr->next;
    node = new link;
    cout<<"***";
    cin>>node->data;

    while(current!=NULL)
    {
        if(current->data > node->data)
        {
            ptr->next = node;
            node->next = current;
        }
        ptr = ptr->next;
        current = current->next;
    }
}

void display()
{
    struct link *p = start;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
}

int main()
{
    create();
    sorting();
    display();
}















