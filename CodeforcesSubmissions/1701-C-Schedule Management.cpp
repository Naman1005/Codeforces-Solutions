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
ll n, m, x, low, high, ans, mid;
vll v;
bool check(ll a)
{
    ll x = 0, y = 0;
    fro(i, 0, n - 1)(v[i] > a) ? x += v[i] - a : y += (a - v[i]) / 2;
    return x <= y;
}
void solve()
{
    cin >> n >> m;
    low = 0, high = 2 * m, ans = -1;
    v.clear(), v.resize(n, 0);
    fro(i, 0, m - 1)
    {
        cin >> x;
        v[x - 1]++;
    }
    while (low <= high)
        mid = (low + high) / 2, (check(mid)) ? ans = mid, high = mid - 1 : low = mid + 1;
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