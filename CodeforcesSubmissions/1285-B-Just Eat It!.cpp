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
ll Kadane(ll a[], ll size)
{
    ll MSF,MSF2,ME;
    MSF = LONG_LONG_MIN, ME = 0;
    fro(i, 0, size - 2)
    {
        ME += a[i];
        if (MSF < ME)
            MSF = ME;
        if (ME < 0)
            ME = 0;
    }
    MSF2 = LONG_LONG_MIN, ME = 0;
    fro(i, 1, size - 1)
    {
        ME += a[i];
        if (MSF2 < ME)
            MSF2 = ME;
        if (ME < 0)
            ME = 0;
    }
    return max(MSF, MSF2);
}
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
    // ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    inp_out();
    cout << setprecision(20) << fixed;
    ll t, n, s;
    cin >> t;
    while (t--)
    {
        cin >> n;
        s = 0;
        ll a[n];
        fro(i, 0, n - 1)
        {
            cin >> a[i];
            s += a[i];
        }
        cout << (s > Kadane(a, n) ? "YES" : "NO") << "\n";
    }
}