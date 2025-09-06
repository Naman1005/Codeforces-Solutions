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
void convert(vll &arr)
{
    fro(i, 1, arr.size() - 2) arr[i] += arr[i - 1];
}
void solve()
{
    ll n, m, k, w, ans = 0, len;
    cin >> n >> m >> k >> w;
    len = max(n, m);
    vll arr(w), row(n + 1, 0), col(m + 1, 0), mat(n * m);
    fro(i, 0, w - 1) cin >> arr[i];
    fro(i, 0, max(0LL, n - k + 1) - 1) row[i]++, row[i + k]--;
    fro(i, 0, max(0LL, m - k + 1) - 1) col[i]++, col[i + k]--;
    convert(row);
    convert(col);
    fro(i, 0, n - 1) fro(j, 0, m - 1) mat[i * m + j] = row[i] * col[j];
    sort(all(mat), greater<ll>());
    sort(all(arr), greater<ll>());
    fro(i, 0, w - 1) ans += arr[i] * mat[i];
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