// DELETE AN ELEMENT FROM AN BST:-

/*
Input 1 :
5
Z E W T Y
Y
Output 1 :
E T W Z
*/

/*
#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
};

Node* insert(Node* root, char data) {
    if (root == nullptr) {
        root = new Node();
        root->data = data;
        root->left = root->right = nullptr;
    } else if (data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

Node* findMin(Node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, char data) {
    if (root == nullptr) {
        return root;
    }
    // for finding the data.......
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    }
    // When the data has been matched......
    else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
    //Both the children are present....
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int pre = 0;

void check_pre(Node* root) {
    if (root == nullptr) {
        return;
    }
    check_pre(root->left);
    pre++;
    check_pre(root->right);
}

void inorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    int size;
    cout << "No. of Elements: ";
    cin >> size;
    int s = size;
    Node* root = nullptr;
    char input, char_to_delete;

    while (size > 0) {
        cout << "*: ";
        cin >> input;
        root = insert(root, input);
        size--;
    }

    cout <<  "Del. element: ";
    cin >> char_to_delete;

    root = deleteNode(root, char_to_delete);

    //To check element present....
    check_pre(root);
    //cout<<pre<<size;
    if(pre == s){
        cout<<"Element not Present......"<<endl;
        exit(0);
    }else{
        cout<<"Element Present."<<endl;
    }

    //For Printing in Sorted Order.......
    cout<<"In-order Series: ";
    inorder(root);
    cout << endl;

    return 0;
} */

// BST to Pre-order tranversal:-

/*
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

};

Node* create_node(int data)
{
    Node* newnode = new Node;
    newnode->data = data;
    newnode->left = nullptr;
    newnode->right = nullptr;
    return newnode;
}

void preOrder(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return create_node(data);
    } else if (data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

int main() {
    Node* root = nullptr;
    int t;
    int data;

    cin >> t;

    while (t > 0) {
        cin >> data;
        root = insert(root, data);
        t--;
    }

    preOrder(root);
    return 0;
} */

// For Binary Tree not Binary search tree:-

/
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* create(int data)
{
    Node* newnode = new Node;
    newnode->data = data;
    newnode->left = nullptr;
    newnode->right = nullptr;
    return newnode;
}

Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return create(data);
    } else {

        if (root->left == nullptr) {
            root->left = create(data);
        } else if (root->right == nullptr) {
            root->right = create(data);
        } else {
            // If both left and right children are already present,
            // you can choose one side to insert the new node, e.g., left.
            root->left = insert(root->left, data);
        }

        return root;
    }
}

