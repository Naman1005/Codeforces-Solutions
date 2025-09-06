#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pi 3.141592653589793238462643383279
#define vi vector<int>
#define vll vector<ll>
#define um unordered_map
#define all(a) (a).begin(), (a).end()
#define sortv(v) sort(all(v))
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    inp_out();
    cout << setprecision(20) << fixed;
    ll n, t, p1 = -1, p2 = -2, sum = 0, maxlen = 0;
    cin >> n >> t;
    vll arr(n);
    fro(i, 0, n - 1) cin >> arr[i];
    fro(i, 0, n - 1) if (arr[i] <= t)
    {
        p1 = p2 = i, sum = arr[i];
        break;
    }
    maxlen = max(maxlen, p2 - p1 + 1);
    while (p1 < n && p2 < n)
    {
        if (p1 > p2)
            p2 = p1, sum = arr[p1];
        if (sum < t && p2 < n - 1)
            p2++, sum += arr[p2];
        else if (sum > t)
            sum -= arr[p1], p1++;
        else
        {
            sum -= arr[p1], p1++;
            if (p2 + 1 < n)
                p2++, sum += arr[p2];
        }
        if (sum <= t)
            maxlen = max(maxlen, p2 - p1 + 1);
    }
    cout << maxlen;
    return 0;
}