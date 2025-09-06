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
void solve()
{
    ll n, ans = 0;
    cin >> n;
    vll arr(n);
    vector<pair<ll, ll>> vec;
    for (auto &x : arr)
        cin >> x;
    sort(all(arr));
    vec.push_back({1, arr[0]});
    fro(i, 1, n - 1)
    {
        if (arr[i] != arr[i - 1])
            vec.push_back({1, arr[i]});
        else
            vec.back().first++;
    }
    sort(all(vec));
    pre(i, vec.size() - 1, 0)
    {
        if (i != vec.size() - 1 && vec[i].first >= vec[i + 1].first)
            vec[i].first = vec[i + 1].first - 1;
        if (!vec[i].first)
            break;
        ans += vec[i].first;
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