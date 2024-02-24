//WAP TO USE PUSH AND POP OPERATION USING ARRAY
/*
#include<iostream>
using namespace std;

void push();
void pop();
void display();

const int maxsize = 10;

int top = -1;
int stack1[maxsize];
int main()
{
    cout<<"1. Push 2. Pop 3. display 4. Exit "<<endl;
    while(1)
    {
        int ch;
        cout<<"Enter your choice(1/2/3/4): "; cin>>ch;
        switch(ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
            break;
        default:
            cout<<"Invalid Choice !!!!!!"<<endl;
        }

    }
}

void push()
{
    if(top == maxsize-1)
    {
        cout<<"Stack overflow condition."<<endl;
    }
    else
    {
        cout<<"Enter the number: ";
        top = top+1;
        cin>>stack1[top];
    }
}

void pop()
{
    int item;
    if(top == -1)
    {
        cout<<"Stack Underflow condition.."<<endl;
    }
    else
    {
        item = stack1[top];
        top = top-1;
        cout<<"Deleted element is: "<<item;
    }
}

void display()
{
    if(top == -1)
    {
        cout<<"Stack is empty....."<<endl;
    }
    else
    {
        cout<<"Stack elements are: ";
        for(int i=top; i>=0; i--)
        {
            cout<<stack1[i]<<" ";
        }
        cout<<endl;
    }
}
*/

// WAP to perform push and pop using linked list: -

/*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct link
{
    int data;
    struct link *next;
};

link *top = NULL;
link *node;


void push(int value);
void pop();
void display();

int main()
{
    cout<<"1. PUSH  2. POP  3. DISPLAY  4. EXIT : "<<endl;
    while(1)
    {
        int ch;
        cout<<"Enter your choice(1/2/3/4): "; cin>>ch;
        switch(ch)
        {
        case 1:
            int val;
            cout<<"Enter a element: ";
            cin>>val;
            push(val);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            cout<<"Invalid Choice !!!!!!"<<endl;
        }
    }
}

void push(int value)
{
    node = new link;
    node->data = value;
    node->next = top;
    top = node;
}

void pop()
{
    int temp;
    if(top == NULL)
    {
        cout<<"Stack Underflow";
    }
    else
    {
        temp = top->data;
        top = top->next;
    }
}

void display()
{
    link *ptr = top;
    if(ptr == NULL)
    {
        cout<<"Stack is empty!!"<<endl;
    }
    else
        while(ptr != NULL)
       {
           cout<<ptr->data<<" ";
           ptr = ptr->next;
       }
       cout<<endl;
}


// APPLICATION OF STACK:-

// 1. Evalutation of Expression...... Prefix(Polish Notation), Postfix(Reverse Polish)

//Convert the Following Infix to postfix:

// A + B - C * (D / E ^ F) + G / H (Convert into postfix)

*/

// CONVERT THE FOLLOWING INFIX TO POSTFIX USING STACK:-

/*
#include<iostream>
#include<string.h>
using namespace std;

char infix[50], stack1[50], postfix[50];
char symbol, temp;
int pos = 0, top = -1;

void push(char val)
{
    top = top+1;
    stack1[top] = val;
}

char pop()
{
    temp = stack1[top];
    top = top-1;
    return temp;
}

int precedance(char symb)
{
    int p;
    switch(symb)
    {
    case '^':
        p=3; break;
    case '*':
    case '/':
        p=2; break;
    case '+':
    case '-':
        p=1; break;
    case '(':
    case ')':
        p=0; break;
    case '#': p=-1; break;
    }
    return p;
}

void infix_to_postfix(char infix[])
{
    push('#');
    int length = strlen(infix);
    for(int i=0; i<length; i++)
    {
        symbol = infix[i];
        switch(symbol)
        {
        case '(':
            push(symbol);
            break;
        case ')':
            temp = pop();
            while(temp != '(')
            {
                postfix[pos++] = temp;
                temp = pop();
            }
            break;
        case '^':
        case '*':
        case '/':
        case '+':
        case '-':
            while(precedance(stack1[top]) >= precedance(symbol))
            {
                temp = pop();
                postfix[pos++] = temp;
            }
            push(symbol);
            break;
        default:
            postfix[pos++] = symbol;
            break;

        }
    }
    while(top>0)
    {
        temp = pop();
        postfix[pos++] = temp;
    }
}
int main()
{
    cout<<"Enter the infix Expression: ";
    cin>>infix;
    infix_to_postfix(infix);
    cout<<"Infix expression is: "<<infix<<endl;
    cout<<"Postfix expression is: "<<postfix<<endl;
}
*/

//CONVERT THE FOLLOWING INFIX TO PREFIX BY USING STACK:-

/*
#include<iostream>
#include<string.h>
using namespace std;

char infix[50], stack1[50], prefix[50];
char symbol, temp;
int pos = 0, top = -1;

void push(char val)
{
    top = top+1;
    stack1[top] = val;
}

char pop()
{
    temp = stack1[top];
    top = top-1;
    return temp;
}

int precedance(char symb)
{
    int p;
    switch(symb)
    {
    case '^':
        p=3; break;
    case '*':
    case '/':
        p=2; break;
    case '+':
    case '-':
        p=1; break;
    case '(':
    case ')':
        p=0; break;
    case '#': p=-1; break;
    }
    return p;
}

void infix_to_prefix(char infix[])
{
    push('#');
    int length = strlen(infix);
    for(int i=length-1; i>0; i--) //change
    {
        symbol = infix[i];
        switch(symbol)
        {
        case ')': //change
            push(symbol);
            break;
        case '(': //change
            temp = pop();
            while(temp != '(')
            {
                prefix[pos++] = temp;
                temp = pop();
            }
            break;
        case '^':
        case '*':
        case '/':
        case '+':
        case '-':
            while(precedance(stack1[top]) > precedance(symbol))  //change
            {
                temp = pop();
                prefix[pos++] = temp;
            }
            push(symbol);
            break;
        default:
            prefix[pos++] = symbol;
            break;

        }
    }
    while(top>0)
    {
        temp = pop();
        prefix[pos++] = temp;
    }
}
int main()
{
    cout<<"Enter the infix Expression: ";
    cin>>infix;
    infix_to_prefix(infix);
    cout<<"Infix expression is: "<<infix<<endl;
    cout<<"Prefix expression is: "; //change
    for(int i=strlen(prefix)-1; i>=0; i--)
    {
        cout<<prefix[i];
    }
}*/

// USING PREDEFINED FUNCTION

#include<iostream>
#include<stack>
using namespace std;

stack<int> s1;
int main()
{
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.pop();
    cout<<s1.top();
    cout<<endl<<s1.size();
    while( !s1.end())
    {
        cout<<s1.top();
        s1.pop();
    }
    return 0;
}





























