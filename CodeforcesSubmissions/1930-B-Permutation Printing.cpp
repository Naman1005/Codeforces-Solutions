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
    ll t,n,i,j;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n&1)
        {
            i = 1;
            j = n-1;
            while(i<n)
            {
                cout<<i<<" "<<j<<" ";
                i+=2;
                j-=2;
            }
            cout<<i<<"\n";
        }
        else
        {
            i = n;
            j = 1;
            while(i>0)
            {
                cout<<i<<" "<<j<<" ";
                i-=2;
                j+=2;
            }
            cout<<"\n";
        }
    }
}