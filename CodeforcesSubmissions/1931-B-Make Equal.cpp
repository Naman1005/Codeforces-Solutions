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
void solve(ll arr[], ll n, double target)
{
    for (ll i = n - 1; i > 0; i--)
    {
        if (arr[i] > (ll)target)
        {
            cout << "NO\n";
            return;
        }
        else if (arr[i] < (ll)target)
        {
            arr[i - 1] -= ((ll)target - arr[i]);
            arr[i] = (ll)target;
        }
    }
    if (arr[0] != (ll)target)
        cout << "NO\n";
    else
        cout << "YES\n";
}
int main()
{
    inp_out();
    ll t, n, sum;
    double target;
    cin >> t;
    while (t--)
    {
        sum = 0;
        cin >> n;
        ll arr[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }
        target = sum / (double)n;
        if (ceil(target) != floor(target))
            cout << "NO\n";
        else
        {
            solve(arr, n, target);
        }
    }
}