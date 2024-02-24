/*
#include<iostream>
#include<cstdlib>
using namespace std;

struct link
{
    int roll;
    int mark;
    struct link *next;
};

struct link *start = NULL;
struct link *node;
struct link *current;

void create()
{
    cout<<"Student roll and mark: ";
    for(int i=0; i<5; i++)
    {
        node = (struct link *)malloc(sizeof(struct link));
        cin>>node->roll; cin>>node->mark;
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
    struct link *ptr = start;
    while(ptr != NULL)
    {
        if(ptr->mark >= 60)
        {
            cout<<ptr->roll<<" ";
        }
        ptr = ptr->next;
    }
}

int main()
{
    create();
    display();
    return 0;
}
*/

#include<iostream>
#include<cstdlib>
using namespace std;

struct link
{
    int data;
    struct link *next;
};

struct link *start = NULL;
struct link *node;
struct link *current;

void create()
{
    int n;
    cout<<"How many Nodes: ";
    cin>>n;
    cout<<"Elements are: ";
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
}

void display()
{
    struct link *ptr = start;
    current = ptr->next;
    int large = ptr->data;
    while(current != NULL)
    {
        if(current->data > large)
        {
            large = current->data;
        }
        current = current->next;
    }
    cout<<"Largest Element is: "<<large;
}

int main()
{
    create();
    display();
    return 0;
}















