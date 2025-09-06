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
void solve()
{
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    inp_out();
    cout << setprecision(20) << fixed;
    ll n, m;
    cin >> n >> m;
    vector<vll> group(m), graph(n), islands;
    vector<bool> vis(n, false);
    vll ans(n);
    fro(i, 0, m - 1)
    {
        ll x, y;
        cin >> x;
        fro(j, 0, x - 1)
        {
            cin >> y;
            group[i].push_back(y - 1);
        }
    }
    fro(i, 0, m - 1) if (group[i].size() > 1) fro(j, 0, group[i].size() - 2) graph[group[i][j]].push_back(group[i][j + 1]), graph[group[i][j + 1]].push_back(group[i][j]);
    fro(i, 0, n - 1)
    {
        if (!vis[i])
        {
            vll island;
            queue<ll> q;
            q.push(i);
            island.push_back(i);
            vis[i] = true;
            while (!q.empty())
            {
                ll u = q.front();
                q.pop();
                for (auto &v : graph[u])
                    if (!vis[v])
                        vis[v] = true, island.push_back(v), q.push(v);
            }
            islands.push_back(island);
        }
    }
    fro(i, 0, islands.size() - 1) fro(j, 0, islands[i].size() - 1) ans[islands[i][j]] = islands[i].size();
    fro(i, 0, n - 1) cout << ans[i] << " ";
}