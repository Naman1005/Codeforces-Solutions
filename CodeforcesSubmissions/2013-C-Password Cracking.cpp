#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pi 3.14159265358979323846
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
bool ask(string t)
{
    short ans;
    cout << "? " << t << '\n';
    cin >> ans;
    return ans;
}
void solve()
{
    ll n;
    string ans;
    cin >> n;
    while (ans.size() < n)
    {
        if (ask(ans + "0"))
            ans += "0";
        else if (ask(ans + "1"))
            ans += "1";
        else
            break;
    }
    while (ans.size() < n)
        ans = (ask("0" + ans) ? "0" : "1") + ans;
    cout << "! " << ans << '\n';
}
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    // inp_out();
    cout << setprecision(20) << fixed;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}