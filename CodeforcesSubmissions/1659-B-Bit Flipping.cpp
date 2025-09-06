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
    ll n, k, moves;
    string s;
    cin >> n >> k >> s;
    vll pick(n, 0);
    moves = k;
    fro(i, 0, n - 1) if (moves > 0) if ((s[i] == '1' && (k & 1)) || (s[i] == '0' && !(k & 1))) pick[i]++, moves--;
    pick[n - 1] += moves;
    fro(i, 0, n - 1)((k & 1) == (pick[i] & 1)) ? cout << s[i] : cout << (s[i] == '1' ? 0 : 1);
    cout << "\n";
    fro(i, 0, n - 1) cout << pick[i] << " ";
    cout << "\n";
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