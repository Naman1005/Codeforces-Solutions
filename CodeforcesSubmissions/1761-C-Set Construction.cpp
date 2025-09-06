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
    ll n;
    cin >> n;
    vector<set<ll>> vs(n + 1);
    vector<vll> adj(n + 1);
    vector<bool> vis(n + 1, false);
    fro(i, 1, n) vs[i].insert(i);
    fro(i, 1, n) fro(j, 1, n)
    {
        char c;
        cin >> c;
        if (c == '1')
            adj[j].push_back(i);
    }
    function<set<ll>(ll)> dfs = [&](ll v) -> set<ll>
    {
        if (vis[v])
            return vs[v];
        vis[v] = true;
        for (auto u : adj[v])
        {
            set<ll> temp = dfs(u);
            vs[v].insert(temp.begin(), temp.end());
        }
        return vs[v];
    };
    fro(i, 1, n) if (!vis[i]) dfs(i);
    fro(i, 1, n)
    {
        cout << vs[i].size() << " ";
        for (auto x : vs[i])
            cout << x << " ";
        cout << "\n";
    }
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