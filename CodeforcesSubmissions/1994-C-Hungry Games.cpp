#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
 ll n, x, ans, val, in;
void solve()
{
    ans = 0;
    cin >> n >> x;
    vll arr(n), pref(n + 1, 0), brr(n + 3);
    fro(i, 0, n - 1)
    {
        cin >> arr[i];
        pref[i + 1] = pref[i] + arr[i];
    }
    pre(i, n - 1, 0)
        in = lower_bound(all(pref), pref[i] + x) - pref.begin(),
        (in == n + 1) ? brr[i] += (n - i) : ((pref[i] + x == pref[in]) ? brr[i] += (in - i) + brr[in + 1] : brr[i] += (in - i - 1) + brr[in]);
    fro(i, 0, n + 2)
        ans += brr[i];
    cout << ans << endl;
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