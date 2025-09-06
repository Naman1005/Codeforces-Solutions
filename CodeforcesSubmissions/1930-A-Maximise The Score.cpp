#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void inp_out(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt" ,"r" , stdin);
    freopen("output.txt" ,"w" , stdout);
    #endif
}
int main()
{
    inp_out();
    ll t,n,sum;
    cin>>t;
    while(t--)
    {
        cin>>n;
        n *= 2;
        ll arr[n];
        for(ll i = 0; i<n; i++)
        cin>>arr[i];
        sort(arr,arr+n);
        sum = 0;
        for(int i = n-2; i>=0; i-=2)
        sum += arr[i];
        cout<<sum<<"\n";
    }
}