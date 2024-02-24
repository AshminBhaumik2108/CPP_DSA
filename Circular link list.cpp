// WAP to create a circular link list and display the program.....

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

void create()
{
    int n;
    cout<<"No. of Nodes: ";
    cin>>n;
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
        }
        else
        {
            current->next = node;
            node->next = start;
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
    } while(ptr!=start);
}

int main()
{
    create();
    display();
}
