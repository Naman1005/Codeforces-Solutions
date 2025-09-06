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
    ll n, q, l, r, idx, idy, ans;
    string x, y;
    cin >> n >> q;
    vector<string> cit(n + 1), type = {"BG", "BR", "BY", "GR", "GY", "RY"};
    map<string, vll> mp;
    fro(i, 1, n)
    {
        cin >> cit[i];
        for (auto k : type)
            if (k != cit[i] && (k[0] == cit[i][0] || k[0] == cit[i][1] || k[1] == cit[i][0] || k[1] == cit[i][1]))
                mp[k].push_back(i);
    }
    for (auto &k : mp)
        sort(all(k.second));
    while (q--)
    {
        cin >> l >> r;
        if (l > r)
            swap(l, r);
        x = cit[l], y = cit[r];
        if (x[0] == y[0] || x[0] == y[1] || x[1] == y[0] || x[1] == y[1])
        {
            cout << r - l << "\n";
            continue;
        }
        ans = -1;
        if (mp[x].size())
        {
            idx = upper_bound(all(mp[x]), l) - mp[x].begin();
            if (idx == mp[x].size())
                idx--;
            ans = min(ans == -1 ? LONG_LONG_MAX : ans, abs(mp[x][idx] - l) + abs(mp[x][idx] - r));
            idx--;
            if (idx < 0)
                idx++;
            ans = min(ans == -1 ? LONG_LONG_MAX : ans, abs(mp[x][idx] - l) + abs(mp[x][idx] - r));
        }
        if (mp[y].size())
        {
            idy = upper_bound(all(mp[y]), r) - mp[y].begin();
            if (idy == mp[y].size())
                idy--;
            ans = min(ans == -1 ? LONG_LONG_MAX : ans, abs(mp[y][idy] - l) + abs(mp[y][idy] - r));
            idy--;
            if (idy < 0)
                idy++;
            ans = min(ans == -1 ? LONG_LONG_MAX : ans, abs(mp[y][idy] - l) + abs(mp[y][idy] - r));
        }
        cout << ans << "\n";
    }
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