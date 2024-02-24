#include <iostream>
using namespace std;

int n = 1;

struct node
{
    int data;
    node* left;
    node* right;
};

struct node* getNode(int data)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* Insert(struct node* root, int data)
{
    if (root == NULL)
        return getNode(data);

    if (data < root->data)
        root->left = Insert(root->left, data);
    else if (data > root->data)
        root->right = Insert(root->right, data);

    return root;
}

int CountNodes(node* root)
{
    if (root == NULL)
        return 0;

    if (root->left != NULL)
    {
        n = n + 1;
        n = CountNodes(root->left);
    }
    if (root->right != NULL)
    {
        n = n + 1;
        n = CountNodes(root->right);
    }
    return n;
}

int main()
{
    node* root = NULL;
    int numNodes;

    cin >> numNodes;

    for (int i = 0; i < numNodes; i++) {
        int data;
        cin >> data;
        root = Insert(root, data);
    }

    cout << CountNodes(root) << endl;

    return 0;
}


#include <iostream>
using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* createNode(int value) {
    TreeNode* newNode = new TreeNode;
    newNode->value = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

void inOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inOrderTraversal(root->left);
    cout << root->value << " ";
    inOrderTraversal(root->right);
}

int main() {
    int n;
    cin >> n;

    int val;
    TreeNode* root = nullptr;

    for (int i = 0; i < n; i++) {
        cin >> val;
        if (i == 0) {
            root = createNode(val);
        } else {
            TreeNode* current = root;
            while (true) {
                if (val < current->value) {
                    if (current->left == nullptr) {
                        current->left = createNode(val);
                        break;
                    }
                    current = current->left;
                } else {
                    if (current->right == nullptr) {
                        current->right = createNode(val);
                        break;
                    }
                    current = current->right;
                }
            }
        }
    }

    cout << "In-order traversal: ";
    inOrderTraversal(root);
    cout << endl;

    return 0;
}

#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* createNode(int key) {
    TreeNode* newNode = new TreeNode;
    newNode->data = key;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

TreeNode* insert(TreeNode* root, int key) {
    if (root == nullptr) return createNode(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    return root;
}

TreeNode* deleteLeafNodes(TreeNode* root) {
    if (root == nullptr) return nullptr;
    if (root->left == nullptr && root->right == nullptr) {
        delete root;
        return nullptr;
    }
    root->left = deleteLeafNodes(root->left);
    root->right = deleteLeafNodes(root->right);
    return root;
}

void printInOrder(TreeNode* root) {
    if (root == nullptr) return;
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

int main() {
    int N;
    cin >> N;

    TreeNode* root = nullptr;

    for (int i = 0; i < N; i++) {
        int key;
        cin >> key;
        root = insert(root, key);
    }

    root = deleteLeafNodes(root);

    if (root == nullptr) {
        cout << "Empty tree" << endl;
    } else {
        printInOrder(root);
        cout << endl;
    }

    return 0;
}

#include <iostream>

// Define a structure for a binary tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

// Function to insert a new key into a BST
TreeNode* insert(TreeNode* root, int key) {
    if (root == NULL) return new TreeNode(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    return root;
}

// Function to delete the node with the minimum value in the BST
TreeNode* deleteMinNode(TreeNode* root) {
    if (root == NULL) return root;
    if (root->left == NULL) {
        TreeNode* temp = root->right;
        delete root;
        return temp;
    }
    root->left = deleteMinNode(root->left);
    return root;
}

// Function to print the values of the BST nodes
void printValues(TreeNode* root) {
    if (root != NULL) {
        printValues(root->left);
        std::cout << root->data << " ";
        printValues(root->right);
    }
}

int main() {
    int N;
    std::cin >> N;

    TreeNode* root = NULL;

    for (int i = 0; i < N; i++) {
        int key;
        std::cin >> key;
        root = insert(root, key);
    }

    root = deleteMinNode(root);

    if (root == NULL) {
        std::cout << "(Empty tree)" << std::endl;
    } else {
        printValues(root);
        std::cout << std::endl;
    }

    return 0;
}


#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

void findKthLargest(Node* root, int K, int& count, int& result) {
    if (root == nullptr || count >= K) {
        return;
    }

    // Traverse the tree in reverse order (right, root, left)
    findKthLargest(root->right, K, count, result);

    // If Kth largest element is found, set the result and return
    if (count == K - 1) {
        result = root->data;
        count++;
        return;
    }

    count++;

    // Continue searching on the left subtree
    findKthLargest(root->left, K, count, result);
}

int main() {
    Node* root = nullptr;
    int n, K, count = 0, result;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        if (root == nullptr) {
            root = createNode(data);
        } else {
            Node* current = root;
            while (true) {
                if (data <= current->data) {
                    if (current->left == nullptr) {
                        current->left = createNode(data);
                        break;
                    }
                    current = current->left;
                } else {
                    if (current->right == nullptr) {
                        current->right = createNode(data);
                        break;
                    }
                    current = current->right;
                }
            }
        }
    }

    cin >> K;

    findKthLargest(root, K, count, result);

    if (count < K) {
        cout << "Doesn't exist.";
    } else {
        cout << result;
    }

    return 0;
}

#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode* next;
};

TreeNode* createNode(int key) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode)); // Use malloc for memory allocation
    newNode->data = key;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->next = nullptr;
    return newNode;
}

