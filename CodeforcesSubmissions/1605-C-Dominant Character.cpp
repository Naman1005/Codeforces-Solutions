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
    ll n, ans = 1e18, a, b, c;
    string s;
    cin >> n >> s;
    fro(i, 0, n - 1) if (s[i] == 'a')
    {
        a = 1, b = c = 0;
        fro(j, i + 1, min(n - 1, i + 6))
        {
            a += (s[j] == 'a'), b += (s[j] == 'b'), c += (s[j] == 'c');
            if (a > b && a > c)
                ans = min(ans, j - i + 1);
        }
    }
    cout << (ans == 1e18 ? -1 : ans) << '\n';
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