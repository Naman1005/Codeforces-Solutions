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
    ll t, n, temp;
    cin >> t;
    while (t--)
    {
        cin >> n;
        ll arr[n];
        cin >> arr[0];
        for (ll i = 1; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] <= arr[i - 1])
            {
                temp = arr[i-1]/arr[i];
                arr[i] *= (temp+1);
            }
        }
        cout<<arr[n-1]<<"\n";
    }
}