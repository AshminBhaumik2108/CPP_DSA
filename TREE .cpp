// WAP TO CREATE A FOLLOWING BINARY TREE:-
/*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    Node *left;
    Node *right;
};

Node* create(char val)
{
    Node* newnode = new Node;
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void display(Node* root)
{
    if(root == NULL)
       return;

    cout<<root->data;
    display(root->left);
    display(root->right);
}

int main()
{
    Node* root = create('A');
    root->left = create('B');
    root->left->left = create('D');
    root->right = create('C');
    root->right->left = create('E');
    root->right->left->left = create('G');
    root->right->right = create('F');
    cout<<endl<<"Binary Tree created Successfully....."<<endl;
    cout<<"Pre-Order traversal is: "<<endl;
    display(root);
}*/

// WAP to create a Binary Tree using recursion and display the In-order traversing:-

#include<iostream>
using namespace std;

struct Node
{
    char data;
    Node* left;
    Node* right;
};

Node* create()
{
    char val;
    cout<<"Enter the Element(or 'X' for no element): ";
    cin>>val;
    if(val == 'X') return NULL;

    Node* newnode = new Node;
    newnode->data = val;

    cout<<"Enter the left Child of "<<val<<": ";
    newnode->left = create();
    cout<<"Enter the Right child of "<<val<<": ";
    newnode->right = create();

    return newnode;

}

void display(Node* root)
{
    if(root == NULL)
    {
        return;
    }

    display(root->left);
    cout<<root->data<<" ";
    display(root->right);
}

int main()
{
    Node* root = NULL;
    root = create();
    cout<<"Binary Tree created....."<<endl;
    cout<<"In-Order Traversal is: ";
    display(root);

}

//WAP to create a Binary Search Tree:-
/*
#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* create(int item)
{
    Node* node = new Node;
    node->data = item;
    node->left = NULL;
    node->right = NULL;

    return node;
}

Node* insert(Node* root, int item)
{
    if(root == NULL)
    {
        return create(item);
    }
    if(item < root->data)
    {
        root->left = insert(root->left, item);
    }
    else if(item > root->data)
    {
        root->right = insert(root->right, item);
    }
    return root;
}

void display(Node* root)
{
    if(root == NULL)
    {
        return;
    }

    display(root->left);
    cout<<root->data<<" ";
    display(root->right);
}

int main()
{
    Node* root = NULL;
    root = insert(root, 9);
    insert(root, 6);
    insert(root, 4);
    insert(root, 14);
    insert(root, 12);
    insert(root, 5);
    insert(root, 10);
    cout<<"Binary Search Tree Created....."<<endl;
    cout<<"In-Order Traversal is: ";
    display(root);
} */

//WAP to Binary Search an element:-
/*
#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* create(int item)
{
    Node* node = new Node;
    node->data = item;
    node->left = NULL;
    node->right = NULL;

    return node;
}

Node* insert(Node* root, int item)
{
    if(root == NULL)
    {
        return create(item);
    }
    if(item < root->data)
    {
        root->left = insert(root->left, item);
    }
    else if(item > root->data)
    {
        root->right = insert(root->right, item);
    }
    return root;
}

void display(Node* root)
{
    if(root == NULL)
    {
        return;
    }

    display(root->left);
    cout<<root->data<<" ";
    display(root->right);
}

Node* search(Node* root, int item)
{
    if(root == NULL || root->data == item)
        return root;
    if(item < root->data)
    {
        return search(root->left, item);
    }
    else if(item > root->data)
    {
        return search(root->right, item);
    }
    else
        return root;

}

int main()
{
    Node* root = NULL;
    root = insert(root, 9);
    insert(root, 6);
    insert(root, 4);
    insert(root, 14);
    insert(root, 12);
    insert(root, 5);
    insert(root, 10);
    cout<<"Binary Search Tree Created....."<<endl;
    cout<<"In-Order Traversal is: ";
    display(root);

    int n;
    cout<<endl<<"Enter the element to search: ";
    cin>>n;
    if(search(root, n) == NULL)
    {
        cout<<"Number not Present...."<<endl;
    }
    else
    {
        cout<<"Number Found......"<<endl;
    }
} */

