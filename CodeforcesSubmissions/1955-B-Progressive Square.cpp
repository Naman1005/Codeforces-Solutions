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
bool isPrime(ll n)
{
    if (n < 2 || (!(n & 1) && n != 2))
        return false;
    ll sq = sqrt(n);
    for (ll i = 2; i <= sq; i++)
        if (n % i == 0)
            return false;
    return true;
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
    ll t, n, c, d, m, min_ele;
    bool flag;
    cin >> t;
    while (t--)
    {
        flag = true;
        min_ele = LONG_LONG_MAX;
        cin >> n >> c >> d;
        m = n * n;
        ll arr[m], mat[m];
        fro(i, 0, m - 1)
        {
            cin >> arr[i];
            min_ele = min(min_ele, arr[i]);
        }
        sort(arr, arr + m);
        mat[0] = min_ele;
        fro(i, 0, n - 1) fro(j, 0, n - 1)
            if (i || j)
            {
                if (j == 0)
                    mat[(n * i) + j] = mat[(n * (i - 1)) + j] + d;
                else
                    mat[(n * i) + j] = mat[(n * i) + j - 1] + c;
            }
        sort(mat, mat + m);
        fro(i, 0, m - 1) if (arr[i] != mat[i])
        {
            flag = false;
            break;
        }
        cout << (flag ? "YES" : "NO") << "\n";
    }
}