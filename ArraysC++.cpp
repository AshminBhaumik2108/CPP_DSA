/*
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int Marks[] = {23, 45, 67, 90, 46};
    cout<<"Marks of the Students unordered: "<<endl;
    cout<<Marks[0]<<" "
        <<Marks[1]<<" "
        <<Marks[2]<<" "
        <<Marks[3]<<" "
        <<Marks[4]<<" ";
    int ord = Marks[0];
} */

#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int arr[] = {10, 40, 67, 89, 78};
    int *p = arr; // Same as int* p = arr;
    int sizes = sizeof(arr)/sizeof(arr[0]);
    // for (int i=0; i<sizes; i++) {cout<<"Marks"<<"["<<i<<"] is "<<*(p+i)<<endl;}
    int mi = arr[0];
    int new_arr[] = {};

    for (int i=0; i<sizes; i++) {if (arr[i]<arr[0]) {mi = arr[i];}};
    new_arr[p] = mi;



}






























