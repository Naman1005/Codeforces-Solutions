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
    ll n, temp;
    cin >> n;
    vll u(n), ans(n, 0);
    map<ll, vll> mp;
    fro(i, 0, n - 1) cin >> u[i];
    fro(i, 0, n - 1)
    {
        cin >> temp;
        mp[u[i]].push_back(temp);
    }
    for (auto &x : mp)
        sort(all(x.second), greater<ll>());
    for (auto &x : mp)
        if (x.second.size() > 1)
            fro(i, 1, x.second.size() - 1) x.second[i] += x.second[i - 1];
    for (auto &x : mp)
        pre(i, x.second.size() / 2, 0) x.second[i] = x.second[(x.second.size() / (i + 1)) * (i + 1) - 1];
    for (auto x : mp)
        fro(i, 0, x.second.size() - 1) ans[i] += x.second[i];
    fro(i, 0, n - 1) cout << ans[i] << " \n"[i == n - 1];
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