#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pi 3.141592653589793238462643383279
#define vi vector<int>
#define vll vector<ll>
#define umllll unordered_map<ll, ll>
#define umsll unordered_map<string, ll>
#define umcll unordered_map<char, ll>
#define sortv(v) sort(v.begin(), v.end())
#define all(a) (a).begin(), (a).end()
#define sort_and_unique(a) \
    sort(all(a));          \
    (a).resize(unique(all(a)) - (a).begin())
#define fro(i, x, y) for (ll i = x; i <= y; i++)
#define pre(i, x, y) for (ll i = x; i >= y; i--)
ll truncMod(double a, double b)
{
    return a - (b * (floor(a / b)));
}
ll fact(ll n)
{
    if (n == 0)
        return 1;
    ll res = 1;
    for (ll i = 2; i <= n; i++)
        res *= i;
    return res;
}
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
    ll t, n, m, l, r, x, ans, mn, mx;
    cin >> t;
    while (t--)
    {
        cin >> n >> x >> m;
        mn = n + 1, mx = 0;
        fro(i, 1, m)
        {
            cin >> l >> r;
            if (l <= x && x <= r)
            {
                if (l < mn) mn = l;
                if (r > mx) mx = r;
            }
            if (r > mx && mx != 0 && l <= mx) mx = r;
            if (l < mn && mn != n + 1 && r >= mn) mn = l;
        }
        cout << (mx ? mx - mn + 1 : 1) << "\n";
    }
}