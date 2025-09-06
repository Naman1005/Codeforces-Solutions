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
const ll MOD = 1e9 + 7;
void solve()
{
    ll n, cnt = 0, mn = LONG_LONG_MAX, fac = 1;
    cin >> n;
    vll arr(n);
    fro(i, 0, n - 1)
    {
        cin >> arr[i];
        mn = min(mn, arr[i]);
    }
    fro(i, 0, n - 1)
    {
        if (mn == arr[i])
            cnt++;
        if ((arr[i] & mn) != mn)
        {
            cout << "0\n";
            return;
        }
    }
    fro(i, 2, n - 2) fac = (fac * i) % MOD;
    cout << (((cnt * (cnt - 1)) % MOD) * fac) % MOD << "\n";
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