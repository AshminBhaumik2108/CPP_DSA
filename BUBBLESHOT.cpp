/// bubble shot
/
#include<iostream>
using namespace std;
int main()
{
    int arr[10],num,i,j, temp;
    cout<<"Enter number of array of elements: "<<endl;
    cin>>num;
    for(i=0; i<num; i++)
    {
        cout<<"Enter "<<i+1<<": ";
        cin>>arr[i];
    }
    cout<<"User defined array: "<<endl;
    for(i=0; i<num; i++)
    {
        cout<<arr[i]<<" ";
    }
    /// Sorting array in Bubble sort in ASCENDING ORDER
    for(i=0; i<num; i++)
    {
        for(j=0; j<num-1-i; j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j]; /// a[i], a[i+1] = a[i+1], a[i]
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    cout<<endl<<"Sorted array is: "<<endl;
    for(i=0; i<num; i++)
    {
        cout<<arr[i]<<" ";
    }

} */

/// Selection Sort of the array
/*
#include<iostream>
using namespace std;
int main()
{
    int a[10], n, i, loc, j, temp;
    cout<<"Enter number of elements: ";
    cin>>num;
    for (i=0; i<n; i++)
    {
        cin<<a[i];
    }
    cout<<"User defined elements: "<<endl;
    for(i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    for(i=0; i<n; i++)
    {
        small = a[i];
        loc = i;
        for(j=i+1; j<n; j++)
        {
            if(a[j]<small)
            {
                small = a[j];
                loc = j;
            }
        }
        temp = a[i];
        a[i] = a[loc];
        a[loc] = a[i];
    }
    cout<<"Sorted array is: ";
    for(i=0; i<num;i++)
    {
        cout<<a[i]<<" ";
    }


} */

/// WAP to except 1 element from the user and check whether the number is armstrong or not..

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int num, a[10];
    cout<<"Enter the number to check: ";
    cin>>num;
    int num_1 = num;
    int cou = 0;
    while(num != 0) {cou++; num /= 10;}
    /// cout<<cou;
    num = num_1;
    int s = 0;
    int sum = 0;
    for(int i=0; i<cou; i++)
    {
        s = num%10;
        sum = sum+(pow(s,cou));
        num %= 10;
    }
    cout<<sum;

}

























