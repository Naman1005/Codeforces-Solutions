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
    ll n, x;
    cin >> n;
    vll even, odd;
    int flag = 0;
    fro(i, 0, n - 1)
    {
        cin >> x;
        (x & 1) ? odd.push_back(x) : even.push_back(x);
    }
    if (even.empty() || odd.empty())
    {
        cout << 0 << "\n";
        return;
    }
    sort(all(even));
    x = *max_element(all(odd));
    fro(i, 0, even.size() - 1) flag |= (x <= even[i]), x += even[i];
    cout << even.size() + flag << "\n";
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