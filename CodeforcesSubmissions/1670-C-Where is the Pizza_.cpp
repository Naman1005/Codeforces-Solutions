#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pi 3.14159265358979323846
#define vi vector<int>
#define vll vector<ll>
#define um unordered_map
#define all(a) (a).begin(), (a).end()
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
 ll MOD = 1e9 + 7;
void solve()
{
    ll n, x, ans = 1;
    cin >> n;
    vll a(n), nxt(n + 1);
    vector<bool> d(n + 1), vis(n + 1);
    fro(i, 0, n - 1) cin >> a[i];
    fro(i, 0, n - 1) cin >> x, nxt[a[i]] = x, vis[a[i]] = a[i] == x;
    fro(i, 0, n - 1) cin >> x, d[x] = true;
     function<bool(ll)> fix = [&](ll v) -> bool
    {
        bool f = false;
        while (!vis[v])
        {
            if (d[v])
                f = true;
            vis[v] = true;
            v = nxt[v];
        }
        return f;
    };
     fro(i, 1, n) if (!vis[i]) ans = (ans * (fix(i) ? 1 : 2)) % MOD;
    cout << ans << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // inp_out();
    cout << setprecision(20) << fixed;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}