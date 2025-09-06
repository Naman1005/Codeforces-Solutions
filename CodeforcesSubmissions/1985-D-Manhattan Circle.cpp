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
    ll n, m, sum = 0, prev = 0, x;
    cin >> n >> m;
    char mat[n][m];
    fro(i, 0, n - 1) fro(j, 0, m - 1) cin >> mat[i][j];
    fro(i, 0, n - 1)
    {
        sum = 0;
        fro(j, 0, m - 1) { sum += mat[i][j] == '#' ? 1 : 0; }
        if (sum > prev)
            x = i;
        prev = sum;
    }
    ll p1 = 0, p2 = m - 1;
    while (p1 < m)
        if (mat[x][p1++] == '#')
            break;
    p1--;
    while (p2 >= 0)
        if (mat[x][p2--] == '#')
            break;
    p2++;
    cout << x + 1 << " " << ((p1 + p2) / 2) + 1 << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    inp_out();
    cout << setprecision(20) << fixed;
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}