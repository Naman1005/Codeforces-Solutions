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
    ll t,n,i,count;
    cin>>t;
    string s;
    while(t--)
    {
        count = 0;
        cin>>n>>s;
        for(i = 0; i<n-1; i++)
        {
            if(s[i] == '*' && s[i+1] == '*')
            break;
            else if(s[i] == '@')
            count++;
        }
        if(i == n-1 && s[i] == '@')
        count++;
        cout<<count<<"\n";
    }
}