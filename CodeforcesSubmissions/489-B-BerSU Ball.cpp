#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n;
    int boy[n];
    for(int i=0; i<n; i++)
    cin>>boy[i];
    sort(boy,boy+n);
    cin>>m;
    int girl[m];
    for(int i=0; i<m; i++)
    cin>>girl[i];
    sort(girl,girl+m);
    int b = 0, g = 0, count = 0;
    while(b<n && g<m)
    {
        if(abs(boy[b]-girl[g]) <= 1)
        {
            count++;
            b++;
            g++;
        }
        else if(boy[b] > girl[g])
        g++;
        else if(girl[g] > boy[b])
        b++;
    }
    cout<<count<<"\n";
}