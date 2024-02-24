/*
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 5, 5, 3, 3, 2};
    int len = 0;
    sort(a, a + 10);
    set<int> Uset;
    for(int i=0; i<10; i++) {Uset.insert(a[i]);}
    cout<<"User Inserted array: ";
    for(int i=0; i<10; i++) {cout<<a[i]<<" ";} cout<<endl;
    cout<<"Union array: ";
    for(auto i : Uset) {cout<<i<<" "; len++;} cout<<endl<<"Len: ";
    cout<<len; cout<<endl;
    //logic code.....
    int k=0, h=0, ar[len];
    for(auto i : Uset)
    {
        ar[k++] = i;
    }
    // Frequency.....
    int Farr[len];
    for(int i=0; i<len; i++)
    {
        int cou = 0;
        for(int j=0; j<10; j++)
        {
            if(ar[i] == a[j])
            {
                cou++;
            }
        }
        Farr[h++] = cou;
    }
    //Frequency Count......
    for(int i=0; i<len; i++)
    {
        cout<<Farr[i]<<" ";
    }
    cout<<endl<<"Frequency: "<<endl;
    for(int i=0; i<len; i++)
    {
        cout<<"F: "<<ar[i]<<" -> "<<Farr[i]<<endl;
    }
} */

















