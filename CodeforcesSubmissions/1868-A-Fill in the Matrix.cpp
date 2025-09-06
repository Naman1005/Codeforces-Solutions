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
void print_perm(ll n, ll rot)
{
    ll a[n];
    fro(i, 0, n - 1) a[i] = i;
    fro(i, n - rot, n - 1) cout << a[i] << " ";
    fro(i, 0, n - 1 - rot) cout << a[i] << " ";
    cout << "\n";
}
void solve()
{
    ll n, m;
    cin >> n >> m;
    if (m == 1)
    {
        cout << 0 << "\n";
        fro(i, 1, n) cout << 0 << "\n";
        return;
    }
    if (n >= m - 1)
    {
        cout << m << "\n";
        fro(i, 2, m) print_perm(m, i - 2);
        fro(i, 1, n - m + 1) print_perm(m, 0);
        return;
    }
    cout << n + 1 << "\n";
    fro(i, 1, n) print_perm(m, i - 1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    inp_out();
    cout << setprecision(20) << fixed;
    ll t, n, m;
    cin >> t;
    while (t--) solve();
}