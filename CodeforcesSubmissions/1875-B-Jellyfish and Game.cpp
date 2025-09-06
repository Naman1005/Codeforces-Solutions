#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pi 3.141592653589793238462643383279
#define vi vector<int>
#define vll vector<ll>
#define umllll unordered_map<ll, ll>
#define umsll unordered_map<string, ll>
#define umcll unordered_map<char, ll>
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
    ll t, n, m, k, res, a_in, b_in, temp;
    cin >> t;
    while (t--)
    {
        res = a_in = b_in = 0;
        cin >> n >> m >> k;
        ll arr[n], brr[m];
        fro(i, 0, n - 1) cin >> arr[i];
        fro(i, 0, m - 1) cin >> brr[i];
        fro(i, 1, n - 1) if (arr[i] < arr[a_in]) a_in = i;
        fro(i, 1, m - 1) if (brr[i] > brr[b_in]) b_in = i;
        if (brr[b_in] > arr[a_in])
        {
            temp = brr[b_in];
            brr[b_in] = arr[a_in];
            arr[a_in] = temp;
        }
        if (k%2 == 0)
        {
            a_in = b_in = 0;
            fro(i, 1, n - 1) if (arr[i] > arr[a_in]) a_in = i;
            fro(i, 1, m - 1) if (brr[i] < brr[b_in]) b_in = i;
            temp = brr[b_in];
            brr[b_in] = arr[a_in];
            arr[a_in] = temp;
        }
        fro(i, 0, n - 1) res += arr[i];
        cout << res << "\n";
    }
}