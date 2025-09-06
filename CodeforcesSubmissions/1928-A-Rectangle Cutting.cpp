#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void inp_out()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int main()
{
    inp_out();
    ll t, a, b;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        if(a>b)
        swap(a,b);
        if ((a & 1) && (b & 1))
        {
            cout << "No\n";
            continue;
        }
        else if(a&1)
        {
            if((b/2 == a) && (2*a == b))
            cout<<"No\n";
            else
            cout<<"Yes\n";
        }
        else if(b&1)
        {
            if((a/2 == b) && (2*b == a))
            cout<<"No\n";
            else
            cout<<"Yes\n";
        }
        else
        cout<<"Yes\n";
    }
}