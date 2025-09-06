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
#define fro(i, x, y) for (ll i = (ll)(x); i <= (ll)(y); i++)
#define pre(i, x, y) for (ll i = (ll)(x); i >= (ll)(y); i--)
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
    ll n, q, l, r, ans;
    cin >> n >> q;
    vector<ll> a(2 * n), pref(2 * n + 1, 0);
    fro(i, 0, n - 1)
    {
        cin >> a[i];
        a[i + n] = a[i];
    }
    fro(i, 1, n * 2) pref[i] = a[i - 1] + pref[i - 1];
    while (q--)
    {
        cin >> l >> r;
        l--, r--;
        cout << (pref[n] * ((r / n) - (l / n) - 1) + pref[(l / n) + n] - pref[(l / n) + l % n] + pref[(r / n) + r % n + 1] - pref[(r / n)]) << '\n';
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
    cin >> t;
    while (t--)
        solve();
}