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
    ll n;
    cin >> n;
    vector<string> vs(2);
    cin >> vs[0] >> vs[1];
    vector<vector<bool>> vis(2, vector<bool>(n));
    queue<pair<ll, ll>> q;
    q.push({0, 0});
    vis[0][0] = true;
    function<pair<ll, ll>(ll, ll)> next = [&](ll i, ll j) -> pair<ll, ll>
    { return ((vs[i][j] == '<') ? pair<ll, ll>{i, j - 1} : pair<ll, ll>{i, j + 1}); };
    function<bool(ll, ll)> valid = [&](ll i, ll j) -> bool
    { return i >= 0 && j >= 0 && i < 2 && j < n; };
    function<vector<pair<ll, ll>>(ll, ll)> nbr = [&](ll i, ll j) -> vector<pair<ll, ll>>
    {
        vector<pair<ll, ll>> res;
        if (valid(i - 1, j))
            res.push_back(next(i - 1, j));
        if (valid(i + 1, j))
            res.push_back(next(i + 1, j));
        if (valid(i, j - 1))
            res.push_back(next(i, j - 1));
        if (valid(i, j + 1))
            res.push_back(next(i, j + 1));
        return res;
    };
    while (!q.empty())
    {
        auto [i, j] = q.front();
        q.pop();
        auto nb = nbr(i, j);
        for (auto [x, y] : nb)
            if (!vis[x][y])
                vis[x][y] = true, q.push({x, y});
    }
    cout << (vis[1][n - 1] ? "YES\n" : "NO\n");
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // inp_out();
    cout << setprecision(20) << fixed;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}