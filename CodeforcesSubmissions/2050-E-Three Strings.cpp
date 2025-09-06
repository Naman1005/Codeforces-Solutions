#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vi vector<int>
#define vll vector<ll>
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
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
ll fun(const string &a, const string &b, const string &c, ll ia, ll ib, vector<vll> &dp)
{
    if (ia == a.size() && ib == b.size())
        return 0;
    ll mn = LONG_LONG_MAX;
    if (dp[ia][ib] != -1)
        return dp[ia][ib];
    if (ia < a.size())
        mn = (c[ia + ib] != a[ia]) + fun(a, b, c, ia + 1, ib, dp);
    if (ib < b.size())
        mn = min(mn, (c[ia + ib] != b[ib]) + fun(a, b, c, ia, ib + 1, dp));
    return dp[ia][ib] = mn;
}
void click_clack_boom()
{
    string a, b, c;
    cin >> a >> b >> c;
    vector<vll> dp(a.size() + 1, vll(b.size() + 1, -1));
    cout << fun(a, b, c, 0, 0, dp) << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);inp_out();
    ll too_much_work = 1, copied_work = 1;cin >> too_much_work, copied_work = too_much_work;
    auto begin = chrono::high_resolution_clock::now();
    while (too_much_work--)click_clack_boom();
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::microseconds>(end - begin);
    cerr << "Total: " << (elapsed.count()) << " ms\nAvg:" << (elapsed.count() / (ld)copied_work) << " ms" << endl;
}