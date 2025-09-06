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
    ll n, k, mx = -1;
    cin >> n >> k;
    vll v(n);
    pair<ll, ll> curr = {-1, -1}, mxp = {-1, -1};
    fro(i, 0, n - 1) cin >> v[i];
    sortv(v);
    map<ll, ll> mp;
    fro(i, 0, n - 1)
    {
        mp[v[i]]++;
        if (mp[v[i]] == k)
        {
            curr.second = v[i];
            if (mp[v[i] - 1] < k)
                curr.first = v[i];
            if (curr.second - curr.first > mx)
                mx = curr.second - curr.first, mxp = curr;
        }
    }
    if (mx == -1)
    {
        cout << "-1\n";
        return;
    }
    cout << mxp.first << " " << mxp.second << "\n";
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