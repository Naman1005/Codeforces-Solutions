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
ll sum_of_digits(ll n)
{
    ll sum = 0;
    while (n)
        sum += n % 10, n /= 10;
    return sum;
}
void solve()
{
    ll n, s, cnt = 1, ans = 0;
    cin >> n >> s;
    while (true)
    {
        // cout << n << "\n";
        if (sum_of_digits(n) <= s)
        {
            cout << ans << "\n";
            return;
        }
        ll dig = (n / cnt) % 10;
        ll inc = ((10 - dig) % 10) * cnt;
        // cout << dig << "***" << inc << "\n";
        ans += inc;
        n += inc;
        cnt *= 10;
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