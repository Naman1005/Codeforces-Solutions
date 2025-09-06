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
bool isPrime(int n)
{
    if (n < 2 || (!(n & 1) && n != 2))
        return false;
    ll sq = sqrt(n);
    for (ll i = 2; i <= sq; i++)
        if (n % i == 0)
            return false;
    return true;
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
     string s;
    cin >> s;
    ll n = s.length();
    char odd = s[n - 1];
    ll in = -1;
    fro(i, 0, n - 1) if ((s[i] - '0') % 2 == 0)
    {
        in = i;
        if (s[i] < odd)
        {
            swap(s[i], s[n - 1]);
            break;
        }
    }
    if (in == -1)
        cout << -1 << "\n";
    else
    {
        if (odd == s[n - 1])
            swap(s[in], s[n - 1]);
        cout << s << "\n";
    }
}