// DELETE A NODE FROM A BINARY SEARCH TREE :-
/*
#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* create(int item)
{
    Node* node = new Node;
    node->data = item;
    node->left = NULL;
    node->right = NULL;

    return node;
}

Node* insert(Node* root, int item)
{
    if(root == NULL)
    {
        return create(item);
    }
    if(item < root->data)
    {
        root->left = insert(root->left, item);
    }
    else if(item > root->data)
    {
        root->right = insert(root->right, item);
    }
    return root;
}

void display(Node* root)
{
    if(root == NULL)
    {
        return;
    }

    display(root->left);
    cout<<root->data<<" ";
    display(root->right);
}

Node* deletenode(Node* root, int item)
{
    if(root == NULL)
        return root;
    if(item < root->data)
    {
        root->left = deletenode(root->left, item);
        return root;
    }
    else if(item > root->data)
    {
        root->right = deletenode(root->right, item);
        return root;
    }
    // if one child:-
    if(root->left == NULL)
    {
        Node* temp = root->right;
        delete root;
        return temp;
    }
    else if(root->right == NULL)
    {
        Node* temp = root->left;
        delete root;
        return temp;
    }
    else
    {
        // root having 2 child
        Node* succParent = root;
        Node* succ = root->right;
        while(succ->left != NULL)
        {
            succParent = succ;
            succ = succ->left;
        }
        if(succParent == root)
        {
            succParent->right = succ->right;
        }
        else
        {
            succParent->left = succ->right;
        }
        root->data = succ->data;
        delete succ;
        return root;
    }
}

int main()
{
    Node* root = NULL;
    root = insert(root, 14);
    insert(root, 7);
    insert(root, 28);
    insert(root, 21);
    insert(root, 10);
    insert(root, 29);
    insert(root, 5);
    insert(root, 15);
    insert(root, 72);
    insert(root, 13);
    cout<<"Binary Search Tree Created....."<<endl;
    cout<<"In-Order Traversal is: ";
    display(root);

    int n; // to delete
    cout<<"\nEnter the number to delete: ";
    cin>>n;
    root = deletenode(root, n);
    cout<<"In-Order Traversal after deleteing: ";
    display(root);
} */

// For binary tree not binary search tree:-
/*
#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* create(int item)
{
    Node* node = new Node;
    node->data = item;
    node->left = NULL;
    node->right = NULL;

    return node;
}

Node* insert(Node* root, int item)
{
    if(root == NULL)
    {
        return create(item);
    }
    if(item < root->data)
    {
        root->left = insert(root->left, item);
    }
    else if(item > root->data)
    {
        root->right = insert(root->right, item);
    }
    return root;
}

void display(Node* root)
{
    if(root == NULL)
    {
        return;
    }

    display(root->left);
    cout<<root->data<<" ";
    display(root->right);
}

Node* deletenode(Node* root, int item)
{
    if(root == NULL)
        return root;
    if(item < root->data)
    {
        root->left = deletenode(root->left, item);
        return root;
    }
    else if(item > root->data)
    {
        root->right = deletenode(root->right, item);
        return root;
    }
    // if one child:-
    if(root->left == NULL)
    {
        Node* temp = root->right;
        delete root;
        return temp;
    }
    else if(root->right == NULL)
    {
        Node* temp = root->left;
        delete root;
        return temp;
    }
    else
    {
        // root having 2 child
        Node* succParent = root;
        Node* succ = root->right;
        while(succ->left != NULL)
        {
            succParent = succ;
            succ = succ->left;
        }
        if(succParent == root)
        {
            succParent->right = succ->right;
        }
        else
        {
            succParent->left = succ->right;
        }
        root->data = succ->data;
        delete succ;
        return root;
    }
}

int main()
{
    Node* root = NULL;
    int n1; int m;
    cin>>n1;
    cout<<"Enter Range: "; cin>>n1;
    for(int i=0; i<n1; i++)
    {
        cout<<"*: "; cin>>m;
        root = insert(root, m);
    }

    cout<<"Binary Search Tree Created....."<<endl;
    cout<<"In-Order Traversal is: ";
    display(root);

    int n; // to delete
    cout<<"\nEnter the number to delete: ";
    cin>>n;
    root = deletenode(root, n);
    cout<<"In-Order Traversal after deleteing: ";
    display(root);
} */