TreeNode* insert(TreeNode* root, int key) {
    if (root == nullptr) return createNode(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    else {
        TreeNode* currentNode = root;
        while (currentNode->next != nullptr) {
            currentNode = currentNode->next;
        }
        currentNode->next = createNode(key);
    }
    return root;
}

int countNodesWithValue(TreeNode* root, int value) {
    if (root == nullptr) return 0;
    int count = countNodesWithValue(root->left, value) + countNodesWithValue(root->right, value);

    TreeNode* currentNode = root;
    while (currentNode != nullptr) {
        if (currentNode->data == value) {
            count++;
        }
        currentNode = currentNode->next;
    }

    return count;
}

void printInOrder(TreeNode* root) {
    if (root != nullptr) {
        printInOrder(root->left);

        cout << root->data << " ";

        TreeNode* currentNode = root->next;
        while (currentNode != nullptr) {
            cout << currentNode->data << " ";
            currentNode = currentNode->next;
        }

        printInOrder(root->right);
    }
}

int main() {
    int N, K, X;
    cin >> N;

    TreeNode* root = nullptr;

    for (int i = 0; i < N; i++) {
        int key;
        cin >> key;
        root = insert(root, key);
    }

    cin >> K >> X;
    root = insert(root, K);

    printInOrder(root);
    cout << endl;
    int count = countNodesWithValue(root, X);
    cout << count << endl;

    return 0;
}


2nd


#include <iostream>
#include <string>
using namespace std;

void heapify(string arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildMaxHeap(string arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

void heapSort(string arr[], int n) {
    buildMaxHeap(arr, n);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int n;
    cin >> n;
    string arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    heapSort(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}


#include <iostream>
using namespace std;

#define MAX_STR_LEN 100
#define MAX_NUM_STR 100

int compareStrings(char* str1, char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] < str2[i])
            return -1;
        else if (str1[i] > str2[i])
            return 1;
        i++;
    }
    if (str1[i] == '\0' && str2[i] == '\0')
        return 0;
    else if (str1[i] == '\0')
        return -1;
    else
        return 1;
}

void copyString(char* dest, char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void MinHeapify(char arr[][MAX_STR_LEN], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && compareStrings(arr[left], arr[smallest]) == -1)
        smallest = left;

    if (right < n && compareStrings(arr[right], arr[smallest]) == -1)
        smallest = right;

    if (smallest != i) {
        char temp[MAX_STR_LEN];
        copyString(temp, arr[i]);
        copyString(arr[i], arr[smallest]);
        copyString(arr[smallest], temp);

        MinHeapify(arr, n, smallest);
    }
}

void MinHeapSort(char arr[][MAX_STR_LEN], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        MinHeapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        char temp[MAX_STR_LEN];
        copyString(temp, arr[0]);
        copyString(arr[0], arr[i]);
        copyString(arr[i], temp);

        MinHeapify(arr, i, 0);
    }

    for (int i = n-1; i >=0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    char arr[MAX_NUM_STR][MAX_STR_LEN];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    MinHeapSort(arr, n);

    return 0;
}


#include <iostream>
using namespace std;

struct Fruit {
    int sweetness;
};

void swap(Fruit& x, Fruit& y) {
    Fruit temp = x;
    x = y;
    y = temp;
}

void heapifyDown(Fruit* heap, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left].sweetness > heap[largest].sweetness) {
        largest = left;
    }

    if (right < n && heap[right].sweetness > heap[largest].sweetness) {
        largest = right;
    }

    if (largest != i) {
        swap(heap[i], heap[largest]);
        heapifyDown(heap, n, largest);
    }
}

