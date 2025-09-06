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
void solve()
{
    ll n, x, y, cnt = 0;
    cin >> n;
    set<ll> s1, s2;
    fro(i, 0, n - 1)
    {
        cin >> x >> y;
        y ? s2.insert(x) : s1.insert(x);
    }
    for (auto k : s1)
    {
        if (s2.find(k + 1) != s2.end() && s1.find(k + 2) != s1.end())
            cnt++;
        if (s2.find(k) != s2.end())
            cnt += s2.size() + s1.size() - 2;
    }
    for (auto k : s2)
        if (s1.find(k - 1) != s1.end() && s2.find(k - 2) != s2.end())
            cnt++;
    cout << cnt << endl;
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