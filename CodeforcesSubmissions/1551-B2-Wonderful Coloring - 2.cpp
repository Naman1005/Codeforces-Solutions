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
    ll n, k, temp, cnt = 0;
    cin >> n >> k;
    vll ans(n, 0);
    map<ll, vll> mp;
    fro(i, 0, n - 1)
    {
        cin >> temp;
        if (mp[temp].size() == k) continue;
        mp[temp].push_back(i);
    }
    for (auto &x : mp) cnt += x.second.size();
    temp = 0, cnt -= cnt % k;
    for (auto x : mp) if (cnt)
        for (auto y : x.second)
        {
            ans[y] = ++temp, temp %= k, cnt--;
            if (!cnt) break;
        }
    for (auto &x : ans) cout << x << " ";
    cout << "\n";
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