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
void solve()
{
    ll n, m, temp;
    cin >> n;
    vll arr(n);
    map<ll, ll> mp, mp2;
    fro(i, 0, n - 1) cin >> arr[i];
    fro(i, 0, n - 1)
    {
        cin >> temp;
        mp2[temp]++;
        if (temp != arr[i])
            mp[temp]++;
    }
    cin >> m;
    vll vec(m);
    fro(i, 0, m - 1)
    {
        cin >> vec[i];
        if (mp[vec[i]])
            mp[vec[i]]--, vec[i] = 0;
    }
    bool f1 = (vec[m - 1] == 0 || mp2[vec[m - 1]]), f2 = true;
    for (auto k : mp)
        if (k.second)
            f2 = false;
    cout << ((f1 && f2) ? "YES" : "NO") << "\n";
    return;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    inp_out();
    cout << setprecision(20) << fixed;
    ll t, n, m, temp;
    cin >> t;
    while (t--)
        solve();
}