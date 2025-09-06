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
    ll t,n,ans;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll arr[n];
        for(ll i=0; i<n; i++)
        cin>>arr[i];
        sort(arr,arr+n);
        ans = abs(arr[n-1] - arr[0]) + abs(arr[0] - arr[n-2]) + abs(arr[n-2] - arr[1]) + abs(arr[1] - arr[n-1]);
        cout<<ans<<"\n";
    }
}