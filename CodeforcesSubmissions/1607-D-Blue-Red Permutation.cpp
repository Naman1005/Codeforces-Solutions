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
void print_vec(vll v)
{
    fro(i, 0, v.size() - 1)
            cout
        << v[i] << " ";
    cout << "\n";
}
void solve()
{
    ll n, cnt;
    cin >> n;
    vll arr(n);
    fro(i, 0, n - 1) cin >> arr[i];
    map<char, vll> mp;
    fro(i, 0, n - 1)
    {
        char c;
        cin >> c;
        mp[c].push_back(arr[i]);
    }
    for (auto &k : mp)
        sortv(k.second);
    cnt = 1;
    for (auto k : mp['B'])
        if (k < cnt++)
        {
            cout << "NO\n";
            return;
        }
    for (auto k : mp['R'])
        if (k > cnt++)
        {
            cout << "NO\n";
            return;
        }
    cout << "YES\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    inp_out();
    cout << setprecision(20) << fixed;
    ll t;
    cin >> t;
    while (t--)
        solve();
}