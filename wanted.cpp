// for even and odd phrasing.......

#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int a[10], ev[10], e=0, od[10], o=0, c_even=0, i, c_odd=0, num, length_even, length_odd, ne=0, no=0, ir;
    cout<<"Enter number of elements of array: ";
    cin>>num;
    cout<<"Enter the elements of array: "<<endl;
    for(i=0; i<num; i++) {cout<<"Enter Element "<<i+1<<": "; cin>>a[i];}
    cout<<"Enter Array is: ";
    for(i=0; i<num; i++) {cout<<a[i]<<" ";}
    // Entering Element of odd and even seprately .....
    for(i=0; i<num; i++) {if(a[i]%2 == 0) {ev[e++] = a[i];} else {od[o++] = a[i];} } cout<<endl;
    // even array......
    cout<<" Array is even: "; {for(i=0; i<e; i++) {cout<<ev[i]<<" ";}} cout<<endl;
    // Odd array......
    cout<<" Array is odd: "; {for(i=0; i<o; i++) {cout<<od[i]<<" ";}} cout<<endl;
    // making a new array to put elements one after another in Even & Odd positions........
    int end_num = num/2;
    int arr[num];
    if (num%2 == 0)
        {for(ir=0; ir<=end_num; ir+=2)
        {
            arr[ir] = ev[ne++];
            arr[ir+1] = od[no++];
        }
        }
    else
        {
        if(e>o){
            for(ir=0; ir<=end_num; ir+=2)
        {
            arr[ir] = ev[ne++];
            arr[ir+1] = od[no++];
        }
            {arr[num-1] = ev[ne];}}
        else
            {for(ir=0; ir<=end_num; ir+=2)
        {
            arr[ir] = od[no++];
            arr[ir+1] = ev[ne++];
        }
            {arr[num-1] = od[ne];}}
        }
    cout<<"Entered array: "; for(i=0; i<num; i++){cout<<arr[i]<<" ";}
}


Problem Statement



You are assigned to design and implement a program that generates and prints a binary sequence based on the user's input.



The program should utilize a queue data structure implemented using a linked list to efficiently generate and manage the binary sequence.

Input format :
The input consists of a single integer, N, representing the number of binary numbers to generate.

Output format :
The output prints the generated binary numbers, separated by space.

Code constraints :
The generated binary numbers should be in ascending order, starting from 1.

Sample test cases :
Input 1 :
5
Output 1 :
1 10 11 100 101
Input 2 :
2
Output 2 :
1 10

#include <iostream>
#include <queue>

using namespace std;

struct Node {
  int data;
  Node *next;
};

class Queue {
private:
  Node *front;
  Node *rear;

public:
  Queue() {
    front = nullptr;
    rear = nullptr;
  }

  bool isEmpty() {
    return front == nullptr;
  }

  void enqueue(int data) {
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = nullptr;

    if (rear == nullptr) {
      front = rear = new_node;
    } else {
      rear->next = new_node;
      rear = new_node;
    }
  }

  int dequeue() {
    if (isEmpty()) {
      return -1;
    }

    int data = front->data;
    front = front->next;

    if (front == nullptr) {
      rear = nullptr;
    }

    return data;
  }
};

void generateBinarySequence(int n) {
  Queue q;
  q.enqueue(1);

  while (n--) {
    int binary_number = q.dequeue();
    cout << binary_number << " ";

    q.enqueue(binary_number * 10);
    q.enqueue(binary_number * 10 + 1);
  }
}

int main() {
  int n;
  cout << "Enter the number of binary numbers to generate: ";
  cin >> n;

  generateBinarySequence(n);

  return 0;
}
