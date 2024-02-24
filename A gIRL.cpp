#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
/*
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
    cin>>n;
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
    struct link *ptr = start;
    cout<<"First linked list: ";
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
}
struct link *start1 = NULL;
struct link *current1;
struct link *node1;
int m;

void create1()
{
    cin>>m;
    for(int i=0; i<m; i++)
    {
        node1 = new link;
        cin>>node1->data;
        node1->next = NULL;
        if(start1 == NULL)
        {
            start1 = node1;
            current1 = node1;
        }
        else
        {
            current1->next = node1;
            current1 = node1;
        }
    }
    struct link *ptr = start1;
    cout<<endl<<"Second linked list: ";
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
}

int result = 0;
void join()
{
    struct link *ptr = start;
    if(n == 1) {result += ptr->data;}
    else
    {
        for(int i=0; i<n-1; i++)
    {
        result += ptr->data*10;
        ptr = ptr->next;
    }
    result += ptr->data;
    }

}

int result1 = 0;
void join1()
{
    struct link *ptr1 = start1;
    if(m == 1) {result1 += ptr1->data;}
    else
    {
        for(int i=0; i<n-1; i++)
    {
        result1 += ptr1->data*10;
        ptr1 = ptr1->next;
    }
    result1 += ptr1->data;
    }

}

int main()
{
    create();
    create1();
    join();
    join1();
    int res = result + result1;
    string str = to_string(res);
    cout<<endl;
    cout<<endl<<"Total Sales: ";
    for(int i=0; i<str.length(); i++)
    {
        cout<<str[i]<<" ";
    }
}




#include <iostream>
#include <string>
using namespace std;

// A linked list node
struct Node {
    string data;
    Node* next;
};

// Given a reference (pointer to pointer) to the head of a list and a string, inserts a new node at the front of the list.
void push(Node** head_ref, string new_data)
{
    // Create a new node
    Node* new_node = new Node();
    new_node->data = new_data;

    // Make the new node point to the current head
    new_node->next = (*head_ref);

    // Update the head to point to the new node
    (*head_ref) = new_node;
}

// Given a reference (pointer to pointer) to the head of a list and a string, appends a new node at the end
void append(Node** head_ref, string new_data)
{
    // Create a new node
    Node* new_node = new Node();
    new_node->data = new_data;

    // Store the head reference in a temporary variable
    Node* last = *head_ref;

    // Set the next pointer of the new node as NULL since it will be the last node
    new_node->next = NULL;

    // If the Linked List is empty, make the new node as the head and return
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    // Else traverse till the last node
    while (last->next != NULL) {
        last = last->next;
    }

    // Change the next pointer of the last node to point to the new node
    last->next = new_node;
}

// This function prints the contents of the linked list starting from the head
void printList(Node* node)
{
    while (node != NULL) {
        cout << " " << node->data;
        node = node->next;
    }
}

int main()
{
    // Start with an empty list
    Node* head = NULL;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        push(&head, str);
    }

    cout << "Document:";
    printList(head);

    string new_string;
    cin >> new_string;

    // Insert the new string at the end
    append(&head, new_string);

    cout << "\nUpdated Document:";
    printList(head);

    return 0;
} */

int main()
{
    string name = "Ashmin";
    cout << name[0] << endl;
}