Fruit removeSweetestFruit(Fruit* heap, int& n) {
    if (n == 0) {
        Fruit emptyFruit;
        emptyFruit.sweetness = -1;
        return emptyFruit;
    }

    Fruit sweetestFruit = heap[0];
    heap[0] = heap[n - 1];
    n--;

    heapifyDown(heap, n, 0);

    return sweetestFruit;
}

int main() {
    Fruit* basket;
    int n;

    cin >> n;
    basket = new Fruit[n];

    for (int i = 0; i < n; i++) {
        cin >> basket[i].sweetness;
    }

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyDown(basket, n, i);
    }

    Fruit eatenFruit = removeSweetestFruit(basket, n);

    if (eatenFruit.sweetness != -1) {
        cout << eatenFruit.sweetness << endl;
    } else {
        cout << "Basket is empty" << endl;
    }

    delete[] basket;
    return 0;
}


#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

void deleteAllMaxOccurrences(int arr[], int& n) {

    int maxElement = arr[0];
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == maxElement) {
            count++;
        }
    }

    while (count > 0) {
        arr[0] = arr[n - 1];
        n--;

        heapify(arr, n, 0);
        count--;
    }
}

void displayHeap(int arr[], int n) {

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    buildMaxHeap(arr, n);

    deleteAllMaxOccurrences(arr, n);
    displayHeap(arr, n);

    return 0;
}


#include <iostream>
using namespace std;

void heapify(char arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildMaxHeap(char arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

void heapSort(char arr[], int n) {
    buildMaxHeap(arr, n);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int n;
    cin >> n;
    char arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    heapSort(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}

void buildMinHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

void deleteInRange(int arr[], int& n, int start, int end) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] >= start)
            break;
    }

    int j = i;
    for (; i < n; i++) {
        if (arr[i] > end)
            break;
    }

    int deleteCount = i - j;

    if (deleteCount > 0) {
        for (int k = j + deleteCount; k < n; k++) {
            arr[k - deleteCount] = arr[k];
        }
        n -= deleteCount;
    }

    buildMinHeap(arr, n);
}

void displayHeap(int arr[], int n) {

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int start, end;
    cin >> start >> end;

    buildMinHeap(arr, n);

    deleteInRange(arr, n, start, end);

    displayHeap(arr, n);

    return 0;
}



#include <iostream>
using namespace std;

#define MAX_SIZE 100

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

int extractMax(int arr[], int& n) {
    if (n <= 0)
        return -1;

    if (n == 1) {
        n--;
        return arr[0];
    }

    int root = arr[0];
    arr[0] = arr[n - 1];
    n--;
    heapify(arr, n, 0);

    return root;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    int arr[MAX_SIZE];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    buildMaxHeap(arr, n);

    int maxElement = extractMax(arr, n);
    if (maxElement != -1) {
        cout << maxElement << endl;
    }

    printArray(arr, n);

    return 0;
}


#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

void heapSort(int arr[], int n) {
    buildMaxHeap(arr, n);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i];
        if (i < n - 1) {
            cout << " ";
        }
    }
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    heapSort(arr, n);

    printArray(arr, n);

    return 0;
}

