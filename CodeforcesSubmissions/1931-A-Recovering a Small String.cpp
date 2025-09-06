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
    while(t--){
        cin>>n;
        if(n == 3)
        cout<<"aaa\n";
        else if(n>3 && n<=28)
        {
            cout<<"aa"<<(char)(n+94)<<"\n";
        }
        else if(n>28 && n<=53)
        {
            cout<<"a"<<(char)(n+69)<<"z\n";
        }
        else if(n>53 && n<=78)
        {
            cout<<(char)(n+44)<<"zz\n";
        }
    }
}