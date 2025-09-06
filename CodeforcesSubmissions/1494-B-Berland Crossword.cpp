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
bool check(ll x, ll n, ll u, ll r, ll d, ll l)
{
    bool ul = x & 1, ur = x & 2, dl = x & 4, dr = x & 8;
    u -= ul + ur, d -= dl + dr, l -= ul + dl, r -= ur + dr;
    return u >= 0 && d >= 0 && l >= 0 && r >= 0 && u <= n - 2 && d <= n - 2 && l <= n - 2 && r <= n - 2;
}
void solve()
{
    ll n, u, r, d, l;
    cin >> n >> u >> r >> d >> l;
    fro(i, 0, 15) if (check(i, n, u, r, d, l))
    {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
    return;
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