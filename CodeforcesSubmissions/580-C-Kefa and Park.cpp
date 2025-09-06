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
vector<vll> adj;
vi vis, cats;
ll n, m, ans;
void DFS(ll node, ll cnt)
{
    vis[node] = 1;
    (cats[node]) ? cnt++ : cnt = 0;
    if (cnt > m)
        return;
    bool isLeaf = true;
    for (auto x : adj[node])
        if (!vis[x])
        {
            isLeaf = false;
            DFS(x, cnt);
        }
    if (isLeaf)
        ans++;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    inp_out();
    cout << setprecision(20) << fixed;
    cin >> n >> m;
    vis.resize(n, 0);
    cats.resize(n);
    fro(i, 0, n - 1) cin >> cats[i];
    adj.resize(n);
    fro(i, 0, n - 2)
    {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ans = 0;
    DFS(0, 0);
    cout << ans << "\n";
}