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
    ll n,count_a,count_b,t;
    cin>>t;
    string s;
    while(t--)
    {
        cin>>s;
        count_a = 0, count_b = 0;
        n = s.length();
        for(int i=0; i<n; i++)
        {
            if(s[i] == 'A')
            count_a++;
            else
            count_b++;
        }
        count_a>count_b?cout<<"A":cout<<"B";
        cout<<"\n";
    }
}