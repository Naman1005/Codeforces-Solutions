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
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    map<ll, ll> m;
    ll s = 0;
    m[0] = 1;
    for (int i = 0; i < n; ++i)
    {
        a[i] *= ((i % 2) ? -1 : 1);
        s += a[i];
        if (m[s])
        {
            cout << "YES\n";
            return;
        }
        ++m[s];
    }
    cout << "NO\n";
}
void solve2()
{
    ll n;
    cin >> n;
    vll arr(n);
    fro(i, 0, n - 1) cin >> arr[i];
    map<ll, ll> m;
    ll s = 0;
    m[0] = 1;
    fro(i, 0, n - 1)
    {
        arr[i] *= ((i & 1) ? 1 : -1);
        s += arr[i];
        if (m[s])
        {
            cout << "YES\n";
            return;
        }
        ++m[s];
    }
    cout << "NO\n";
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
        solve2();
    }
}