#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
ll m;
map<ll, ll> mp;
ll calc(ll a, ll cnt_a)
{
    ll ans, total, rem, b = a + 1, cnt_b = mp[b];
    ans = total = a * min(m / a, cnt_a);
    if (!cnt_b)
        return ans;
    rem = m - total;
    if (rem >= b)
        total += b * min(rem / b, cnt_b), cnt_b -= min(rem / b, cnt_b), rem = m - total;
    return max({ans, min(m / b, cnt_b), total + min({rem, cnt_b, min(m / a, cnt_a)})});
}
void solve()
{
    ll n,temp;
    cin >> n >> m;
    vll arr;
    fro(i, 0, n - 1)
    {
        cin >> temp;
        arr.push_back(temp);
        mp[temp]++;
    }
    n= arr.size();
    sort(all(arr));
    ll ans = 0;
    fro(i, 0, n - 1) ans = max(ans, calc(arr[i], mp[arr[i]]));
    cout << ans << '\n';
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