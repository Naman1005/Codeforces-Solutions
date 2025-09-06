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
void solve()
{
    ll n, temp, cnt = 0, cycle = 0, linear = 0;
    cin >> n;
    vll sz(n);
    vector<set<ll>> adj(n);
    bool c;
    vector<bool> visited(n, false);
    fro(i, 0, n - 1)
    {
        cin >> temp;
        temp--;
        adj[i].insert(temp);
        adj[temp].insert(i);
    }
    fro(i, 0, n - 1) sz[i] = adj[i].size();
    fro(i, 0, n - 1) if (!visited[i])
    {
        queue<ll> q;
        q.push(i);
        visited[i] = true;
        vll comp = {i};
        while (!q.empty())
        {
            ll u = q.front();
            q.pop();
            for (ll v : adj[u])
                if (!visited[v])
                {
                    visited[v] = true;
                    q.push(v);
                    comp.push_back(v);
                }
        }
        c = true;
        for (auto k : comp)
            if (sz[k] == 1)
            {
                c = false;
                break;
            }
        c ? cycle++ : linear++;
    }
    cout << cycle + min(linear, 1LL) << ' ' << cycle + linear << '\n';
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