// NORMAL QUEUE :-
/*
#include <iostream>
using namespace std;
int queue[100], n = 100, front = - 1, rear = - 1;
void Insert()
{
   int val;
   if (rear == n - 1)
   {
        cout<<"Queue Overflow"<<endl;
   }
   else
   {
      if (front == - 1)
      front = 0;

      cout<<"Insert the element in queue : "<<endl;
      cin>>val;

      //rear++;
      queue[++rear] = val;
   }
}
void Delete()
{
   if (front == - 1 || front > rear )
   {
      cout<<"Queue Underflow ";
      return ;
   }
   else
   {
      cout<<"Element deleted from queue is : "<< queue[front] <<endl;
      front++;
   }
}
void Display()
{
   if (front == - 1 || front > rear)
   {
   cout<<"Queue is empty"<<endl;
   }
   else
   {
      cout<<"Queue elements are : ";
      for (int i = front; i <= rear; i++)
      cout<<queue[i]<<" ";
      cout<<endl;
   }
}
int main()
{
   int ch;
   cout<<"1) Insert element to queue"<<endl;
   cout<<"2) Delete element from queue"<<endl;
   cout<<"3) Display all the elements of queue"<<endl;
   cout<<"4) Exit"<<endl;
   while(1)
   {
      cout<<"Enter your choice : "<<endl;
      cin>>ch;
      switch (ch)
      {
         case 1: Insert();
         break;
         case 2: Delete();
         break;
         case 3: Display();
         break;
         case 4: exit(0);
         break;
         default: cout<<"Invalid choice"<<endl;
      }
   }
   return 0;
} */

// CIRCULAR QUEUE:-
/*
#include <iostream>
using namespace std;
# define size 5
int cqueue[size];
int front = -1, rear = -1, n=5;
void insertCQ(int val)
{
   if ((front == 0 && rear == n-1) || ((rear+1) % size == front))
   {
      cout<<"Queue Overflow \n";
      return;
   }
   else if (front == -1)
   {
      front = 0;
      rear = 0;
   }
   else if(rear == n-1)
   {
        rear = 0;
   }
   else
   {
      rear = rear + 1;
   }
   cqueue[rear] = val ;
}
void deleteCQ() {
   if (front == -1)
   {
      cout<<"Queue Underflow\n";
      return ;
   }
   cout<<"Element deleted from queue is : "<<cqueue[front]<<endl;

   if (front == rear)
   {
      front = -1;
      rear = -1;
   }
   else if(front == n-1)
   {
      front = 0;
   }
   else
   {
      front = front + 1;
   }
}
void displayCQ()
{
    if (front == -1)
   {
      cout<<"Queue is empty"<<endl;
      return;
   }
   cout<<"Queue elements are :\n";
   if (front <= rear)
   {
      while (front <= rear)
      {
         cout<<cqueue[front]<<" ";
         front++;
      }
   }
   else
   {
      while (front <= n - 1)
      {
         cout<<cqueue[front]<<" ";
         front++;
      }

      front = 0;
      while (front <= rear)
      {
         cout<<cqueue[front]<<" ";
         front++;
      }
   }
   cout<<endl;
}
int main() {

   int ch, val;
   cout<<"1)Insert\n";
   cout<<"2)Delete\n";
   cout<<"3)Display\n";
   cout<<"4)Exit\n";
   while(1)
   {
      cout<<"Enter choice : "<<endl;
      cin>>ch;
      switch(ch) {
         case 1:
         cout<<"Input for insertion: "<<endl;
         cin>>val;
         insertCQ(val);
         break;

         case 2:
         deleteCQ();
         break;

         case 3:
         displayCQ();
         break;

         case 4:
         exit(0);
         break;
         default: cout<<"Incorrect!\n";
      }
   }
   return 0;
} */

