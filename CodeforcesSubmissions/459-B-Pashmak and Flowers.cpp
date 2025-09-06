#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    ll n; cin>>n;
    ll arr[n];
    ll MIN = LONG_LONG_MAX, MAX = LONG_LONG_MIN;
    for(ll i=0; i<n; i++)
    {
        cin>>arr[i];
        if(MIN>arr[i]) MIN = arr[i];
        if(MAX<arr[i]) MAX = arr[i];
    }
    ll maxNo = 0, minNo = 0;
    for(ll i=0; i<n; i++)
    {
        if(arr[i] == MAX) maxNo++;
        if(arr[i] == MIN) minNo++;
    }
    if(MAX != MIN)
    cout<<MAX-MIN<<" "<<maxNo*minNo;
    else
    cout<<0<<" "<<minNo*(minNo-1)/2;
}