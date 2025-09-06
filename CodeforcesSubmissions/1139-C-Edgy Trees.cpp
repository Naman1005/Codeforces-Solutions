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
const ll MOD = 1e9 + 7;
ll mul(ll a, ll b) { return ((a % MOD) * (b % MOD)) % MOD; }
ll add(ll a, ll b) { return ((a % MOD) + (b % MOD)) % MOD; }
ll pow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}
void solve()
{
    ll k, n, ans;
    cin >> n >> k;
    ans = pow(n, k);
    vector<vll> adj(n + 1);
    vector<bool> vis(n + 1);
    function<ll(ll)> dfs = [&](ll v) -> ll
    {
        vis[v] = true;
        ll cnt = 1;
        for (auto &u : adj[v])
            if (!vis[u])
                cnt += dfs(u);
        return cnt;
    };
    fro(i, 1, n - 1)
    {
        ll u, v, x;
        cin >> u >> v >> x;
        if (x) continue;
        adj[u].push_back(v), adj[v].push_back(u);
    }
    fro(i, 1, n) if (!vis[i]) ans -= pow(dfs(i), k), ans += MOD, ans %= MOD;
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
    // cin >> t;
    while (t--)
        solve();
}