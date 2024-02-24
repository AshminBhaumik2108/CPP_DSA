#include<iostream>
using namespace std;

int main()
{
    int n, left, right, mid; string key;
    cout<<"Number of elements: "; cin>>n;
    string arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    cout<<"Key element: "; cin>>key;
    left = 0; right = n-1;
    while(left <= right)
    {
        mid = (left + right)/2;
        if(arr[mid] == key)
        {
            cout<<"The element is found i.e. "<<arr[mid]<<endl;
            exit(0);
        }
        else if(arr[left] < key)
        {
            left = mid+1;
        }
        else
        {
            right = mid-1;
        }
    }
    cout<<"Element not found.....";
}
