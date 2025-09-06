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
    ll t, n, prevg, maxg, currg;
    cin >> t;
    while (t--)
    {
        cin >> n;
        ll arr[n], mi = 0;
        fro(i, 0, n - 1)
        {
            cin >> arr[i];
            if (arr[i] > arr[mi])
                mi = i;
        }
        swap(arr[mi], arr[0]);
        prevg = arr[0];
        fro(i, 1, n - 1)
        {
            maxg = 1, mi = i;
            fro(j, i, n - 1)
            {
                currg = __gcd(prevg, arr[j]);
                if (currg > maxg)
                    maxg = currg, mi = j;
            }
            swap(arr[mi], arr[i]);
            prevg = maxg;
        }
        for (auto k : arr)
            cout << k << " ";
        cout << "\n";
    }
}