// DOUBLE CIRCULAR LINKED LIST:-
/*
    #include <iostream>
    using namespace std;
    #define size 5
    int deque[size];
    int f = -1, r = -1;
    //  insert_front function will insert the value from the front
    void insert_front(int x)
    {
        if((f==0 && r==size-1) || (f==r+1))
        {
            cout<<"Overflow";
        }
        else if((f==-1) && (r==-1))
        {
            f=r=0;
            deque[f]=x;
        }
        else if(f==0)
        {
            f=size-1;
            deque[f]=x;
        }
        else
        {
            f=f-1;
            deque[f]=x;
        }
    }

    // insert_rear function will insert the value from the rear
    void insert_rear(int x)
    {
        if((f==0 && r==size-1) || (f==r+1))
        {
            cout<<"Over flow";
        }
        else if((f==-1) && (r==-1))
        {
            r=0;
            deque[r]=x;
        }
        else if(r==size-1)
        {
            r=0;
            deque[r]=x;
        }
        else
        {
            r++;
            deque[r]=x;
        }

    }

    // display function prints all the value of deque.
    void display()
    {
        int i=f;
        printf("\nElements in a deque are: ");

        while(i!=r)
        {
            cout<<deque[i];
            i=(i+1)%size;
        }
         cout<<deque[r]<<endl;
    }

    // getfront function retrieves the first value of the deque.
    void getfront()
    {
        if((f==-1) && (r==-1))
        {
            cout<<"queue is empty";
        }
        else
        {
            cout<<"\nThe value of the element at front is:"<<deque[f];
        }

    }

    // getrear function retrieves the last value of the deque.
    void getrear()
    {
        if((f==-1) && (r==-1))
        {
            cout<<"queue is empty";
        }
        else
        {
            cout<<"\nThe value of the element at rear is:"<<deque[r];

        }

    }

    // delete_front() function deletes the element from the front
    void delete_front()
    {
        if((f==-1) && (r==-1))
        {
            cout<<"queue is empty";
        }
        else if(f==r)
        {
            cout<<"Deleted element is:"<<deque[f];
            f=-1;
            r=-1;

        }
         else if(f==(size-1))
         {
             cout<<"Deleted element is:"<<deque[f];
             f=0;
         }
         else
         {
             cout<<"Deleted element is:"<<deque[f];
              f=f+1;
         }
    }

    // delete_rear() function deletes the element from the rear
    void delete_rear()
    {
        if((f==-1) && (r==-1))
        {
            cout<<"queue is empty";
        }
        else if(f==r)
        {
            cout<<"Deleted element is:"<<deque[r];
            f=-1;
            r=-1;

        }
         else if(r==0)
         {
             cout<<"Deleted element is:"<<deque[r];
             r=size-1;
         }
         else
         {
              cout<<"Deleted element is:"<<deque[r];
              r=r-1;
         }
    }

    int main()
    {
        int ch,val;
        cout<<"1.insert_Front  2.insert_rear 3.delete_front 4.delete_rear 5.dispaly 6.Exit:"<<endl;
        cout<<"7.get_front  8.get_rear"<<endl;
        while(1)
        {
            cout<<"Enter your choice:(1/2/3/4/5/6/7/8):";
            cin>>ch;
            switch(ch)
            {
                case 1:cout<<"Enetr a number"; cin>>val; insert_front(val);break;
                case 2:cout<<"Enetr a number"; cin>>val;insert_rear(val);break;
                case 3:delete_front();break;
                case 4:delete_rear();break;
                case 5:display();break;
                case 6:exit(0);break;
                case 7:getfront();break;
                case 8:getrear();break;
            }
        }

        return 0;
    }
*/

// QUEUE USING STANDARD TEMPLATE LIBRARY:-

/*
#include<iostream>
#include<queue>
using namespace std;
const int size = 100;
queue <int> que;

void loop()
{
    int n;
    cout<<"Enter the elements( Until value is -1 ): "<<endl;
    while(1)
    {
        cout<<"*: "; cin>>n;
        if(n==-1) break;
        que.push(n);
    }
    while(!que.empty())
    {
        cout<<que.front()<<" ";
        que.pop();
    }
    cout<<endl;
}

int main()
{
    int n;
    cout<<" ....Enter Elements in stack...."<<endl;
    cout<<"Enter the number of queue to print: ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        loop();
    }
    cout<<endl<<"YOUR LOOP IS COMPLITED.........."<<endl;
} */

// STRING OPPOSITE PRINT IN QUEUE:-

#include<iostream>
#include<string>
#include<queue>
using namespace std;
queue<char> que;

void rev_str(string str)
{
    int len = str.length();
    for(int i=len; i>=0; i--)
    {
        que.push(str[i]);
    }
    cout<<"Entered String in Reverse: ";
    while(!que.empty())
    {
        cout<<que.front()<<"";
        que.pop();
    }
}

int main()
{
    string str;
    cout<<"Enter String: ";
    getline(cin, str);
    rev_str(str);
}


















