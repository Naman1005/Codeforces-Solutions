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
ll BFS1(ll node1, vll adj[], vector<bool> vis, vector<bool> marked)
{
    queue<ll> q;
    q.push(node1);
    vis[node1] = true;
    ll node2 = node1;
    while (!q.empty())
    {
        ll s = q.front();
        q.pop();
        if (marked[s])
            node2 = s;
        for (auto x : adj[s])
            if (!vis[x])
            {
                vis[x] = true;
                q.push(x);
            }
    }
    return node2;
}
ll BFS2(ll node, vll adj[], vector<bool> vis, vector<bool> marked, ll n)
{
    queue<ll> q;
    q.push(node);
    vis[node] = true;
    vll distance(n, 0);
    distance[node] = 0;
    ll max_distance = 0;
    while (!q.empty())
    {
        ll s = q.front();
        q.pop();
        for( auto x: adj[s])
        {
            if (!vis[x])
            {
                vis[x] = true;
                distance[x] = distance[s] + 1;
                if(marked[x])
                max_distance = max(max_distance, distance[x]);
                q.push(x);
            }
        }
    }
    return max_distance;
}
void solve()
{
    ll n, k, x, y, ans;
    cin >> n >> k;
    vector<bool> marked(n, false), visited(n, false);
    fro(i, 0, k - 1)
    {
        cin >> x;
        marked[x - 1] = true;
    }
    vll adj[n];
    fro(i, 0, n - 2)
    {
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    if (k == 1)
    {
        cout << "0\n";
        return;
    }
    fro(i, 0, n - 1) if (marked[i])
    {
        ans = BFS1(i, adj, visited, marked);
        break;
    }
    ans = BFS2(ans, adj, visited, marked, n);
    cout << (ll)ceil(ans/2.0) << "\n";
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