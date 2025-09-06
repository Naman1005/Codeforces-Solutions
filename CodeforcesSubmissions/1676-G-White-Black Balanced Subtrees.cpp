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
void solve()
{
    ll n, x, ans = 0;
    cin >> n;
    vector<vll> tree(n + 1);
    fro(i, 2, n)
    {
        cin >> x;
        tree[x].push_back(i);
    }
    string color;
    cin >> color;
    function<pair<ll, ll>(ll)> dfs = [&](ll v) -> pair<ll, ll>
    {
        pair<ll, ll> p = {0, 0};
        for (auto u : tree[v])
        {
            auto temp = dfs(u);
            p.first += temp.first, p.second += temp.second;
        }
        (color[v - 1] == 'B') ? p.first++ : p.second++;
        if (p.first == p.second && p.first)
            ans++;
        return p;
    };
    dfs(1);
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