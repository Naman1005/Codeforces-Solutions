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
    ll a, b, q, l, r, lcm, x1, y1, x2, y2;
    cin >> a >> b >> q;
    lcm = (a * b) / __gcd(a, b);
    while (q--)
    {
        cin >> l >> r;
        x1 = lcm * (l / lcm) + max(a, b), y1 = lcm * (l / lcm + 1) - 1, x2 = lcm * (r / lcm) + max(a, b), y2 = lcm * (r / lcm + 1) - 1;
        cout << (x1 == x2 ? (max(r - max(l, x1) + 1, 0LL)) : (y1 - max(x1, l) + 1 + max(0LL, r - x2 + 1) + (((y2 - y1) / lcm) - 1) * (lcm - max(a, b)))) << " ";
    }
    cout << "\n";
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