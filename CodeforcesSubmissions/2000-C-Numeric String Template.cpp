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
ll n;
vll arr;
void answer(string s)
{
    ll len = s.length();
    if (len != n)
    {
        cout << "NO\n";
        return;
    }
    map<ll, char> mp_num;
    map<char, ll> mp_char;
    fro(i, 0, len - 1)
    {
        if (!mp_num.count(arr[i]))
            mp_num[arr[i]] = s[i];
        if (!mp_char.count(s[i]))
            mp_char[s[i]] = arr[i];
        if (mp_num[arr[i]] != s[i] || mp_char[s[i]] != arr[i])
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    return;
}
void solve()
{
    ll m, len;
    string s;
    cin >> n;
    arr.resize(n);
    fro(i, 0, n - 1) cin >> arr[i];
    cin >> m;
    while (m--)
    {
        cin >> s;
        answer(s);
    }
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