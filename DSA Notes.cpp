// DELETE NUMBER FROM AN GIVEN ARRAY:-
/*
#include<iostream>
using namespace std;
int main()
{
    int a[10], num, num_delete, position, i;
    /// Write the user defined elements of the array
    cout<<"Enter the number of elements in array: ";
    cin>>num;
    cout<<"Enter the elements one by one"<<endl;
    for (i=0;i<num;i++) {cin>>a[i];}
    /// User defined number to delete
    cout<<"Enter the number to delete: ";
    cin>>num_delete;
    /// for searching the number from the array & write the position
    for (i=0; i<num; i++)
    {
      if (a[i] == num_delete) {position = i;}
    }
    /// New array changed
    for (i=position; i<num-1;i++)
    {
        a[i] = a[i+1];
    }
    /// New array print
    for (i=0; i<num-1; i++)
    {
        cout<<a[i]<<" ";
    }
} */

// DELETE NUMBER FROM AN GIVEN ARRAY by using new array:-

#include<iostream>
using namespace std;
int main()
{
    int a[10],b[10], num, num_delete, position, i, j=0, flag;
    /// Write the user defined elements of the array
    cout<<"Enter the number of elements in array: ";
    cin>>num;
    cout<<"Enter the elements one by one"<<endl;
    for (i=0;i<num;i++) {cin>>a[i];}
    /// User defined number to delete
    cout<<"Enter the number to delete: ";
    cin>>num_delete;
    /// Making new array
    for(i=0; i<num; i++)
    {
        if(a[i] != num_delete)
        {
           b[j] = a[i]; j++;
        }
        else flag = 1;
    }
    /// Printing new array and also the message, if the message doesn't exist

    if (flag == 0){cout<<endl<<"The number doesn't exist......"<<endl;}
    else
    {
        cout<<endl<<"The new array is: "<<endl;
        for (i=0; i<num-1; i++)
        {
            cout<<b[i]<<" ";
        }

    }

}























