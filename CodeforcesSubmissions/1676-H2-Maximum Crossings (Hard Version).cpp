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
class BIT
{
private:
    vll bit;
    ll n;
 public:
    BIT(ll size) : n(size) { bit.assign(n + 1, 0); }
    void update(ll i, ll val) { while (i <= n) bit[i] += val, i += (i & -i); }
    ll query(ll i)
    {
        ll sum = 0;
        while (i > 0)
            sum += bit[i], i -= (i & -i);
        return sum;
    }
    ll get(ll l, ll r) { return query(r) - query(l - 1); }
};
void solve()
{
    ll n, ans = 0;
    cin >> n;
    vll arr(n);
    fro(i, 0, n - 1) cin >> arr[i];
    BIT bit(n);
    fro(i, 0, n - 1)
    {
        ans += bit.get(arr[i], n);
        bit.update(arr[i], 1);
    }
    cout << ans << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // inp_out();
    cout << setprecision(20) << fixed;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}