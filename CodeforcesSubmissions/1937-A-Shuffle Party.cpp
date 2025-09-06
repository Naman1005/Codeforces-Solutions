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
    ll t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        n = log2(n);
        n = pow(2,n);
        cout<<n<<"\n";
    }
}