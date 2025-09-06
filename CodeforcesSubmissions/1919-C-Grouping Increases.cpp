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
void solve()
{
    ll n, x, y, cnt = 0;
    cin >> n;
    vll arr(n), a, b;
    fro(i, 0, n - 1)
    {
        cin >> arr[i];
        x = a.size() ? a.back() : LONG_LONG_MAX, y = b.size() ? b.back() : LONG_LONG_MAX;
        (min(x, y) < arr[i] && arr[i] <= max(x, y)) ? (x > y ? a.push_back(arr[i]) : b.push_back(arr[i])) : (x < y ? a.push_back(arr[i]) : b.push_back(arr[i]));
    }
    if (a.size() > 1)
        fro(i, 0, a.size() - 2) if (a[i] < a[i + 1]) cnt++;
    if (b.size() > 1)
        fro(i, 0, b.size() - 2) if (b[i] < b[i + 1]) cnt++;
    cout << cnt << "\n";
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