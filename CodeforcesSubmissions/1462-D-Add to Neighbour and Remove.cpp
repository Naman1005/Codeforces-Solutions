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
ll n, mx, sm;
vll arr;
bool calc(ll a)
{
    ll sum = 0;
    fro(i, 0, n - 1)
    {
        if (sum == a)
            sum = 0;
        if (sum > a)
            return false;
        else
            sum += arr[i];
    }
    return sum == a;
}
vll all_fac(ll a)
{
    vll ans;
    for (ll i = 1; i * i <= a; i++)
        if (a % i == 0)
            ans.push_back(i), ans.push_back(a / i);
    sort_and_unique(ans);
    return ans;
}
void solve()
{
    cin >> n;
    arr.resize(n);
    fro(i, 0, n - 1) cin >> arr[i];
    sm = accumulate(all(arr), 0);
    vll fac = all_fac(sm);
    for (auto x : fac)
        if (calc(x))
        {
            cout << n - (sm / x) << "\n";
            return;
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