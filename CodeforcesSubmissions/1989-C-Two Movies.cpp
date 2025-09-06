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
    ll n, cnt_a, cnt_b, pos, neg, ans = LONG_LONG_MIN;
    cin >> n;
    cnt_a = cnt_b = pos = neg = 0;
    vll a(n), b(n);
    fro(i, 0, n - 1) cin >> a[i];
    fro(i, 0, n - 1)
    {
        cin >> b[i];
        if (a[i] > b[i])
            cnt_a += a[i];
        else if (a[i] < b[i])
            cnt_b += b[i];
        else if (a[i] < 0)
            neg++;
        else if (a[i] > 0)
            pos++;
    }
    fro(i, -neg, pos) ans = max(ans, min(cnt_a + i, cnt_b + pos - neg - i));
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