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
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<vll> a(n, vll(m)), b(n, vll(m));
    fro(i, 0, n - 1) fro(j, 0, m - 1)
    {
        cin >> a[i][j];
        b[i == n - 1 ? 0 : i + 1][j == m - 1 ? 0 : j + 1] = a[i][j];
    }
    if (n == m && n == 1)
    {
        cout << "-1\n";
        return;
    }
    fro(i, 0, n - 1)
    {
        fro(j, 0, m - 1) cout << b[i][j] << " ";
        cout << "\n";
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