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
    ll i = 0, n, a, b, z = 0, curSum = 0, total = 0;
    string s;
    cin >> a >> b >> s;
    n = s.length();
    while (i < n)
    {
        if (s[i] == '1')
            break;
        i++;
    }
    while (i < n)
    {
        if (s[i] == '1' && !curSum)
            curSum = z ? min(z * b, a) : a, z = 0, total += curSum;
        else if (s[i] == '0')
            z++, curSum = 0;
        i++;
    }
    cout << total << '\n';
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