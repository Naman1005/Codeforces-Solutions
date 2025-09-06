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
inline ll sm(ll a)
{
    return ((a * (a + 1)) / 2);
}
void solve()
{
    ll n, k, low, high, mid;
    cin >> n >> k;
    low = k, high = k + n - 1;
    while (low < high)
    {
        mid = (low + high + 1) / 2;
        if (sm(mid) - sm(k - 1) > sm(k + n - 1) - sm(mid))
            high = mid - 1;
        else
            low = mid;
    }
    cout << min(abs((sm(low) - sm(k - 1)) - (sm(k + n - 1) - sm(low))), abs((sm(low + 1) - sm(k - 1)) - (sm(k + n - 1) - sm(low + 1)))) << '\n';
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