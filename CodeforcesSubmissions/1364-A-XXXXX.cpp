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
    int t, n, x, sum, l, r, temp;
    cin>>t;
    while (t--)
    {
        cin >> n >> x;
        sum = 0, l = -1;
        fro(i, 0, n - 1)
        {
            cin >> temp;
            if (temp % x)
            {
                if (l == -1)
                    l = i;
                r = i;
            }
            sum += temp;
        }
        if (sum % x)
            cout << n << "\n";
        else if (l == -1)
            cout << -1 << "\n";
        else
            cout << n - min(l + 1, n - r) << "\n";
    }
}