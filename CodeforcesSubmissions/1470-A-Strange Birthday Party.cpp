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
ll truncMod(double a, double b)
{
    return a - (b * (floor(a / b)));
}
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
    ll t, n, m, j, p, s;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        ll index[n];
        fro(i, 0, n - 1)
        {
            cin >> index[i];
            index[i]--;
        }
        vll mat[m];
        fro(i, 0, m - 1)
        {
            ll temp;
            cin >> temp;
            mat[i].push_back(temp);
        }
        fro(i, 0, n - 1) mat[index[i]].push_back(1);
        p = 0;
        for (ll i = m - 1; i >= 0 && p < i; i--)
        {
            j = mat[i].size() - 1;
            while (j > 0 && p < i)
            {
                mat[p].push_back(1);
                mat[i].pop_back();
                j--;
                p++;
            }
        }
        s = 0;
        fro(i, 0, m - 1) s += (mat[i][0]) * (mat[i].size() - 1);
        cout << s << "\n";
    }
}