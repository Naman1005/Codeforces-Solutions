#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pi 3.141592653589793238462643383279
#define vi vector<int>
#define vll vector<ll>
#define um unordered_map
#define all(a) (a).begin(), (a).end()
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
    ll n, k, p1, p2, cnt = 0, rem = 0;
    cin >> n >> k;
    string s;
    cin >> s;
    p1 = n, p2 = -1;
    fro(i, 0, n - 1) if (s[i] == '1')
    {
        cnt++;
        if (p1 == n)
            p1 = i;
        p2 = i;
    }
    if (cnt && (n - 1 - p2) <= k)
        cnt--, rem++, k -= n - 1 - p2;
    if (cnt && p1 <= k)
        cnt--, rem += 10, k -= p1;
    cout << 11 * cnt + rem << "\n";
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