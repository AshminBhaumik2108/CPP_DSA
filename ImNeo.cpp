// STACK MAKING HAND MADE:-
/*
#include<iostream>
#include<string.h>
using namespace std;

char infix[50], stack1[50], postfix[50];
char symbol;
int top = -1;
int k=0, temp;

int push(char val)
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

int precedence(int symb)
{
    int res;
    switch(symb)
    {
        case '^': res = 3; break;
        case '/':
        case '*': res = 2; break;
        case '+':
        case '-': res = 1; break;
        case '(':
        case ')': res = 0; break;
        case '#': res = -1; break;
    }
    return res;
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
                postfix[k++] = temp;
                temp = pop();
            }
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            while(precedence(stack1[top]) >= precedence(symbol))
            {
                temp = pop();
                postfix[k++] = temp;
            }
            push(symbol);
            break;
        default:
            postfix[k++] = symbol;
            break;
        }
    }
    while(top>0)
    {
        temp = pop();
        postfix[k++] = temp;
    }
}



int main()
{
    cout<<"Enter the infix Expression: ";
    cin>>infix;
    infix_to_postfix(infix);
    cout<<"Postfix Expression: "<<postfix<<endl;
} */


// INFIX TO PREFIX:

#include<iostream>
#include<string.h>
using namespace std;

char infix[50], stack1[50], postfix[50];
char symbol;
int top = -1;
int k=0, temp;

int push(char val)
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

int precedence(int symb)
{
    int res;
    switch(symb)
    {
        case '^': res = 3; break;
        case '/':
        case '*': res = 2; break;
        case '+':
        case '-': res = 1; break;
        case '(':
        case ')': res = 0; break;
        case '#': res = -1; break;
    }
    return res;
}


int length;
void infix_to_postfix(char infix[])
{
    push('#');
    length = strlen(infix);
    for(int i=length-1; i>=0; i--)    // CHANGE
    {
        symbol = infix[i];
        switch(symbol)
        {
        case ')':                   // CHANGE
            push(symbol);
            break;
        case '(':                   // CHANGE
            temp = pop();
            while(temp != ')')      // CHANGE
            {
                postfix[k++] = temp;
                temp = pop();
            }
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            while(precedence(stack1[top]) > precedence(symbol))        // CHANGE
            {
                temp = pop();
                postfix[k++] = temp;
            }
            push(symbol);
            break;
        default:
            postfix[k++] = symbol;
            break;
        }
    }
    while(top>0)
    {
        temp = pop();
        postfix[k++] = temp;
    }
}

int main()
{
    cout<<"Enter the infix Expression: ";
    cin>>infix;
    infix_to_postfix(infix);
    cout<<"Postfix Expression:";
    for(int i=length-1; i>=0; i--)   // CHANGE
    {
        cout<<postfix[i];
    }
}
