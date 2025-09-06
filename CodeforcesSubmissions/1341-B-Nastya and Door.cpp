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
    ll t, n, k, s, l, min_sum;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        ll arr[n], m[n];
        fro(i, 0, n - 1) cin >> arr[i];
        m[n - 1] = m[0] = s = l = 0;
        fro(i, 1, n - 2)((arr[i] > arr[i + 1] && arr[i] > arr[i - 1]) ? m[i] = 1 : m[i] = 0);
        fro(i, 1, k - 2) s += m[i];
        min_sum = s;
        fro(i, 1, n - k + 1)
        {
            s += m[i + k - 2] - m[i];
            if (s > min_sum)
                min_sum = s, l = i;
        }
        cout << min_sum + 1 << " " << l + 1 << "\n";
    }
}