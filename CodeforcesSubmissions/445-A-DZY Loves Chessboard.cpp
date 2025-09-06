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
    int m, n;
    cin >> n >> m;
    char arr[n][m];
    fro(i, 0, n - 1)
        fro(j, 0, m - 1)
    {
        cin >> arr[i][j];
        if (arr[i][j] == '.')
        {
            if (pow(-1, i + j) > 0)
                arr[i][j] = 'B';
            else
                arr[i][j] = 'W';
        }
    }
    fro(i, 0, n - 1)
    {
        fro(j, 0, m - 1) cout << arr[i][j];
        cout << "\n";
    }
}