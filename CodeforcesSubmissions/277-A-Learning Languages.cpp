#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    inp_out();
    cout << setprecision(20) << fixed;
    ll n, m, k, x, ans = 0;
    bool f = false;
    cin >> n >> m;
    vector<bool> vis(n, false);
    vector<vll> v(m), graph(n);
    fro(i, 1, n)
    {
        cin >> k;
        f |= k;
        fro(j, 1, k)
        {
            cin >> x;
            v[x - 1].push_back(i - 1);
        }
    }
    fro(i, 0, m - 1) if (v[i].size() > 1) fro(j, 1, v[i].size() - 1) graph[v[i][j]].push_back(v[i][j - 1]), graph[v[i][j - 1]].push_back(v[i][j]);
    // for(auto x : graph) {
    //     for(auto y : x) cout << y << " ";
    //     cout << "\n";
    // }
    fro(i, 0, n - 1) if (!vis[i])
    {
        queue<ll> q;
        q.push(i);
        vis[i] = true;
        while (!q.empty())
        {
            ll u = q.front();
            q.pop();
            for (auto v : graph[u])
                if (!vis[v])
                    vis[v] = true, q.push(v);
        }
        ans++;
    }
    // cout << ans << "\n";
    cout << ans - (ans != n || f) << "\n";
}