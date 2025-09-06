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
vll balance;
void just_do_it(string s)
{
    balance.clear();
    balance.resize(s.size(), 0);
    ll bal = 0;
    fro(i, 0, s.size() - 1) bal += s[i] == '(' ? 1 : -1, balance[i] = bal;
}
bool check1()
{
    for (auto x : balance)
        if (x < 0)
            return false;
    return true;
}
bool check2()
{
    for (auto x : balance)
        if (x > 0)
            return false;
    return true;
}
void solve()
{
    ll n;
    string s;
    cin >> n >> s;
    just_do_it(s);
    if (balance.back())
    {
        cout << "-1\n";
        return;
    }
    if (check1() || check2())
    {
        cout << "1\n";
        fro(i, 1, n) cout << 1 << " \n"[i == n];
        return;
    }
    cout << "2\n";
    fro(i, 0, n - 1)(balance[i]) ? cout << ((balance[i] < 0) + 1) << " \n"[i == n - 1] : cout << ((balance[i - 1] < 0) + 1) << " \n"[i == n - 1];
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