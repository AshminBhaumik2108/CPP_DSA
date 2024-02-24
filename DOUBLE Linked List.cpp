// WAP to create a double circular linked list  and display all the output........
/*
#include<iostream>
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

void display()
{
    struct link *ptr = start;
    do
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    } while(ptr != start);
}

int main()
{
    create();
    display();
    return 0;
}
*/


// WAP to insert a number in particular position of a double circular linked list.....


#include<iostream>
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

void insert1()
{
    int loc;
    node = (struct link *)malloc(sizeof(struct link));
    cout<<"Enter the number: "; cin>>node->data;
    cout<<"Enter the location: "; cin>>loc;
    struct link *ptr = start;
    current = ptr->next;
    for(int i=0; i<loc-2; i++)
    {
        ptr = ptr->next;
        current = current->next;
    }
    ptr->next = node;
    node->prev = ptr;
    node->next = current;
    current->prev = node;
}

void display()
{
    struct link *ptr = start;
    do
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    } while(ptr != start);
}

int main()
{
    create();
    display();
    return 0;
}















