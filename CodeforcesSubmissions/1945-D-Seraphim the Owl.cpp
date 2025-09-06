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
    ll n, m, tempSum = 0, total = 0;
    cin >> n >> m;
    vll a(n), b(n);
    fro(i, 0, n - 1) cin >> a[i];
    fro(i, 0, n - 1) cin >> b[i];
    reverse(all(a)), reverse(all(b));
    fro(i, 0, n - 1)
    {
        if (i < n - m)
            tempSum += min(a[i], b[i]), total += min(a[i], b[i]);
        else if (i == n - m)
            total += a[i], tempSum += min(a[i], b[i]);
        else
            total = min(total, tempSum + a[i]), tempSum += b[i];
    }
    cout << total << "\n";
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