void postOrder(Node* root) {
    if (root == nullptr) {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = nullptr;
    int n;
    int data;

    cin >> n;

    while (n > 0) {
        cin >> data;
        root = insert(root, data);
        n--;
    }

    postOrder(root);
    return 0;
} */

// For Binary Search Tree not Binary Tree:- // ONLY CHANGE IN INSERT FUNCTION AND REST ALL ARE SAME:-
/*
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* create(int data)
{
    Node* newnode = new Node;
    newnode->data = data;
    newnode->left = nullptr;
    newnode->right = nullptr;
    return newnode;
}

Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return create(data);
    }
    else if(data <= root->data)
    {
        root->left = insert(root->left, data);
    }
    else if(data > root->data)
    {
        root->right = insert(root->right, data);
    }

    return root;
}

void postOrder(Node* root) {
    if (root == nullptr) {
        return;
    }

    postOrder(root->left);
    cout << root->data << " ";
    postOrder(root->right);

}

int main() {
    Node* root = nullptr;
    int n;
    int data;

    cin >> n;

    while (n-- > 0) {
        cin >> data;
        root = insert(root, data);
    }

    postOrder(root);
    return 0;
} */

// For Binary Tree when val != -1.....

/*
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* create(int data)
{
    Node* newnode = new Node;
    newnode->data = data;
    newnode->left = nullptr;
    newnode->right = nullptr;
    return newnode;
}

Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return create(data);
    } else {

        if (root->left == nullptr) {
            root->left = create(data);
        } else if (root->right == nullptr) {
            root->right = create(data);
        } else {
            // If both left and right children are already present,
            // you can choose one side to insert the new node, e.g., left.
            root->left = insert(root->left, data);
        }

        return root;
    }
}

void postOrder(Node* root) {
    if (root == nullptr) {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = nullptr;
    int n;
    int data;

    while (1) {
        cin >> data;
        if(data == -1) break;
        root = insert(root, data);
    }

    postOrder(root);
    return 0;
}*/

// For Binary Search Tree when val != -1.....

/*
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* create(int data)
{
    Node* newnode = new Node;
    newnode->data = data;
    newnode->left = nullptr;
    newnode->right = nullptr;
    return newnode;
}

Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return create(data);
    }
    else if(data <= root->data)
    {
        root->left = insert(root->left, data);
    }
    else if(data > root->data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}

void postOrder(Node* root) {
    if (root == nullptr) {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = nullptr;
    int n;
    int data;

    while (1) {
        cin >> data;
        if(data == -1) break;
        root = insert(root, data);
    }

    postOrder(root);
    return 0;
} */

// POST ORDER BST & SUM OF ALL THE NODES

/*
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* create(int data)
{
    Node* newnode = new Node;
    newnode->data = data;
    newnode->left = nullptr;
    newnode->right = nullptr;
    return newnode;
}

Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return create(data);
    }
    else if(data <= root->data)
    {
        root->left = insert(root->left, data);
    }
    else if(data > root->data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}

void postOrder(Node* root) {
    if (root == nullptr) {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int sumNodes(Node* root)
{
    if(root == nullptr)
    {
        return 0;
    }

    int leftSum = sumNodes(root->left);
    int rightSum = sumNodes(root->right);

    return root->data + leftSum + rightSum;
}

int main() {
    Node* root = nullptr;
    int n;
    int data;

    while (1) {
        cin >> data;
        if(data == -1) break;
        root = insert(root, data);
    }

    postOrder(root);

    int r = sumNodes(root);

    cout<<endl<<"Sum: "<<r;
    return 0;
}*/

// SEARCHING AN ELEMENT :-

/*
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* create(int data)
{
    Node* newnode = new Node;
    newnode->data = data;
    newnode->left = nullptr;
    newnode->right = nullptr;
    return newnode;
}

Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return create(data);
    }
    else if(data <= root->data)
    {
        root->left = insert(root->left, data);
    }
    else if(data > root->data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}
// flag...............
int flag = 0;

Node* search(Node* root, int data)
{
    if(root == nullptr)
        return root;
    if(root->data == data)
    {
        flag = 1;
    }
    else if(data < root->data)
    {
        root->left = search(root->left, data);
    }
    else if(data > root->data)
    {
        root->right = search(root->right, data);
    }
    return root;
}

void postOrder(Node* root) {
    if (root == nullptr) {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int sumNodes(Node* root)
{
    if(root == nullptr)
    {
        return 0;
    }

    int leftSum = sumNodes(root->left);
    int rightSum = sumNodes(root->right);

    return root->data + leftSum + rightSum;
}

int main() {
    Node* root = nullptr;
    int n;
    int data;

    while (1) {
        cin >> data;
        if(data == -1) break;
        root = insert(root, data);
    }

    postOrder(root);

    int r = sumNodes(root);

    cout<<endl<<"Sum: "<<r;

    int p;
    cout<<endl<<"Search: "; cin>>p;
    search(root, p);

    if(flag == 1)
    {
        cout<<"Present..";
    }
    else
    {
        cout<<"Not present.....";
    }
    return 0;
} */

// SORTED ELEMENT USING QUICK-SORT:-
/*
#include <iostream>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void recursiveQuickSort(int arr[], int n) {
    quickSort(arr, 0, n - 1);
}

int main() {
    int n;
    cin >> n;

    int years[n];

    for (int i = 0; i < n; i++) {
        cin >> years[i];
    }

    recursiveQuickSort(years, n);

    for (int i = 0; i < n; i++) {
        cout << years[i] << " ";
    }

    return 0;
}*/

// FOR POINT ELEMENTS in Descending order using quick sort:-
/*
#include <iostream>
#include<iomanip>
using namespace std;

double swap(double &p, double &q)
{
    double temp = p;
    p = q;
    q = temp;
}

int partition(double arr[], int low, int high) {
    double pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] > pivot)
        {
            i++;
            // to swap..........
            swap(arr[i], arr[j]);
        }
    }
    // to swap..........
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(double arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void recursiveQuickSort(double arr[], int n) {
    quickSort(arr, 0, n - 1);
}

int main() {
    int n;
    cin >> n;

    double years[n];

    for (int i = 0; i < n; i++) {
        cin >> years[i];
    }

    recursiveQuickSort(years, n);

    for (int i = 0; i < n; i++) {
        cout << fixed << setprecision(1) <<years[i] << " ";
    }

    return 0;
} */

// QUICK SORT FOR STRING :-
/*
#include <iostream>
#include <string>
using namespace std;

void swap(string &p, string &q)
{
    string temp = p;
    p = q;
    q = temp;
}

int partition(string arr[], int low, int high) {
    string pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] > pivot)
        {
            i++;
            // to swap..........
            swap(arr[i], arr[j]);
        }
    }
    // to swap..........
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(string arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void recursiveQuickSort(string arr[], int n) {
    quickSort(arr, 0, n - 1);
}

int main() {
    int n;
    cin >> n;

    string years[n];

    for (int i = 0; i < n; i++) {
        cin >> years[i];
    }

    recursiveQuickSort(years, n);

    for (int i = 0; i < n; i++) {
        cout <<years[i] << " ";
    }

    return 0;
} */

// SORTING USING MERGE SORT:-
/*
#include <iostream>
using namespace std;

void merge(char arr[], int left, int mid, int right)
{
    int n1 = mid-left+1; //
    int n2 = right-mid;
    int i, j, k=0;

    char L1[n1], L2[n2];

    for(i=left; i<=mid; i++)
    {
        L1[k++] = arr[i];
    }
    k=0;
    for(i=mid+1; i<=right; i++)
    {
        L2[k++] = arr[i];
    }

    i=0; j=0; k=left;

    while(i < n1 && j < n2)
    {
        if(L1[i] < L2[j])
        {
            arr[k++] = L1[i++];
        }
        else
        {
            arr[k++] = L2[j++];
        }
    }

    while(i < n1)
    {
        arr[k++] = L1[i++];
    }
    while(j < n2)
    {
        arr[k++] = L2[j++];
    }
}

void mergeSort(char arr[], int left, int right)
{
   if(left < right)
   {
       int mid = (left + right)/2;
       mergeSort(arr, left, mid);
       mergeSort(arr, mid+1, right);

       // merging:-
       merge(arr, left, mid, right);
   }
}

int main() {
    int size;
    cin >> size;

    char arr[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    mergeSort(arr, 0, size - 1);

    cout << "Sorted Characters: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
} */

#include<iostream>
using namespace std;

// Definition of a node in the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Function to insert a new node into the binary tree
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to perform an inorder traversal of the binary tree
void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    // Example usage of the binary tree
    Node* root = nullptr;

    // Inserting elements into the binary tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Perform an inorder traversal to display the elements
    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}







