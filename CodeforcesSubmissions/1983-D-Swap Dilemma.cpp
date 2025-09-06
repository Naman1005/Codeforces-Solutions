#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pi 3.141592653589793238462643383279
#define vi vector<int>
#define vll vector<ll>
#define um unordered_map
#define all(a) (a).begin(), (a).end()
#define sortv(v) sort(all(v))
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
bool check(vll &arr, vll &brr)
{
    um<ll, ll> mp;
    ll n = arr.size(), cnt = 0, si;
    fro(i, 0, brr.size() - 1) mp[brr[i]] = i;
    fro(i, 0, n - 1) if (arr[i] != brr[i])
    {
        cnt++;
        si = mp[arr[i]];
        swap(brr[i], brr[si]);
        mp[brr[si]] = si, mp[arr[i]] = i;
    }
    return cnt % 2 == 0;
}
void solve()
{
    ll n;
    cin >> n;
    vll arr(n), brr(n);
    fro(i, 0, n - 1) cin >> arr[i];
    fro(i, 0, n - 1) cin >> brr[i];
    vll sa = arr, sb = brr;
    sortv(sa), sortv(sb);
    if (sa != sb)
    {
        cout << "NO" << endl;
        return;
    }
    if (check(arr, brr))
    {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
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