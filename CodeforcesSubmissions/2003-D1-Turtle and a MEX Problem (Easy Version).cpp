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
ll sum(ll x)
{
    return x * (x + 1) / 2;
}
ll calc(ll l, ll r)
{
    return sum(r) - sum(l - 1);
}
void solve()
{
    ll n, m, s = 0, left, x;
    cin >> n >> m;
    fro(i, 1, n)
    {
        cin >> left;
        set<ll> temp;
        fro(j, 1, left)
        {
            cin >> x;
            temp.insert(x);
        }
        bool flag = true;
        fro(j, 0, LONG_LONG_MAX) if (!temp.count(j))
        {
            if (flag)
            {
                flag = false;
                continue;
            }
            s = max(s, j);
            break;
        }
    }
    cout << ((m <= s) ? (s * (m + 1)) : (s * (s + 1) + calc(s + 1, m))) << '\n';
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