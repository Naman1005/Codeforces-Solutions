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
    ll n, m, k, x, ans;
    cin >> n >> m >> k;
    vll a(n), b(m);
    multiset<ll> tar, done, rem;
    fro(i, 0, n - 1) cin >> a[i];
    fro(i, 0, m - 1)
    {
        cin >> b[i];
        tar.insert(b[i]);
    }
    fro(i, 0, m - 1)(tar.find(a[i]) != tar.end()) ? done.insert(a[i]), tar.erase(tar.find(a[i])) : rem.insert(a[i]);
    ans = (done.size() >= k);
    fro(i, m, n - 1)
    {
        x = a[i - m];
        if (rem.find(x) != rem.end())
            rem.erase(rem.find(x));
        else if (done.find(x) != done.end())
            done.erase(done.find(x)), tar.insert(x);
        (tar.find(a[i]) != tar.end()) ? done.insert(a[i]), tar.erase(tar.find(a[i])) : rem.insert(a[i]);
        ans += (done.size() >= k);
    }
    cout << ans << "\n";
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