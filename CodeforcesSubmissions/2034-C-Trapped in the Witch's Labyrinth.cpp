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
    ll n, m, ans = 0;
    cin >> n >> m;
    vector<string> mat(n + 2, string(m + 2, '.'));
    vector<vector<bool>> vis(n + 2, vector<bool>(m + 2, false));
    fro(i, 1, n) fro(j, 1, m) cin >> mat[i][j];
    queue<pair<ll, ll>> q;
    fro(i, 1, n) vis[i][m + 1] = vis[i][0] = true, q.push({i, 0}), q.push({i, m + 1});
    fro(j, 1, m) vis[n + 1][j] = vis[0][j] = true, q.push({0, j}), q.push({n + 1, j});
     auto check = [&](int i, int j, int row, int col) -> bool
    {
        if (i < 1 || j < 1 || i > n || j > m)
            return false;
        if ((mat[i][j] == 'U' && row == i - 1 && col == j) ||
            (mat[i][j] == 'D' && row == i + 1 && col == j) ||
            (mat[i][j] == 'L' && row == i && col == j - 1) ||
            (mat[i][j] == 'R' && row == i && col == j + 1))
            return true;
        return false;
    };
     auto next = [&](int i, int j) -> vector<pair<ll, ll>>
    {
        vector<pair<ll, ll>> vec;
        if (check(i - 1, j, i, j))
            vec.push_back({i - 1, j});
        if (check(i + 1, j, i, j))
            vec.push_back({i + 1, j});
        if (check(i, j - 1, i, j))
            vec.push_back({i, j - 1});
        if (check(i, j + 1, i, j))
            vec.push_back({i, j + 1});
        return vec;
    };
     while (!q.empty())
    {
        auto [i, j] = q.front();
        q.pop();
        auto vec = next(i, j);
        for (auto [x, y] : vec)
            if (!vis[x][y])
                vis[x][y] = true, q.push({x, y});
    }
    fro(i, 1, n) fro(j, 1, m)(mat[i][j] == '?')
        ? ans += !(vis[i - 1][j] && vis[i + 1][j] && vis[i][j - 1] && vis[i][j + 1])
        : ans += !vis[i][j];
    cout << ans << "\n";
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