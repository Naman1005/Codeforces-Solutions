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
ll n, x, s;
vll arr;
bool calc(ll a)
{
    ll p = 0, sum = 0;
    while (a > 0)
    {
        if (a & 1)
            sum += arr[p];
        a >>= 1, p++;
    }
    return (s - 2 * sum) % 360 == 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    inp_out();
    cout << setprecision(20) << fixed;
    bool flag = false;
    cin >> n;
    x = (1 << n) - 1;
    arr.resize(n);
    fro(i, 0, n - 1) cin >> arr[i];
    s = accumulate(all(arr), 0);
    fro(i, 0, x) flag |= calc(i);
    cout << (flag ? "YES" : "NO") << '\n';
}