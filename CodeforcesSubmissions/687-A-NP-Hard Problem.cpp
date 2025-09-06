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
    ll n, m;
    cin >> n >> m;
    vector<vll> adj(n + 1);
    string col(n + 1, '.');
    fro(i, 0, m - 1)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
     fro(i, 1, n) if (adj[i].size() && col[i] == '.')
    {
        queue<ll> q;
        q.push(i);
        col[i] = 'R';
        while (!q.empty())
        {
            ll u = q.front();
            q.pop();
            for (ll v : adj[u])
            {
                if (col[v] == col[u])
                {
                    cout << "-1\n";
                    return;
                }
                if (col[v] == '.')
                    col[v] = (col[u] == 'R') ? 'B' : 'R', q.push(v);
            }
        }
    }
    vll u, v;
    fro(i, 1, n)
    {
        if (col[i] == 'B')
            u.push_back(i);
        else if (col[i] == 'R')
            v.push_back(i);
    }
    cout << u.size() << "\n";
    for (ll x : u)
        cout << x << " ";
    cout << "\n";
    cout << v.size() << "\n";
    for (ll x : v)
        cout << x << " ";
    cout << "\n";
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