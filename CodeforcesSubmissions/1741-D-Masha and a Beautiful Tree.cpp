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
    ll m, ans = 0, n;
    cin >> m;
    n = log2(m);
    vll arr(m);
    fro(i, 0, m - 1) cin >> arr[i];
    fro(_, 0, n - 1)
    {
        ll x = 1 << _, i = 0;
        while (i < m)
        {
            if (arr[i] > arr[i + x])
            {
                ans++;
                fro(s, 0, x - 1) swap(arr[i + s], arr[i + x + s]);
            }
            i += 2 * x;
        }
    }
    if (is_sorted(all(arr)))
        cout << ans << "\n";
    else
        cout << -1 << "\n";
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