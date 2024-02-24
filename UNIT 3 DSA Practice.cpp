// PATTERN FOUND AND MATCH IN DEQUE....
/*
#include <iostream>
#include <string>
#include <deque>
using namespace std;

void findPattern(string& text, string& pattern) {
    int textLength = text.length();
    int patternLength = pattern.length();

    if (patternLength > textLength) {
    cout << "Pattern is longer than the string" << endl;
    return;
    }

    deque<int> positions;

    for (int i = 0; i <= textLength - patternLength; ++i) {
    int j;

    for (j = 0; j < patternLength; ++j)
    {
    if (text[i + j] != pattern[j]) {
    break;
    }
    }

    if (j == patternLength) {
    positions.push_back(i);
    }
    }

    if (positions.empty()) {
    std::cout << "Pattern not found" << std::endl;
    }
    else {
    for (int pos : positions) {
    std::cout << "Pattern found at index " << pos << std::endl;
    }
    }
}

int main() {
    std::string text, pattern;
    std::getline(std::cin, text); // Read the text
    std::cin >> pattern; // Read the pattern

    findPattern(text, pattern);

    return 0;
} */

// USING LINKED LIST:-
/*
#include <iostream>
#include <string>
#include <deque>

using namespace std;

struct Node {
    char data;
    Node* next;
};

void findPattern(string str, string pattern) {
    Node* head = nullptr;
    Node* tail = nullptr;
    int n = str.size();
    int m = pattern.size();
    bool found = false;

    // Check if the pattern is longer than the string
    if (m > n) {
        cout << "Pattern is longer than the string" << endl;
        return;
    }

    // Initialize the deque with the first m characters of the string
    deque<char> dq(str.begin(), str.begin() + m);

    // Initialize the linked list with the first m characters of the string
    for (int i = 0; i < m; i++) {
        Node* newNode = new Node();
        newNode->data = dq[i];
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Check if the linked list matches the pattern and print the first match
    Node* current = head;
    string temp = "";
    while (current != nullptr) {
        temp += current->data;
        current = current->next;
    }
    if (temp == pattern) {
        cout << "Pattern found at index 0" << endl;
        found = true;
    }

    // Slide the window through the string and check for matches
    for (int i = m; i < n; i++) {
        dq.pop_front();
        dq.push_back(str[i]);
        Node* newNode = new Node();
        newNode->data = str[i];
        newNode->next = nullptr;
        tail->next = newNode;
        tail = newNode;
        head = head->next;
        temp = "";
        current = head;
        while (current != nullptr) {
            temp += current->data;
            current = current->next;
        }
        if (temp == pattern) {
            cout << "Pattern found at index " << i - m + 1 << endl;
            found = true;
        }
    }

    // If pattern is not found, print a message
    if (!found) {
        cout << "Pattern not found" << endl;
    }
}

int main() {
    string str, pattern;
    getline(cin, str);
    getline(cin, pattern);
    findPattern(str, pattern);
    return 0;
} */


