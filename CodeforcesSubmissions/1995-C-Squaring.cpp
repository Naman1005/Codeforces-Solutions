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
const ld mn = 1e-9;
void solve()
{
    ll n, temp, cnt = 0, curr;
    cin >> n;
    vector<ld> arr(n);
    fro(i, 0, n - 1)
    {
        cin >> temp;
        arr[i] = log(log(temp));
    }
    fro(i, 0, n - 2) if (arr[i] - arr[i + 1] > mn)
    {
        if (arr[i + 1] == log(log(1)))
        {
            cout << "-1\n";
            return;
        }
        curr = ceil((arr[i] - arr[i + 1] - mn) / log(2)), arr[i + 1] += curr * log(2), cnt += curr;
    }
    cout << cnt << "\n";
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