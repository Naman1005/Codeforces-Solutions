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
ll n, m, grid[1001][1001];
bool visited[1001][1001];
ll BFS(ll i, ll j)
{
    ll ans = 0;
    queue<pair<ll, ll>> q;
    q.push({i, j});
    visited[i][j] = true;
    while (!q.empty())
    {
        pair<ll, ll> cell = q.front();
        i = cell.first, j = cell.second;
        q.pop();
        ans += grid[i][j];
        if (i > 0 && grid[i - 1][j] && !visited[i - 1][j])
            visited[i - 1][j] = true, q.push({i - 1, j});
        if (i < n - 1 && grid[i + 1][j] && !visited[i + 1][j])
            visited[i + 1][j] = true, q.push({i + 1, j});
        if (j > 0 && grid[i][j - 1] && !visited[i][j - 1])
            visited[i][j - 1] = true, q.push({i, j - 1});
        if (j < m - 1 && grid[i][j + 1] && !visited[i][j + 1])
            visited[i][j + 1] = true, q.push({i, j + 1});
    }
    return ans;
}
void solve()
{
    ll ans = 0;
    cin >> n >> m;
    fro(i, 0, n - 1) fro(j, 0, m - 1)
    {
        cin >> grid[i][j];
        visited[i][j] = false;
    }
    fro(i, 0, n - 1) fro(j, 0, m - 1) if (!visited[i][j] && grid[i][j] != 0)
        ans = max(ans, BFS(i, j));
    cout << ans << '\n';
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