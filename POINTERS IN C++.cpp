// POINTERS OBJECT:-
/*
#include<iostream>
using namespace std;

class A
{
    int *arr;
    int size1;
public:
    void get()
    {
        cout<<"*- ";
        cin>>size1;
        arr = new int[size1];
        cout<<"Enter Elements: ";
        for(int i=0; i<size1; i++)
        {
            cin>>*(arr+i);
        }
    }

    void add()
    {
        int sum = 0;
        for(int i=0; i<size1; i++)
        {
            sum = sum + *(arr+i);
        }
        cout<<"Sum is: "<<sum;
    }
};

int main()
{
    A obj;
    obj.get();
    obj.add();
}*/


// POINTERS ON OBJECTS OF CLASS:-
/*
#include<iostream>
using namespace std;

class A
{
    int x;
public:
    void get()
    {
        x = 30;
        void show()
        {
            cout<<x<<endl;
        }
    }
};

int main()
{
    A *ob;
    ob = new A;
    ob->get();
    ob->show();
}*/
/*
#include<iostream>
using namespace std;

class student
{
    int roll_no;
    string name;
public:
    void getdata()
    {
        cout<<"*- ";
        cin>>roll_no;
        cin.ignore();
        getline(cin, name);
    }
    void showdata()
    {
        cout<<"Roll No.:- "<<roll_no<<endl;
        cout<<"Name:- "<<name<<endl;
    }
};

int main()
{
    student *obj[3];
    for(int i=0; i<3; i++)
    {
        obj[i] = new student;
        obj[i]->getdata();
    }
    for(int i=0; i<3; i++)
    {
        obj[i]->showdata();
    }

    return 0;
}
*/
// To access members of a class when pointers are used for object as well as on class members then we use
// pointer to member operators which are  ->* (dereferencing operator) also .*.

// ->* : This is used to access members of class, .* : It is used when object of class itself is used with the member pointer.
// A class member pointer can be declared using ::* (i.e. if class is 'A' A::* means pointer to member of A)
// Suppose class A has data member n then &A::n datatype

#include<iostream>
using namespace std;

class






