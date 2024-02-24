//MAX HEAP ELEMENTS :-
/*
#include<iostream>
using namespace std;

void maxheap(int a[], int k, int n)
{
    int val = a[k];
    int j = 2*k;
    while(j <= n)
    {
        if(a[j+1] > a[j])
           j=j+1;
        if(val > a[j])
           break;
        else if(val < a[j])
        {
            a[j/2] = a[j];
            j = 2*j;
        }
     }
     a[j/2] = val;
     return;

}


void build_heap(int *a, int n)
{
    int k;
    for(k = n/2; k>=1; k--)
    {
        maxheap(a, k, n);
    }
}

int main()
{
    int n, a[30];
    cout<<"Enter Range: ";
    cin>>n;
    cout<<"Enter all the elements: ";
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    //build a heap......
    build_heap(a, n);
    //display........
    cout<<endl<<"Max Heap is: ";
    for(int i=1; i<=n; i++)
    {
        cout<<a[i]<<" ";
    }
} */

//MIN HEAP ELEMENTS :-
/*
#include<iostream>
using namespace std;

void minheap(int a[], int k, int n)
{
    int val = a[k];
    int j = 2*k;
    while(j <= n)
    {
        if(a[j+1] < a[j])
           j=j+1;
        if(val < a[j])
           break;
        else if(val > a[j])
        {
            a[j/2] = a[j];
            j = 2*j;
        }
     }
     a[j/2] = val;
     return;

}


void build_heap(int *a, int n)
{
    int k;
    for(k = n/2; k>=1; k--)
    {
        minheap(a, k, n);
    }
}

int main()
{
    int n, a[30];
    cout<<"Enter Range: ";
    cin>>n;
    cout<<"Enter all the elements: ";
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    //build a heap......
    build_heap(a, n);
    //display........
    cout<<endl<<"Max Heap is: ";
    for(int i=1; i<=n; i++)
    {
        cout<<a[i]<<" ";
    }
} */

// MAX HEAP ELEMENT BY USING STARTING FORM 0th INDEX:......
/*
void maxheap(int a[], int k, int n)
{
    int val = a[k];
    int j = 2*k+1;
    while(j<n)
    {
        if(a[j+1]>a[j])
            j = j+1;
        if(val > a[j])
            break;
        else
        {
            if(j%2 == 0)
                a[(j/2)-1] = a[j];
            else
                a[j/2] = a[j];
                a[j] = val;

            break;
        }

    }


    return;
}

#include<iostream>
using namespace std;

void build_heap(int a[], int n)
{
    int k;
    for(k = (n/2)-1; k>=0; k--)
    {
        maxheap(a, k, n);
    }
}

int main()
{
    int a[30], n;
    cout<<"Enter the range: "; cin>>n;
    cout<<"Enter the Elements: ";
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    build_heap(a, n);
    cout<<"Max Heap is: ";
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }

    return 0;
} */

// DELETE AN ELEMENT FROM THE MAX HEAP:-
// CREATE AN MIN HEAP......
/*
#include<iostream>
using namespace std;

void minheap(int a[], int k, int n)
{
    int val = a[k];
    int j = 2*k;
    while(j <= n)
    {
        if(a[j+1] < a[j])
           j=j+1;
        if(val < a[j])
           break;
        else if(val > a[j])
        {
            a[j/2] = a[j];
            j = 2*j;
        }
     }
     a[j/2] = val;
     return;

}


void build_heap(int *a, int n)
{
    int k;
    for(k = (n/2)-1; k>=0; k--)
    {
        minheap(a, k, n);
    }
}

int main()
{
    int n, a[30];
    cout<<"Enter Range: ";
    cin>>n;
    cout<<"Enter all the elements: ";
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    //build a heap......
    build_heap(a, n);
    //display........
    cout<<endl<<"MIN Heap is: ";
    for(int i=1; i<=n; i++)
    {
        cout<<a[i]<<" ";
    }
} */

// MAX HEAP BUT IN VERY CORRECT WAY:-
/*
#include<iostream>
using namespace std;

void maxheap(int a[], int k, int n)
{
    int val = a[k];
    int j = 2*k;
    while(j <= n)
    {
        if( j<n && a[j+1] > a[j])
           j=j+1;
        if(val > a[j])
           break;
        else
            a[j/2] = a[j];
            j = 2*j;

     }
     a[j/2] = val;
     return;

}


void build_heap(int a[], int n)
{
    int k;
    for(k = n/2; k>=1; k--)
    {
        maxheap(a, k, n);
    }
}

int main()
{
    int n, a[30];
    cout<<"Enter Range: ";
    cin>>n;
    cout<<"Enter all the elements: ";
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    //build a heap......
    build_heap(a, n);
    //display........
    cout<<endl<<"Max Heap is: ";
    for(int i=1; i<=n; i++)
    {
        cout<<a[i]<<" ";
    }
} */


// DELETE AN ELEMENT FROM THE HEAP......
/*
#include <iostream>
using namespace std;
void maxheap(int a[],int k,int n)
{
int val=a[k];
int j=2*k+1; //modified
while(j<n) //modified
{
if(j<n && a[j+1]>a[j])
j=j+1;
if(val>a[j])
break;
else
a[(j-1)/2]=a[j]; //modified
j=2*j+1; //modified
}
a[(j-1)/2]=val; //modified
return;
}
void build_heap(int a[],int n)
{
int k;
for(k=(n/2)-1;k>=0;k--) //modified
{
maxheap(a,k,n);
}
}
void hipify(int a[],int n,int index)
{
int largeindex=index;
int L=2*index+1;
int R=2*index+2;
if(L<n && a[L]>a[largeindex])
{
largeindex=L;
}
if(R<n && a[R]>a[largeindex])
{
largeindex=R;
}
if(index!=largeindex)
{
swap(a[index],a[largeindex]);
hipify(a,n,largeindex);
}
}
void deleteheap(int a[],int n,int no)
{
int index;
for(int i=0;i<n;i++)
{
if(a[i]==no)
{
index=i;
break;
}
}
a[index]=a[n-1];
hipify(a,n,index);
}

int main()
{
int n;
int a[30];
cout<<"how many nodes u want to create: ";
cin>>n;
cout<<"Enter the elements: ";
for(int i=0;i<n;i++) //modified
{
cin>>a[i];
}
build_heap(a,n);
cout<<"MAX heap is: ";
for(int i=0;i<n;i++) //modified
{
cout<<a[i]<<" ";
}
int no;
cout<<"Enter the number you want to delete: ";
cin>>no;
deleteheap(a,n,no);
cout<<"\nThe MAX heap after deletion :";
for(int i=0;i<n-1;i++)
{
cout<<a[i]<<" ";
}

return 0;
}
 */

// WAP to sort the delete the root of the max heap of .......

#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node* create(int data)
{
    Node *newnode = new Node;
    newnode->data = data;
    newnode->left = nullptr;
    newnode->right = nullptr;
    return newnode;
}

Node* insert(Node* root, int data)
{
    if(root == nullptr)
    {
        return create(data);
    }
    else
    {
        if(root->data > data)
        {
            root->left = insert(root->left, data);
        }
        else if(root->data < data)
        {
            root->right = insert(root->right, data);
        }
    return root;
    }
}

void postOrder(Node* root)
{
    if(root == nullptr)
        return;

    postOrder(root->left);
    cout << root->data << " ";
    postOrder(root->right);
}

int main() {
    Node* root = nullptr;
    int n;
    int data;

    while (1)
    {
        cin >> data;
        if(data == -1) break;
        root = insert(root, data);
    }

    postOrder(root);

    return 0;
}










