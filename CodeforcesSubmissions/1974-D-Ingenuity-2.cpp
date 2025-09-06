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
map<char, char> opp;
void do_it()
{
    opp['N'] = 'S';
    opp['S'] = 'N';
    opp['E'] = 'W';
    opp['W'] = 'E';
}
void solve()
{
    ll n, x = 0, y = 0;
    string s;
    cin >> n >> s;
    string ans(n, 'R');
    fro(i, 0, n - 1) y += s[i] == 'N', y -= s[i] == 'S', x += s[i] == 'E', x -= s[i] == 'W';
    if ((x & 1) || (y & 1) || (n == 2 && x == 0 && y == 0))
    {
        cout << "NO\n";
        return;
    }
    if (!(x || y))
    {
        ans[0] = 'H';
        fro(i, 0, n - 1) if (s[i] == opp[s[0]])
        {
            ans[i] = 'H';
            break;
        }
        goto out;
    }
    fro(i, 0, n - 1)
    {
        if (s[i] == 'N' && y > 0)
            ans[i] = 'H', y -= 2;
        else if (s[i] == 'S' && y < 0)
            ans[i] = 'H', y += 2;
        else if (s[i] == 'E' && x > 0)
            ans[i] = 'H', x -= 2;
        else if (s[i] == 'W' && x < 0)
            ans[i] = 'H', x += 2;
    }
out:
    cout << ans << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    inp_out();
    do_it();
    cout << setprecision(20) << fixed;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}