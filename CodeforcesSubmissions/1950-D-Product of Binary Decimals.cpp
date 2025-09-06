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
    int t, n, a, i;
    bool flag;
    cin >> t;
    int arr[] = {11111, 11110, 11101, 11100, 11011, 11010, 11001, 11000, 10111, 10110, 10101, 10100, 10011, 10010, 10001, 10000, 1111, 1110, 1101, 1100, 1011, 1010, 1001, 1000, 111, 110, 101, 100, 11, 10};
    while (t--)
    {
        flag = false;
        cin >> n;
        i = 0;
        fro(i,0,29)
        {
            if (!(n % arr[i]))
            {
                n = n / arr[i];
                if (n == 1)
                {
                    flag = true;
                    break;
                }
                i--;
            }
        }
        cout << ((flag || n == 1) ? "YES\n" : "NO\n");
    }
    return 0;
}