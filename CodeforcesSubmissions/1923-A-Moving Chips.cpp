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
    ll t,n,x,y,count;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll arr[n];
        x = -1, y = n-1, count = 0;
        for(ll i = 0; i<n; i++)
        {
            cin>>arr[i];
            if(arr[i] == 1 && x == -1)
            x = i;
            if(x>=0 && arr[i]==1)
            y = i;
            else if(x>=0 && arr[i] == 0)
            count++;
        }
        // cout<<x<<" "<<y<<" "<<count<<" ";
        cout<<count-(n-y)+1<<"\n";
    }
}