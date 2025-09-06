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
ll solve(ll x, ll y, ll z, ll k)
{
     ll mv = 0;
    fro(x_in, 1, x) fro(y_in, 1, y) if (k % (x_in * y_in) == 0 && (k / (x_in * y_in)) <= z)
        mv = max(mv, (x - x_in + 1) * (y - y_in + 1) * (z - (k / (x_in * y_in)) + 1));
    return mv;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    inp_out();
    cout << setprecision(20) << fixed;
    ll t, x, y, z, k, a, b, c, ans;
    cin >> t;
    while (t--)
    {
        cin >> x >> y >> z >> k;
        cout << solve(x, y, z, k) << "\n";
    }
}