// USING COMPILER INPUT:-
/*
#include <iostream>
using namespace std;

struct link {
    char data;
    struct link *next;
};

struct link *start = NULL;
struct link *node;
struct link *current;

void createHelloWorld() {
    string helloWorld = "Hello World";
    int length = helloWorld.length(); // excluding the null-terminator

    for (int i = 0; i < length; i++) {
        node = (struct link *)malloc(sizeof(struct link));
        node->data = helloWorld[i];
        node->next = NULL;

        if (start == NULL) {
            start = node;
            current = node;
        } else {
            current->next = node;
            current = node;
        }
    }
}

void display() {
    struct link *ptr = start;
    cout << "Output: ";
    while (ptr != NULL) {
        cout << ptr->data;
        ptr = ptr->next;
    }
}

int main() {
    createHelloWorld();
    display();
    return 0;
}*/

// USING USER INPUT:-

#include <iostream>
using namespace std;

struct link {
    char data;
    struct link *next;
};

struct link *start = NULL;
struct link *node;
struct link *current;

void createHelloWorld() {
    string helloWorld;
    cout<<"Enter String: ";
    getline(cin, helloWorld);
    int length = helloWorld.length(); // excluding the null-terminator

    for (int i = 0; i < length; i++) {
        node = new link;
        node->data = helloWorld[i];
        node->next = NULL;

        if (start == NULL) {
            start = node;
            current = node;
        } else {
            current->next = node;
            current = node;
        }
    }
}

void display() {
    struct link *ptr = start;
    cout << "Output: ";
    while (ptr != NULL) {
        cout << ptr->data;
        ptr = ptr->next;
    }
}

int main() {
    createHelloWorld();
    display();
    return 0;
}

// Converting number to string :-

/*
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n = 123;
    string na = to_string(n);
} */

















