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
    ll t, n, i, j;
    cin >> t;
    while (t--)
    {
        cin>>n;
        ll arr[n];
        for (ll i = 0; i < n; i++)
            cin >> arr[i];
        if (n == 1)
            cout << 0 << "\n";
        else if (n == 2)
        {
            if (arr[0] != arr[1])
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
        else
        {
            i = 0, j = n - 1;
            for (ll x = 1; x < n; x++)
            {
                if (arr[x] != arr[x - 1])
                break;
                else
                i = x;
            }
            for(ll x = n-2; x>=0; x--)
            {
                if(arr[x] != arr[x+1])
                break;
                else
                j = x;
            }
            // cout<<i<<" "<<j<<"\n";
            if(i == n-1 && j == 0)
            cout<<0<<"\n";
            else if(arr[i] == arr[j])
            cout<<j-i-1<<"\n";
            else
            {
                if(i+1 > n-j)
                cout<<n-i-1<<"\n";
                else
                cout<<j<<"\n";
            }
        }
    }
}