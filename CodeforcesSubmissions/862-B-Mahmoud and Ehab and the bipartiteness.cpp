#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pi 3.141592653589793238462643383279
#define vi vector<int>
#define vll vector<ll>
#define um unordered_map
#define all(a) (a).begin(), (a).end()
#define sortv(v) sort(all(v))
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
ll ans, u, v, n, N = 1e5;
vector<vll> adj(N);
vector<bool> visited(N);
ll bfs(ll node)
{
    queue<ll> q;
    q.push(node);
    visited[node] = true;
    ll group[n], cnt = 1;
    group[node] = 1;
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        for (auto &v : adj[u])
        {
            if (!visited[v])
            {
                group[v] = group[u] * (-1);
                if (group[v] == 1)
                    cnt++;
                visited[v] = true;
                q.push(v);
            }
        }
    }
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    inp_out();
    cout << setprecision(20) << fixed;
    cin >> n;
    fro(i, 0, n - 2)
    {
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        visited[i] = false;
    }
    visited[n - 1] = false;
    ans = bfs(0);
    cout << (ans * (n - ans)) - n + 1 << "\n";
}