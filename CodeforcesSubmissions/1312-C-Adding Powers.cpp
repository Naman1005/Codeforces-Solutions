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
map<ll, bool> mp;
bool add(ll a, ll k)
{
    ll p = 0;
    while (a > 0)
    {
        if (a % k > 1)
            return false;
        if (a % k == 1)
        {
            if (mp[p])
                return false;
            mp[p] = true;
        }
        a /= k, p++;
    }
    return true;
}
void solve()
{
    ll n, k;
    cin >> n >> k;
    vll arr(n);
    bool flag = true;
    for (auto &x : arr)
    {
        cin >> x;
        flag &= add(x, k);
    }
    cout << (flag ? "YES\n" : "NO\n");
    mp.clear();
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