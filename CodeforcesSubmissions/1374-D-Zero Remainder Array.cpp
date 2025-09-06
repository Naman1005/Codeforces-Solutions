#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
void solve()
{
    ll i = 0, temp = 0, n, k, mx = 0;
    cin >> n >> k;
    vll arr(n);
    fro(i, 0, n - 1)
    {
        cin >> arr[i];
        arr[i] = arr[i] % k ? k - arr[i] % k : 0;
    }
    sort(all(arr));
    while (i < n)
    {
        mx = max(mx, arr[i]);
        temp = i + 1;
        while (temp < n && arr[temp] == arr[i] && arr[temp])
            mx = max(mx, arr[i] + k * (temp - i)), temp++;
        i = temp;
    }
    cout << (mx ? mx + 1 : 0) << "\n";
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