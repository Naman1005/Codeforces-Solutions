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
    ll n, leaf, next, cnt = 1;
    bool flag = false;
    cin >> n;
    vll ans(n);
    vector<vll> tree(n + 1);
    vector<bool> vis(n + 1, false);
    map<pair<ll, ll>, ll> mp;
    fro(i, 1, n - 1)
    {
        ll u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
        if (tree[u].size() > 2 || tree[v].size() > 2)
            flag = true;
        mp[{u, v}] = i;
    }
    if (flag)
    {
        cout << "-1\n";
        return;
    }
    fro(i, 1, n) if (tree[i].size() == 1) leaf = i;
    while (true)
    {
        vis[leaf] = true;
        for (auto x : tree[leaf])
            if (!vis[x])
                next = x;
        if (leaf == next)
            break;
        ans[mp[{leaf, next}] + mp[{next, leaf}]] = cnt == 1 ? 2 : 5;
        cnt *= -1, leaf = next;
    }
    fro(i, 1, n - 1) cout << ans[i] << " \n"[i==n-1];
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