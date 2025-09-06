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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    inp_out();
    cout << setprecision(20) << fixed;
    ll m, s, s2, i;
    cin >> m >> s;
    if ((s == 0 && m > 1) || s > m * 9)
    {
        cout << "-1 -1";
        return 0;
    }
    vi mn(m, 0), mx(m, 0);
    s2 = s, mn[0] = s > 0 ? 1 : 0, i = m - 1, s--;
    while (s > 0)
        mn[i--] += (s >= 9) ? 9 : s, s -= (s >= 9) ? 9 : s;
    i = 0;
    while (s2 > 0)
        mx[i++] += (s2 >= 9) ? 9 : s2, s2 -= (s2 >= 9) ? 9 : s2;
    fro(i, 0, m - 1) cout << mn[i];
    cout << " ";
    fro(i, 0, m - 1) cout << mx[i];
    cout << "\n";
}