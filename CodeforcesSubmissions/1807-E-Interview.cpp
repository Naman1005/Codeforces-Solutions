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
ll ask(ll n, ll l, ll r)
{
    cout << "? " << n << " ";
    fro(i, l, r) cout << i + 1 << " ";
    cout << '\n';
    ll ans;
    cin >> ans;
    return ans;
}
void solve()
{
    ll n;
    cin >> n;
    vll arr(n), pref(n);
    cin >> arr[0];
    pref[0] = arr[0];
    fro(i, 1, n - 1) cin >> arr[i], pref[i] = pref[i - 1] + arr[i];
    function<ll(ll, ll)> sum = [&](ll l, ll r)
    { return pref[r] - (l > 0 ? pref[l - 1] : 0); };
    ll l = 0, r = n - 1, mid, val;
    while (l < r)
    {
        mid = (l + r) >> 1, val = ask(mid - l + 1, l, mid);
        (val != sum(l, mid)) ? r = mid : l = mid + 1;
    }
    cout << "! " << l + 1 << '\n';
}
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    // inp_out();
    cout << setprecision(20) << fixed;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}