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
ll primeFactors(ll n, umllll &map)
{
    ll max_ele = -1, max = -1;
    while (n % 2 == 0)
    {
        map[2]++, n /= 2;
        if (map[2] > max) max = map[2], max_ele = 2;
    }
    ll sq = sqrt(n);
    for (ll i = 3; i <= sq; i += 2) while (n % i == 0)
    {
        map[i]++, n /= i;
        if (map[i] > max) max = map[i], max_ele = i;
    }
    return max_ele;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    inp_out();
    cout << setprecision(20) << fixed;
    ll t, n, max_ele;
    cin >> t;
    while (t--)
    {
        cin >> n;
        umllll map;
        max_ele = primeFactors(n, map);
        cout << (max_ele == -1 ? 1 : map[max_ele]) << "\n";
        fro(i, 1, map[max_ele] - 1) cout << max_ele << " ";
        cout << (max_ele == -1 ? n : (ll)(n / pow(max_ele, map[max_ele] - 1))) << "\n";
    }
}