// FIND PATTERN PRACTICE USING LINKED LIST:-
/*
#include<iostream>
#include<cstring>
using namespace std;

// Defining a Structure for Linked-List Making......
struct link
{
    string data;
    link* next;
};

//Date Formates of Linked List......
struct link *head = nullptr;
struct link *tail = nullptr;
int flag = 0;

void patternCheck(const string &str, const string &pattern)
{
    int str_size = str.length(); //cout<<str_size;
    int pattern_size = pattern.length(); //cout<<pattern_size;

    // For checking the length of two strings....
    if(pattern_size > str_size)
    {
        cout<<"Pattern size is Greater then String Size! "<<endl;
        exit(0);
    }

    // For checking the first Position of the string.....
    //INSERTION :-
    for(int i = 0; i < pattern_size; i++)
    {
        link* newnode = new link;
        newnode->data = str[i];
        newnode->next = nullptr;
        if(head == nullptr)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
    }

    //CHECKING:-
    string temp = "";
    link* current = head;
    while(current != nullptr)
    {
        temp += current->data;
        //cout<<current->data<<" ";
        current = current->next;
    }

    if(temp == pattern)
    {
        cout<<"Pattern found at Index 0."<<endl;
        flag = 1;
    }

    //For checking other indexes
    for(int i = pattern_size-1; i < str_size; i++)
    {
        temp = "";
        link* newnode = new link;
        newnode->data = str[i];
        newnode->next = nullptr;
        head = head->next;
        tail->next = newnode;
        tail = newnode;
        link* cur = head;
        while(cur != nullptr)
        {
            temp += cur->data;
            cur = cur->next;
        }

        if(temp == pattern)
        {
            cout<<"Position found at Index "<< i - pattern_size + 1 <<endl;
            flag = 1;
        }
    }

    if(flag == 0)
    {
        cout<<"Position not found...."<<endl;
        exit(0);
    }
}

int main()
{
    string str, pattern;
    cout<<"Enter the String to check: ";
    getline(cin, str);
    cout<<"Enter the Pattern: ";
    cin>> pattern;

    patternCheck(str, pattern);
} */
/*
#include<iostream>
#include<deque>
#include<vector>
using namespace std;

struct Node
{
    int data;
    //int freq = 0;
};

int i = -1;

void frequencyCheck(deque<int> &n)
{
      ;
      while(!n.empty())
      {
          int num = n.front();
          for(int j = 0; j <=i; j++)
          {
              if(num == arr[j].data)
              {
                  //arr[j].freq++;
              }
              else
              {
                  i++;
                  arr[i].data = num;
                  //arr[i].freq++;
              }
          }
      }



}

int main()
{
    deque<int> n1;
    while(1)
    {
        int n;
        cout<<"*: ";
        cin>>n;
        if(n == -1)
            break;
        n1.push_back(n);
    }

    // putting the elements in deque function......

    frequencyCheck(n1);
} */

// To Print EVEN & ODD elements:-
/*
#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *front = nullptr;
node *front1 = nullptr;
node *back = nullptr;

void push_back(int n)
{
    node *newnode = new node;
    newnode->data = n;
    newnode->next = nullptr;
    if(front == nullptr && back == nullptr)
    {
        front = newnode;
        front1 = newnode;
        back = newnode;
    }
    else
    {
        back->next = newnode;
        back = newnode;
    }
}

bool empty()
{
    if(front1 == nullptr)
        return 0;
}

int pop_front()
{
    int temp;
    temp = front1->data;
    front1 = front1->next;

    return temp;
}

void element()
{
    while(1)
    {
        int n;
        cout<<"*: "; cin>>n;
        if(n == -1)
            break;
        push_back(n);
    }

    cout<<"Even Numbers: ";
    while(empty())
    {
        int temp;
        temp = pop_front();
        if(temp % 2 == 0)
        {
            cout<<temp<<" ";
        }
    }

    front1 = front;
    cout<<endl<<"Odd Numbers: ";
    while(empty())
    {
        int temp;
        temp = pop_front();
        if(temp % 2 != 0)
        {
            cout<<temp<<" ";
        }
    }
}

int main()
{
    element();
} */

// DECIMAL TO BINARY IN C++........

/*
#include<iostream>
using namespace std;

int main()
{
    int binary[32];
    int i=0;
    int n = 8;
    while(n>0)
    {
        binary[i] = n%2;
        n /= 2;
        i++;
    }
    for(int j=i-1; j>=0; j--)
    {
        cout<<binary[j]<<"";
    }

} */

// priority_queue:-

#include<iostream>
#include<bits/stdc++.h>
#include<queue>
using namespace std;

priority_queue<int> arr;

int main()
{
    int n;
    cout<<"Enter Range: ";
    cin>>n;
    int ar[n];
    cout<<"Enter Elements: ";
    for(int i=0; i<n; i++)
    {
        cin>>ar[i];
    }
    //queue....
    for(int i=0; i<n; i++)
    {
        arr.push(ar[i]);
    }
    cout<<"Priority Queue order: ";
    while(!arr.empty())
    {
        cout<<arr.top()<<" ";
        arr.pop();
    }
}




















