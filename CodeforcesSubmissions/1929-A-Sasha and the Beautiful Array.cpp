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
    ll t,n,maximum,minimum;
    cin>>t;
    while(t--)
    {
        maximum = INT_MIN;
        minimum = INT_MAX;
        cin>>n;
        ll arr[n];
        for(ll i=0; i<n; i++)
        {
            cin>>arr[i];
            if(maximum<arr[i])
            maximum = arr[i];
            if(minimum>arr[i])
            minimum = arr[i];
        }
        cout<<maximum-minimum<<"\n";
    }
}