3rd


#include <iostream>
using namespace std;

void max_heap(int *a, int m, int n) {
   int j, temp;
   temp = a[m];
   j = 2 * m;
   while (j <= n) {
      if (j < n && a[j+1] > a[j])
         j = j + 1;
      if (temp > a[j])
         break;
      else if (temp <= a[j]) {
         a[j / 2] = a[j];
         j = 2 * j;
      }
   }
   a[j/2] = temp;
   return;
}

void build_maxheap(int *a, int n) {
   int k;
   for(k = n/2; k >= 1; k--) {
      max_heap(a, k, n);
   }
}

int main() {
   int n, i;
   cin >> n;
   int a[n + 1]; // Make the array 1-based for easier indexing

   for (i = 1; i <= n; i++) {
      cin >> a[i];
   }

   build_maxheap(a, n);

   cout << "Max heap" << endl;
   for (i = 1; i <= n; i++) {
      cout << a[i] << " ";
   }
   cout << endl;

   cout << "The maximum value is " << a[1] << endl;

   return 0;
}


#include <iostream>
using namespace std;

struct Location {
    int distance;
};

void swap(Location& a, Location& b) {
    Location temp = a;
    a = b;
    b = temp;
}

// Function to insert a new location into the binary min-heap
void insertLocation(Location* heap, int& heapSize, Location newLocation) {
    if (heapSize >= 100) {
        cout << "Heap is full. Cannot insert more elements." << endl;
        return;
    }

    // Insert the new location at the end of the heap.
    heap[heapSize] = newLocation;
    int current = heapSize;

    // Heapify up to maintain the min-heap property.
    while (current > 0) {
        int parent = (current - 1) / 2;
        if (heap[current].distance < heap[parent].distance) {
            swap(heap[current], heap[parent]);
            current = parent;
        } else {
            break;  // Min-heap property is satisfied.
        }
    }

    heapSize++;
}

void printHeap(const Location* heap, int heapSize) {
    for (int i = 0; i < heapSize; i++) {
        cout << heap[i].distance << " ";
    }
    cout << endl;
}

int main() {
    const int maxHeapSize = 100;
    Location* binaryHeap = new Location[maxHeapSize];
    int heapSize = 0;

    while (true) {
        Location newLocation;
        if (!(cin >> newLocation.distance)) {
            break;
        }

        insertLocation(binaryHeap, heapSize, newLocation);
    }

    printHeap(binaryHeap, heapSize);

    delete[] binaryHeap;

    return 0;
}


#include <iostream>
using namespace std;

struct Player {
    int score;
};

void swap(Player& a, Player& b) {
    Player temp = a;
    a = b;
    b = temp;
}

void insertPlayer(Player heap[], int& heapSize, Player newPlayer) {
    if (heapSize >= 100) {
        cout << "Heap is full. Cannot insert more elements." << endl;
        return;
    }

    // Insert the new player at the end of the heap.
    heap[heapSize] = newPlayer;
    int current = heapSize;

    // Heapify up to maintain the max-heap property.
    while (current > 0) {
        int parent = (current - 1) / 2;
        if (heap[current].score > heap[parent].score) {
            swap(heap[current], heap[parent]);
            current = parent;
        } else {
            break;  // Max-heap property is satisfied.
        }
    }

    heapSize++;
}

void printHeap(Player heap[], int heapSize) {
    for (int i = 0; i < heapSize; i++) {
        cout << heap[i].score << " ";
    }
    cout << endl;
}

int main() {
    Player maxHeap[100];
    int heapSize = 0;

    while (true) {
        Player newPlayer;
        if (!(cin >> newPlayer.score)) {
            break;
        }

        insertPlayer(maxHeap, heapSize, newPlayer);
    }

    printHeap(maxHeap, heapSize);

    return 0;
}


#include <iostream>
using namespace std;

