// WRITE A PROGRAM TO CHNGE INFIX TO POSTFIX USING LLIBRAARY;
/
#include<iostream>
#include<stack>
#include<string.h>
using namespace std;

char infix[50], postfix[50];
stack <char> s1;
char symbol, temp;
int pos = 0, top = -1;
//change
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
    s1.push('#'); //change
    int length = strlen(infix);
    for(int i=0; i<length; i++)
    {
        symbol = infix[i];
        switch(symbol)
        {
        case '(':
            s1.push(symbol); // change
            break;
        case ')':
            while(s1.top()!= '(')
            {
                postfix[pos++] = s1.top();
                s1.pop();
            }  //change
            s1.pop();
            break;
        case '^':
        case '*':
        case '/':
        case '+':
        case '-':
            while(precedance(s1.top()) >= precedance(symbol))
            {
                temp = s1.top();
                s1.pop();
                postfix[pos++] = temp;
            }
            s1.push(symbol);
            break;
        default:
            postfix[pos++] = symbol;
            break;

        }
    }
    while(s1.size()>1) // change
    {
        temp = s1.top(); //change
        s1.pop(); //change
        postfix[pos++] = temp; //change
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

// WRITE A PROGRAM TO CHNGE INFIX TO PREFIX USING LLIBRAARY;
/*
#include<iostream>
#include<stack>
#include<string.h>
using namespace std;

char infix[50], postfix[50];
stack <char> s1;
char symbol, temp;
int pos = 0, top = -1;
//change
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
    s1.push('#'); //change
    int length = strlen(infix);
    for(int i=length; i>=0; i--)
    {
        symbol = infix[i];
        switch(symbol)
        {
        case ')':
            s1.push(symbol); // change
            break;
        case '(':
            while(s1.top()!= ')')
            {
                postfix[pos++] = s1.top();
                s1.pop();
            }  //change
            s1.pop();
            break;
        case '^':
        case '*':
        case '/':
        case '+':
        case '-':
            while(precedance(s1.top()) > precedance(symbol)) // CHANGE
            {
                temp = s1.top();
                s1.pop();
                postfix[pos++] = temp;
            }
            s1.push(symbol);
            break;
        default:
            postfix[pos++] = symbol;
            break;

        }
    }
    while(s1.size()>1) // change
    {
        temp = s1.top(); //change
        s1.pop(); //change
        postfix[pos++] = temp; //change
    }
}
int main()
{
    cout<<"Enter the infix Expression: ";
    cin>>infix;
    infix_to_postfix(infix);
    cout<<"Infix expression is: "<<infix<<endl;
    cout<<"Postfix expression is: ";
    for(int i=strlen(postfix)-1; i>=0; i--)
    {
        cout<<postfix[i];
    }
} */

// WRITE A PROGRAM TO EVALUATE THE POSTFIX EXPRESSION:-
/*
#include<iostream>
#include<cmath>
#include<string.h>
using namespace std;

char postfix[50]; int stack1[50];
char symbol; int n1, n2, top = -1;

void push(int val)
{
    top = top+1;
    stack1[top] = val;
}

int pop()
{
    int temp = stack1[top];
    top = top-1;
    return temp;
}

int evaluate(char symb, int a, int b)
{
    int res;
    switch(symbol)
    {
        case '+': res= a+b; break;
        case '-': res= a-b; break;
        case '*': res= a*b; break;
        case '/': res= a/b; break;
        case '^': res= pow(a,b); break;
    }
}
int main()
{
    cout<<"Enter the postfix expression: ";
    cin>>postfix;
    int length = strlen(postfix);
    for(int i=0; i<length; i++)
    {
        symbol = postfix[i];
        if(isdigit(symbol))
        {
            push(symbol-'0');
        }
        else
        {
            n2 = pop();
            n1 = pop();
            int result = evaluate(symbol, n1, n2);
            push(result);
        }
    }
    cout<<"Stack of top: "<<stack1[top]<<endl;
    return 0;
} */


// WRITE A PROGRAM TO EVALUATE THE POSTFIX EXPRESSION USING INBUILD FUNCTION:-
/*
#include<iostream>
#include<cmath>
#include<stack>
#include<string.h>
using namespace std;

char postfix[50];
stack <int> s1;
char symbol; int n1, n2;

int evaluate(char symb, int a, int b)
{
    int res;
    switch(symb)
    {
        case '+': res= a+b; break;
        case '-': res= a-b; break;
        case '*': res= a*b; break;
        case '/': res= a/b; break;
        case '^': res= pow(a,b); break;
    }
    return res;
}
int main()
{
    cout<<"Enter the postfix expression: ";
    cin>>postfix;
    int length = strlen(postfix);
    for(int i=0; i<length; i++)
    {
        symbol = postfix[i];
        if(isdigit(symbol))
        {
            s1.push(symbol-'0');
        }
        else
        {

            n2 = s1.top();
            s1.pop();
            n1 = s1.top();
            s1.pop();
            int result = evaluate(symbol, n1, n2);
            s1.push(result);
        }
    }
    cout<<"Stack of top: "<<s1.top()<<endl;
    return 0;
}
*/
// EVALUATE THE FOLLOWING PREFIX EXPRESSION:-
/*
#include<iostream>
#include<cmath>
#include<stack>
#include<string.h>
using namespace std;

char postfix[50];
stack <int> s1;
char symbol; int n1, n2;

int evaluate(char symb, int a, int b)
{
    int res;
    switch(symb)
    {
        case '+': res= a+b; break;
        case '-': res= a-b; break;
        case '*': res= a*b; break;
        case '/': res= a/b; break;
        case '^': res= pow(a,b); break;
    }
    return res;
}
int main()
{
    cout<<"Enter the postfix expression: ";
    cin>>postfix;
    int length = strlen(postfix);
    for(int i=length-1; i>=0; i--)
    {
        symbol = postfix[i];
        if(isdigit(symbol))
        {
            s1.push(symbol-'0');
        }
        else
        {

            n1 = s1.top();
            s1.pop();
            n2 = s1.top();
            s1.pop();
            int result = evaluate(symbol, n1, n2);
            s1.push(result);
        }
    }
    cout<<"Stack of top: "<<s1.top()<<endl;
    return 0;
}
*/
/*

#include<iostream>
#include<stack>
#include<string>
using namespace std;

stack<char> str;

void stack1(string n)
{
    string s1 = n;
    int len = s1.length();
    for(int i=0; i<len; i++)
    {
        str.push(s1[i]);
    }
    for(int i=0; i<len; i++)
    {
        cout<<str.top();
        str.pop();
    }
    cout<<endl;
}


int main()
{
    int n1;
    cout<<"Enter the number of string: ";
    cin>>n1;
    cin.ignore();
    for(int i=0; i<n1; i++)
    {
        string n;
        cout<<"Enter String: ";
        getline(cin, n);
        stack1(n);
    }
} */

/*
#include<iostream>
#include<string.h>
using namespace std;
char infix[100], stack1[100], postfix[100];
int top = -1, pos = 0;

void push(char n)
{
    top = top+1;
    stack1[top] = n;
}

char pop()
{
    int temp = stack1[top];
    top = top-1;
    return temp;
}

int precedence(char n)
{
    int p;
    if(n == '^')
        p = 3;
    else if(n=='*' || n=='/') p=2;
    else if(n=='+' || n=='-') p=1;
    else if(n=='(' || n==')') p=0;
    else return -1;
    return p;
}

infix_postfix(char str[])
{
    push('#');
    int len = strlen(str);
    for(int i=0; i<len; i++)
    {
        char n = str[i];
        switch(n)
        {
            case '(':
                push(n);
                break;
            case ')':
                char temp;
                while((temp = pop()) != '(')
                {
                    postfix[pos++] = temp;
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while( precedence(stack1[top]) >= precedence(n))
                {
                    char temp = pop();
                    postfix[pos++] = temp;
                }
                push(n);
                break;
            default:
                postfix[pos++] = n;
                break;
        }
    }
    while(top != 0)
    {
        int temp = pop();
        postfix[pos++] = temp;
    }
}

int main()
{
    cout<<"Enter Infix Notation: ";
    cin>>infix;
    infix_postfix(infix);
    cout<<"Ans: "<<postfix<<endl;
} */
/*
#include<iostream>
#include<cstring>
using namespace std;

char infix[100], stack1[100], postfix[100];
int top = -1, pos = 0;

void push(char n)
{
    top = top + 1;
    stack1[top] = n;
}

char pop()
{
    char temp = stack1[top];
    top = top - 1;
    return temp;
}

int precedence(char n)
{
    int p;
    if (n == '^')
        p = 3;
    else if (n == '*' || n == '/')
        p = 2;
    else if (n == '+' || n == '-')
        p = 1;
    else if (n == '(' || n == ')')
        p = 0;
    else
        return 0;
    return p;
}

void infix_postfix(char str[])
{
    int len = strlen(str);
    for(int i=0; i<len; i++)
    {
        char n = str[i];
        switch(n)
        {
            case '(':
                push(n);
                break;
            case ')':
                char temp;
                while((temp = pop()) != '(')
                {
                    postfix[pos++] = temp;
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while( precedence(stack1[top]) >= precedence(n))
                {
                    char temp = pop();
                    postfix[pos++] = temp;
                }
                push(n);
                break;
            default:
                postfix[pos++] = n;
                break;
        }
    }
    while(top != -1)
    {
        char temp = pop();
        postfix[pos++] = temp;
    }
    postfix[pos] = '\0'; // Null-terminate the postfix string
}

int main()
{
    cout << "Enter Infix Notation: ";
    cin >> infix;
    infix_postfix(infix);
    cout << "Ans: " << postfix << endl;
    return 0;
} */

// SOLVE THE POSTFIX EXPRESSION:-
/*
#include<iostream>
#include<stack>
#include<cstring>
#include<cmath>
using namespace std;
char ch;

string postfix;
stack<int> solve;

int evaluate(char ch, int n1, int n2)
{
    int p;
    switch(ch)
    {
    case '/': p = n1/n2; break;
    case '*': p = n1*n2; break;
    case '+': p = n1+n2; break;
    case '-': p = n1-n2; break;
    case '^': p = pow(n1, n2); break;
    }
    return p;
}

void postfix_solve(string postfix)
{
    int n = postfix.length();
    for(int i=0; i<n; i++)
    {
        ch = postfix[i];
        if(isdigit(ch)) // REMEMBER
        {
            solve.push(ch - '0');
        }
        else
        {
            int n1, n2;
            n1 = solve.top();
            solve.pop();
            n2 = solve.top();
            solve.pop();
            int n3 = evaluate(ch, n2, n1); // REMEMBER
            solve.push(n3);
        }
    }
}

int main()
{
    cout<<"Enter Postfix Expression: ";
    cin>>postfix;
    postfix_solve(postfix);
    cout<<"Ans: "<<solve.top()<<endl;
} */

// USING SIN COS TAN:-

#include<iostream>
#include<stack>
#include<cstring>
#include<cmath>
using namespace std;

char ch;
string postfix;
stack<double> solve; // Use a stack of double for better precision

double evaluate(char ch, double n1, double n2)
{
    double result;
    switch(ch)
    {
    case '/': result = n1 / n2; break;
    case '*': result = n1 * n2; break;
    case '+': result = n1 + n2; break;
    case '-': result = n1 - n2; break;
    case '^': result = pow(n1, n2); break;
    case 's': result = sin(n1); break; // 's' for Sin
    case 'c': result = cos(n1); break; // 'c' for Cos
    case 't': result = tan(n1); break; // 't' for Tan
    }
    return result;
}

void postfix_solve(string postfix)
{
    int n = postfix.length();
    for(int i = 0; i < n; i++)
    {
        ch = postfix[i];
        if(isdigit(ch))
        {
            solve.push(ch - '0');
        }
        else if (ch == 's' || ch == 'c' || ch == 't') // Check for Sin, Cos, Tan
        {
            double n1 = solve.top();
            solve.pop();
            double n3 = evaluate(ch, n1, 0); // 0 as the second operand for Sin, Cos, Tan
            solve.push(n3);
        }
        else
        {
            double n1, n2;
            n1 = solve.top();
            solve.pop();
            n2 = solve.top();
            solve.pop();
            double n3 = evaluate(ch, n2, n1);
            solve.push(n3);
        }
    }
}

int main()
{
    cout<<"Enter Postfix Expression: ";
    cin>>postfix;
    postfix_solve(postfix);
    cout<<"Ans: "<<solve.top()<<endl;
}
































