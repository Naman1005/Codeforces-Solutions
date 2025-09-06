#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pi 3.141592653589793238462643383279
#define vi vector<int>
#define vll vector<ll>
#define umllll unordered_map<ll, ll>
#define umsll unordered_map<string, ll>
#define umcll unordered_map<char, ll>
#define sortv(v) sort(v.begin(), v.end())
#define all(a) (a).begin(), (a).end()
#define sort_and_unique(a) \
    sort(all(a));          \
    (a).resize(unique(all(a)) - (a).begin())
#define fro(i, x, y) for (ll i = x; i <= y; i++)
#define pre(i, x, y) for (ll i = x; i >= y; i--)
ll fact(ll n)
{
    if (n == 0)
        return 1;
    ll res = 1;
    for (ll i = 2; i <= n; i++)
        res *= i;
    return res;
}
void inp_out()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    inp_out();
    cout << setprecision(20) << fixed;
    ll t, n, mdi, dif;
    cin >> t;
    while (t--)
    {
        dif = LONG_LONG_MAX;
        mdi = -1;
        cin >> n;
        ll arr[n];
        for (ll i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr, arr + n);
        if (n == 1 || n == 2)
        {
            for (ll i = 0; i < n; i++)
                cout << arr[i] << " ";
            cout << "\n";
            continue;
        }
        for (ll i = 0; i < n - 1; i++)
        {
            if (arr[i + 1] - arr[i] <= dif)
            {
                dif = arr[i + 1] - arr[i];
                mdi = i + 1;
            }
        }
        for (ll i = mdi; i < n; i++)
            cout << arr[i] << " ";
        for (ll i = 0; i < mdi; i++)
            cout << arr[i] << " ";
         // for (ll i = 0; i < n; i++)
        //     cout << arr[i] << " ";
        // cout << "   "<<mdi<<" ";
        cout << "\n";
    }
}