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
ll add(ll a, ll b)
{
    return ((a % MOD) + (b % MOD)) % MOD;
}
ll mul(ll a, ll b)
{
    return ((a % MOD) * (b % MOD)) % MOD;
}
ll power(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}
ll inv(ll a, ll mod = MOD)
{
    return power(a, mod - 2);
}
void solve()
{
    ll n, sum = 0, temp = 0, q1, q2;
    cin >> n;
    vll arr(n);
    // fro(i, 0, n - 1) cin >> arr[i], sum += arr[i];
    // fro(i, 0, n - 1) sum -= arr[i], temp = (temp + (arr[i] * sum))%MOD;
    // q1 = (n * (n - 1) / 2) % MOD, q2 = power(q1, MOD - 2);
    // cout << ((temp * q2) % MOD) << '\n';
    fro(i, 0, n - 1) cin >> arr[i], sum += arr[i];
    fro(i, 0, n - 1) temp = add(temp, mul(sum - arr[i], arr[i]));
    cout << mul(temp, inv(mul(n, n - 1))) << '\n';
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