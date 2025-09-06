#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n,t,i,j; cin>>t;
    string s;
    while(t--)
    {
        cin>>n>>s;
        for(i=0; i<n;i++)
        {
            if(s[i] == 'B')
            break;
        }
        for(j = n-1; j>=0; j--)
        {
            if(s[j] == 'B')
            break;
        }
        cout<<j-i+1<<"\n";
    }
}