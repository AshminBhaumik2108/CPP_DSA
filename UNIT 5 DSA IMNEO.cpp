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

#include <iostream>
using namespace std;

struct PrintJob {
    int importance;
};

void swap(struct PrintJob* a, struct PrintJob* b) {
    struct PrintJob temp = *a;
    *a = *b;
    *b = temp;
}

void insertPrintJob(struct PrintJob heap[], int* heapSize, struct PrintJob newPrintJob) {
    if (*heapSize >= 100) {
        cout << "Heap is full. Cannot insert more elements." << endl;
        return;
    }

    // Insert the new print job at the end of the heap.
    heap[*heapSize] = newPrintJob;
    int current = *heapSize;

    // Heapify up to maintain the min-heap property.
    while (current > 0) {
        int parent = (current - 1) / 2;
        if (heap[current].importance < heap[parent].importance) {
            swap(&heap[current], &heap[parent]);
            current = parent;
        } else {
            break;  // Min-heap property is satisfied.
        }
    }

    (*heapSize)++;
}

void printHeap(struct PrintJob heap[], int heapSize) {
    for (int i = 0; i < heapSize; i++) {
        cout << heap[i].importance << " ";
    }
    cout << endl;
}

int main() {
    struct PrintJob binaryHeap[100];
    int heapSize = 0;

    while (1) {
        struct PrintJob newPrintJob;
        if (!(cin >> newPrintJob.importance)) {
            break;
        }

        insertPrintJob(binaryHeap, &heapSize, newPrintJob);
    }

    printHeap(binaryHeap, heapSize);

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


