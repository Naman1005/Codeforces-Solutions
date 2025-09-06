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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    inp_out();
    cout << setprecision(20) << fixed;
     ll n, m, ans = 0;
    cin >> n >> m;
    vector<ll> cost(n);
    for (auto &it : cost)
        cin >> it;
    vector<vector<ll>> adj(n);
    fro(i, 1, m)
    {
        ll u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    vector<bool> vis(n, false);
    function<ll(ll, ll &)> dfs;
    dfs = [&](ll val, ll &mn)
    {
        vis[val] = true;
        mn = min(mn, cost[val]);
        for (auto &v : adj[val])
            if (!vis[v])
                dfs(v, mn);
        return mn;
    };
    fro(i, 0, n - 1) if (!vis[i])
    {
        ll mn = LONG_LONG_MAX, temp = dfs(i, mn);
        if (temp != LONG_LONG_MAX)
            ans += temp;
    }
    cout << ans << endl;
    return 0;
}