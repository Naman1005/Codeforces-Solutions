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
void solve()
{
    ll n, k, q, l, r, mn = LONG_LONG_MAX, mx = LONG_LONG_MIN;
    cin >> n >> k >> q;
    vll v(2e5 + 1, 0);
    fro(i, 1, n)
    {
        cin >> l >> r;
        mn = min(mn, l), mx = max(mx, r);
        v[l]++, v[r + 1]--;
    }
    fro(i, 1, 2e5) v[i] += v[i - 1];
    fro(i, 1, 2e5) v[i] = (v[i] >= k) + v[i - 1];
    while (q--)
    {
        cin >> l >> r;
        cout << v[r] - v[l - 1] << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    inp_out();
    cout << setprecision(20) << fixed;
    ll t = 1;
    // cin>>t;
    while (t--)
        solve();
}