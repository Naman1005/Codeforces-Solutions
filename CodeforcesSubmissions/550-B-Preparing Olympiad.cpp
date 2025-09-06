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
void possibleSums(vll arr, ll n, ll currSum, vll &result)
{
    if (n == 0)
    {
        result.push_back(currSum);
        return;
    }
    possibleSums(arr, n - 1, currSum + arr[n - 1], result);
    possibleSums(arr, n - 1, currSum, result);
    return;
}
pair<ll, ll> add(vll arr, ll n)
{
    ll sum = 0, diff = 0, i = 0;
    while (n > 0)
    {
        if (n & 1)
            diff = (!diff) ? arr[i] : diff, sum += arr[i];
        n >>= 1, i++;
    }
    diff = arr[i - 1] - diff;
    return {sum, diff};
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    inp_out();
    cout << setprecision(20) << fixed;
    ll n, l, r, x, ans = 0;
    pair<ll, ll> temp;
    cin >> n >> l >> r >> x;
    vll arr(n);
    fro(i, 0, n - 1) cin >> arr[i];
    sort(all(arr));
    n = (1 << n) - 1;
    fro(i, 1, n)
    {
        if (__builtin_popcountll(i) < 2)
            continue;
        temp = add(arr, i);
        if (temp.first >= l && temp.first <= r && temp.second >= x)
            ans++;
    }
    cout << ans << "\n";
}