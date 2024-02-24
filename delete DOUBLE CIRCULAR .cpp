// WAP to delete a number from a double circular linked list by asking the position from the user........

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
int n;

void create()
{

    cout<<"Enter number of nodes: ";
    cin>>n;
    cout<<"Enter all values: ";
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

void delete1()
{
    int loc;
    struct link *ptr = start;
    current = ptr->next;
    cout<<"Enter location: ";
    cin>>loc;
    if(loc == 1)
    {
        start = current;
        start->prev = node;
        node->next = start;
    }
    else if(loc<1 || loc>n)
    {
        cout<<"Invalid location !!!!!!!!";
        exit(0);
    }
    else
    {
        for(int i=0; i<loc-2; i++)
        {
            ptr = ptr->next;
            current = current->next;
        }
        ptr->next = current->next;
        current->next->prev = ptr;
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
    delete1();
    display();
    return 0;
}





