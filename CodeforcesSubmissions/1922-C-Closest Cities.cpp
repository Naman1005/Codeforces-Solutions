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
    ll t, n, m, l, r;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vll arr(n), forward(n, 0), backward(n, 0);
        forward[0] = backward[n - 1] = 0, forward[1] = backward[n - 2] = 1;
        fro(i, 0, n - 1) cin >> arr[i];
        fro(i, 2, n - 1) forward[i] = forward[i - 1] + (arr[i] - arr[i - 1] < arr[i - 1] - arr[i - 2] ? 1 : arr[i] - arr[i - 1]);
        pre(i, n - 3, 0) backward[i] = backward[i + 1] + (arr[i + 1] - arr[i] < arr[i + 2] - arr[i + 1] ? 1 : arr[i + 1] - arr[i]);
        cin>>m;
        while (m--)
        {
            cin >> l >> r;
            l--, r--;
                cout << ((l < r)?forward[r] - forward[l]:backward[r] - backward[l] )<< "\n";
        }
    }
}