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
#define forn(i, n) for (int i = 0; i < int(n); i++)
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
    ll t, n, m;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        ll arr[n], brr[n], l = 0, r = n - 1;
        fro(i, 0, n - 1) cin >> arr[i];
        cin >> s;
        fro(i, 0, n - 2)((s[i] == 'L') ? l++ : r--);
        brr[n - 1] = arr[l] % m;
        pre(i, n - 2, 0) s[i] == 'L' ? brr[i] = (brr[i + 1] * arr[--l]) % m : brr[i] = (brr[i + 1] * arr[++r]) % m;
        fro(i, 0, n - 1) cout << brr[i] << " ";
        cout << "\n";
    }
}