void min_heap(int *a, int m, int n) {
    int j, temp;
    temp = a[m];
    j = 2 * m;
    while (j <= n) {
        if (j < n && a[j + 1] < a[j]) {
            j = j + 1;
        }
        if (temp < a[j]) {
            break;
        } else if (temp >= a[j]) {
            a[j / 2] = a[j];
            j = 2 * j;
        }
    }
    a[j / 2] = temp;
    return;
}

void build_minheap(int *a, int n) {
    int k;
    for (k = n / 2; k >= 1; k--) {
        min_heap(a, k, n);
    }
}

int main() {
    int n, i;
    cin >> n;

    int a[n + 1]; // Make the array 1-based for easier indexing

    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }

    build_minheap(a, n);

    for (i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}


#include <iostream>
using namespace std;

void min_heap(int *a, int m, int n) {
    int j, temp;
    temp = a[m];
    j = 2 * m;
    while (j <= n) {
        if (j < n && a[j + 1] < a[j]) {
            j = j + 1;
        }
        if (temp < a[j]) {
            break;
        } else if (temp >= a[j]) {
            a[j / 2] = a[j];
            j = 2 * j;
        }
    }
    a[j / 2] = temp;
    return;
}

void build_minheap(int *a, int n) {
    int k;
    for (k = n / 2; k >= 1; k--) {
        min_heap(a, k, n);
    }
}

int main() {
    int n, i;
    cin >> n;

    int a[n + 1]; // Make the array 1-based for easier indexing

    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }

    build_minheap(a, n);

    for (i = 1; i <= n; i++) {
        cout << a[i] << " ";
}
    cout << endl;

    return 0;
}


#include <iostream>
using namespace std;

void max_heap(int *a, int m, int n) {
    int j, temp;
    temp = a[m];
    j = 2 * m;
    while (j <= n) {
        if (j < n && a[j + 1] > a[j]) {
            j = j + 1;
        }
        if (temp > a[j]) {
            break;
        } else if (temp <= a[j]) {
            a[j / 2] = a[j];
            j = 2 * j;
        }
    }
    a[j / 2] = temp;
    return;
}

void build_maxheap(int *a, int n) {
    int k;
    for (k = n / 2; k >= 1; k--) {
        max_heap(a, k, n);
    }
}

int main() {
    int n, i;
    cin >> n;

    int a[n + 1]; // Make the array 1-based for easier indexing

    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }

    build_maxheap(a, n);

    for (i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}


#include <iostream>
using namespace std;

void min_heap(int *a, int m, int n) {
    int j, temp;
    temp = a[m];
    j = 2 * m;
    while (j <= n) {
        if (j < n && a[j + 1] < a[j]) {
            j = j + 1;
        }
        if (temp < a[j]) {
            break;
        } else if (temp >= a[j]) {
            a[j / 2] = a[j];
            j = 2 * j;
        }
    }
    a[j / 2] = temp;
}

void build_minheap(int *a, int n) {
    int k;
    for (k = n / 2; k >= 1; k--) {
        min_heap(a, k, n);
    }
}

int main() {
    int n, i;
    cin >> n;

    int a[n + 1]; // Adjusted array size to start from index 1
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int element;
    cin >> element;
    if (element < 1 || element > n) {
        cout << "Invalid entry" << endl;
        return 0;
    }
    build_minheap(a, n);
    cout << "Min heap is: ";
    for (i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl << "Kth element in min heap is " << a[element];
    return 0;
}


#include <iostream>
using namespace std;

void max_heap(int *a, int m, int n) {
    int j, temp;
    temp = a[m];
    j = 2 * m;
    while (j <= n) {
        if (j < n && a[j + 1] > a[j]) {
            j = j + 1;
        }
        if (temp > a[j]) {
            break;
        } else if (temp <= a[j]) {
            a[j / 2] = a[j];
            j = 2 * j;
        }
    }
    a[j / 2] = temp;
    return;
}

void build_maxheap(int *a, int n) {
    int k;
    for (k = n / 2; k >= 1; k--) {
        max_heap(a, k, n);
    }
}

int main() {
    int n, i;
    cin >> n;

    int a[n + 1]; // Make the array 1-based for easier indexing

    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }

    build_maxheap(a, n);

    for (i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}



