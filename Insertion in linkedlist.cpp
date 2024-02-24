/
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

void Insert1()
{
    node = (struct link *)malloc(sizeof(struct link));
    int loc;
    cout<<"Enter location: ";
    cin>>loc;
    cout<<"Enter element: ";
    cin>>node->data;
    struct link *ptr = start;
    current = ptr->next;
    for(int i=1; i<=loc-2; i++)
    {
        ptr = ptr->next;
        current = current->next;
    }
    ptr->next = node;
    node->next = current;
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
    Insert1();
    display();
    return 0;
}

*/
// WAP to delete a number from a single linked list

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
int cou = 1;

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
    int n; cout<<"*: "; cin>>n;
    struct link *ptr=start;
    current = ptr->next;

    if(ptr->data == n)
    {
        start = ptr->next;
    }
    else
        {
        while(current->next != NULL)
        {
        while(current->data != n)
        {
            ptr = ptr->next;
            current = current->next;
            break;
        }
            break;
        }
        cout<<cou;
        if(cou == n)
        {
            cout<<"Element not found."<<endl;
            exit(0);
        }
        else{
            ptr->next = current->next;
        }

        }

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

// WAP to except the value of m and n, and delete n nodes after m nodes...................



























