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
void solve()
{
    ll n;
    cin >> n;
    vll arr(n);
    bool flag = false;
    fro(i, 0, n - 1)
    {
        cin >> arr[i];
        if (arr[i] % 5 == 0)
            flag = true;
    }
    if (flag)
    {
        arr[0] += arr[0] % 10;
        fro(i, 1, n - 1) if (arr[i] + arr[i] % 10 != arr[0])
        {
            cout << "No\n";
            return;
        }
        cout << "Yes\n";
        return;
    }
    fro(i, 0, n - 1)
    {
        while (arr[i] % 10 != 4)
            arr[i] += arr[i] % 10;
        arr[i] %= 20;
        if(arr[i] != arr[0])
        {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
    return;
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