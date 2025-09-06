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
    vll arr(n), idx(n);
    vector<pair<ll, ll>> ans;
    fro(i, 0, n - 1) cin >> arr[i], idx[arr[i] - 1] = i, arr[i] = i;
    map<pair<ll, ll>, bool> mp;
    fro(_, 0, n - 1)
    {
        fro(i, 0, n - 2)
        {
            ll x = arr[i], y = arr[i + 1];
            if (mp[{x, y}])
                continue;
            ans.push_back({y, x});
            swap(arr[i], arr[i + 1]);
            if (idx[y] < idx[x])
                mp[{y, x}] = true;
        }
    }
    cout << ans.size() << "\n";
    for (auto x : ans)
        cout << x.first + 1 << " " << x.second + 1 << "\n";
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