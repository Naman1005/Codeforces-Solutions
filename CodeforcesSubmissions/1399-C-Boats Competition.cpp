#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pi 3.141592653589793238462643383279
#define vi vector<int>
#define vll vector<ll>
#define um unordered_map
#define all(a) (a).begin(), (a).end()
#define sort_and_unique(a) \
    sort(all(a));          \
    (a).resize(unique(all(a)) - (a).begin())
#define fro(i, x, y) for (ll i = x; i <= y; i++)
#define pre(i, x, y) for (ll i = x; i >= y; i--)
#define fact(n) (ll) tgamma(n + 1)
#define truncMod(a, b) (ll)(a - (b * (floor(a / b))))
void inp_out()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
vll arr;
ll calc(ll a, um<ll, ll> mp)
{
    ll cnt = 0, x;
    for (auto i : arr)
        if (mp[i] && mp[a - i])
        {
            if (2 * i == a)
                mp[i] >>= 1;
            x = min(mp[i], mp[a - i]), cnt += x, mp[i] -= x, mp[a - i] -= x;
        }
    return cnt;
}
void solve()
{
    ll n, x, res = -1, mx = -1;
    cin >> n;
    um<ll, ll> mp;
    fro(i, 0, n - 1)
    {
        cin >> x;
        if (!mp[x])
            arr.push_back(x);
        mp[x]++, mx = max(mx, x);
    }
    fro(i, 2, 2 * mx) res = max(res, calc(i, mp));
    cout << res << "\n";
    arr.clear();
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    inp_out();
    cout << setprecision(20) << fixed;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}