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
ll n, k, low, high, mid, sum;
bool check(ll m, vll arr)
{
    sum = 0;
    fro(i, n / 2, n - 1)
    {
        sum += max(0LL, m - arr[i]);
        if (sum > k)
            return false;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    inp_out();
    cout << setprecision(20) << fixed;
    cin >> n >> k;
    vll arr(n);
    fro(i, 0, n - 1) cin >> arr[i];
    sort(all(arr));
    low = 1, high = 2e9;
    while (low != high)
    {
        mid = (low + high + 1) / 2;
        if (check(mid, arr))
            low = mid;
        else
            high = mid - 1;
    }
    cout << low << "\n";
    return 0;
}