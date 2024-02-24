/*

#include<iostream>
using namespace std;

struct link
{
    int data;
    struct link *next;
};

struct link *start = NULL;
struct link *current;
struct link *node;
int n;

void create()
{
    cout<<"How many Nodes: ";
    cin>>n;
    cout<<"Enter Elements: ";
    for(int i=0; i<n; i++)
    {
        node = (struct link *)malloc(sizeof(struct link));
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
}

void delete1()
{
    int loc;
    if(n%2 == 0)
    {
        loc = n/2;
    }
    else
    {
        loc = (n/2)+1;
    }
    struct link *ptr=start;
    current = ptr->next;
    for(int i=0; i<loc-2; i++)
    {
        ptr = ptr->next;
        current = current->next;
    }
    ptr->next = current->next;
}

void display()
{
    struct link *ptr = start;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
}

int main()
{
    create();
    delete1();
    display();
    return 0;
}
 */

// WAP to except the value of m and n, and delete n nodes after m nodes...................

/*

#include<iostream>
using namespace std;

struct link
{
    int data;
    struct link *next;
};

struct link *start = NULL;
struct link *current;
struct link *node;

void create()
{
    int n;
    cout<<"How many Nodes: ";
    cin>>n;
    cout<<"Enter Elements: ";
    for(int i=0; i<n; i++)
    {
        node = (struct link *)malloc(sizeof(struct link));
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
}

void del()
{
    int n1, m1;
    cout<<"Enter Nodes to skip: "; cin>>m1;
    cout<<"Enter Nodes to delete: "; cin>>n1;
    struct link *ptr = start;
    current = ptr->next;
    if(m1 == 0)
    {
        for(int i=1; i<n1; i++)
        {start = current->next;
        current = current->next;}
    }
    else {
    for(int i =1; i<m1; i++)
    {
        ptr = ptr->next;
        current = current->next;
    }
    for(int i=1; i<n1; i++)
    {
        current = current->next;
    }
    }
    ptr->next = current->next;
}

void display()
{
    struct link *ptr = start;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
}

int main()
{
    create();
    del();
    display();
    return 0;
} */

// Given a singly linked list and a key, count the number of occurrence of the given key in the linked list.
// for example 1,2, 1, 1, 3, 1 and given key is 1 then the output should be 4.....

#include<iostream>
using namespace std;

struct link
{
    int data;
    struct link *next;
};

struct link *start = NULL;
struct link *current;
struct link *node;
int n;

void create()
{
    cout<<"How many Nodes: ";
    cin>>n;
    cout<<"Enter Elements: ";
    for(int i=0; i<n; i++)
    {
        node = (struct link *)malloc(sizeof(struct link));
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
}

void display()
{
    int cou = 0, key;
    cout<<"Key: ";
    cin>>key;
    struct link *ptr = start;
    while(ptr!=NULL){
    if(ptr->data == key)
    {
        cou++;
    }
    ptr = ptr->next;}
    if(cou == 0)
        cout<<"Key not found...";
    else
    cout<<"Freq.: "<<cou;
}

int main()
{
    create();
    display();
    return 0;
}










