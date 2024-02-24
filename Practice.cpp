/*

#include<iostream>
#include<string>
using namespace std;

struct student
{
    int rollNumber;
    string name;
    int marks[5];
    int total;
    double average;
};

int main()
{
    student Student;
    getline(cin, Student.name);
    cin>>Student.rollNumber;

    for(int i=0; i<5; i++)
    {
        cin>>Student.marks[i];
        Student.total += Student.marks[i];
    }
    Student.average = static_cast<double>(Student.total)/5.0;

    cout<<"NAME: "<<Student.name<<endl;
    cout<<"ROLL NO: "<<Student.rollNumber<<endl;

    if(Student.marks[0] >= 50 && Student.marks[1] >= 50
       && Student.marks[2] >= 50 && Student.marks[3] >= 50
       && Student.marks[4] >= 50)
       { if (Student.average >=75)
       {
           cout<<"RESULT: Pass"<<endl<<"Distinction";
       }
       else if(Student.average >= 60)
       {
           cout<<"RESULT: Pass"<<endl<<"First Class";
       }
       else if(Student.average >= 50)
       {
           cout<<"RESULT: Pass"<<endl<<"Second Class";
       }
       }
    else
       {
           int numPassSub = 0;
           for(int i=0; i<5; i++)
           {
               if(Student.marks[i] >= 50) numPassSub++;
           }

           if (numPassSub >= 3) cout<<"RESULT: Pass";
           else cout<<"RESULT: Fail";
       }
} */
/*

#include<iostream>
#include<set>
using namespace std;

struct link
{
    int data;
    struct link *next;
};

struct link *start1 = NULL;
struct link *node1;
struct link *current1;
int n;

void create1()
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        node1 = new link;
        cin>>node1->data;
        node1->next = NULL;
        if(start1 == NULL)
        {
            current1 = node1;
            start1 = node1;
        }
        else
        {
            current1->next = node1;
            current1 = node1;
        }
    }
}

struct link *start2 = NULL;
struct link *node2;
struct link *current2;
int m;

void create2()
{
    cin>>m;
    for(int i=0; i<m; i++)
    {
        node2 = new link;
        cin>>node2->data;
        node2->next = NULL;
        if(start2 == NULL)
        {
            current2 = node2;
            start2 = node2;
        }
        else
        {
            current2->next = node2;
            current2 = node2;
        }
    }
}

void sort1()
{
    struct link *ptr1;
    struct link *current;
    int swapped;

    if (start1 == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = start1;
        current = ptr1->next;
        while(current != NULL)
        {
            if(ptr1->data > current->data)
            {
                int temp;
                temp = ptr1->data;
                ptr1->data = current->data;
                current->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
            current = current->next;
        }
    }while (swapped);

    cout<<"First Linked list: ";
    struct link *p = start1;
    for(int i=0; i<n; i++)
    {
        cout<<p->data<<" ";
        p = p->next;
    }

}

void sort2()
{
    struct link *ptr2;
    struct link *current;
    int swapped;

    if (start2 == NULL)
        return;

    do
    {
        swapped = 0;
        ptr2 = start2;
        current = ptr2->next;
        while(current != NULL)
        {
            if(ptr2->data > current->data)
            {
                int temp;
                temp = ptr2->data;
                ptr2->data = current->data;
                current->data = temp;
                swapped = 1;
            }
            ptr2 = ptr2->next;
            current = current->next;
        }
    }while (swapped);

    cout<<endl<<"Second Linked list: ";
    struct link *p = start2;
    for(int i=0; i<m; i++)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
}


void union1()
{
    struct link *p1 = start1;
    struct link *p2 = start2;
    set<int> unionSet;

    while (p1 != NULL)
    {
        unionSet.insert(p1->data);
        p1 = p1->next;
    }

    while (p2 != NULL)
    {
        unionSet.insert(p2->data);
        p2 = p2->next;
    }

    cout<<endl<< "Union Linked list: ";
    for (auto val : unionSet)
    {
        cout << val << " ";
    }
    cout << endl;
}

int main()
{
    create1();
    create2();
    sort1();
    sort2();
    union1();
} */

#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include<iomanip>
using namespace std;

string print(int, string);

int main()
{
    int Roll; string Name;
    cout << "Enter Roll: "; cin >> Roll;
    cin.ignore();
    cout << "Enter Name: "; getline(cin, Name);

    // Putting Everything in other given function....
    string bye_back = print(Roll, Name);

    cout << bye_back << endl;

    return 0;
}

string print(int Roll, string Name)
{
    cout  << "The Roll Number is: "; cout << Roll << endl;
    cout << "The Name is: "; cout << Name << endl;

    return "The Statement is Found. THANK YOU...";
}







































































