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
    double W, H, w, h, ver, hor, ans;
    pair<double, double> p1, p2;
    cin >> W >> H >> p1.first >> p1.second >> p2.first >> p2.second >> w >> h;
    ver = p1.second - p2.second + H, hor = p1.first - p2.first + W;
    if (ver < h && hor < w)
        cout << "-1\n";
    else
    {
        if (ver >= h && hor >= w)
            ans = min({max(0.0, h - p1.second), max(0.0, p2.second + h - H), max(0.0, w - p1.first), max(0.0, p2.first + w - W)});
        else if (ver >= h)
            ans = min(max(0.0, h - p1.second), max(0.0, p2.second + h - H));
        else
            ans = min(max(0.0, w - p1.first), max(0.0, p2.first + w - W));
        cout << ans << "\n";
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