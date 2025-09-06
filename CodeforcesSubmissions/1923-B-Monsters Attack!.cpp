#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vi vector<int>
#define vll vector<ll>
#define umllll unordered_map<ll, ll>
#define umsll unordered_map<string, ll>
#define umcll unordered_map<char, ll>
#define mllll map<ll, ll>
#define msll map<string, ll>
#define sortv(v) sort(v.begin(), v.end())
#define all(a) (a).begin(), (a).end()
#define sort_and_unique(a) \
    sort(all(a));          \
    (a).resize(unique(all(a)) - (a).begin())
#define fro(i, x, y) for (ll i = x; i <= y; i++)
#define pre(i, x, y) for (ll i = x; i >= y; i--)
ll fact(ll n)
{
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
    ll t, n, k, temp, left;
    bool flag;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        ll health[n];
        ll pos[n];
        left = 0;
        flag = true;
        fro(i, 0, n - 1) cin >> health[i];
        fro(i, 0, n - 1) cin >> pos[i];
        vector<long long> s(n + 1);
        fro(i,0,n-1) s[abs(pos[i])] += health[i];
        fro(i, 1, n)
        {
            left += k - s[i];
            flag &= (left >= 0);
        }
        cout << (flag ? "YES\n" : "NO\n");
    }
}