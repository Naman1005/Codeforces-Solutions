#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,k;
    cin>>t;
    string arr = "abcdefghijklmnopqrstuvwxyz";
    while(t--)
    {
        cin>>n>>k;
        for(int i=0; i<n; i++)
            cout<<arr.substr(0,k);
        cout<<"\n";
    }
 }