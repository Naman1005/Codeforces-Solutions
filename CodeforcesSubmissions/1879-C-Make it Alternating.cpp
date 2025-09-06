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
const int N = 998244353;
void solve()
{
    string s;
    cin >> s;
    ll n = s.size(), ans = 1, one = 0, zero = 0, cnt = 0;
    s[0] == '1' ? one++ : zero++;
    fro(i, 1, n - 1)
    {
        if (s[i] == '1')
        {
            if (zero)
                ans = (ans * zero) % N, cnt++, zero = 0;
            one++;
        }
        else
        {
            if (one)
                ans = (ans * one) % N, cnt++, one = 0;
            zero++;
        }
    }
    if (zero)
        ans = (ans * zero) % N, cnt++;
    if (one)
        ans = (ans * one) % N, cnt++;
    fro(i, 1, n-cnt) ans = (ans * i) % N;
    cout << n - cnt << " " << ans << "\n";
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