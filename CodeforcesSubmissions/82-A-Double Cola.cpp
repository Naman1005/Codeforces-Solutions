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
    ll arr[28];
    fro(i, 0, 27) arr[i] = 5 * (pow(2, i + 1) - 1);
    ll n, x, i = 27;
    cin >> n;
    while (i > 0)
    {
        if (arr[i] >= n && arr[i - 1] < n)
            break;
        i--;
    }
    x = i != 0 ? (ll)ceil((n - arr[i - 1]) / (double)((arr[i] - arr[i - 1]) / 5)) : n;
    switch (x)
    {
    case 1:
        cout << "Sheldon\n";
        break;
    case 2:
        cout << "Leonard\n";
        break;
    case 3:
        cout << "Penny\n";
        break;
    case 4:
        cout << "Rajesh\n";
        break;
    case 5:
        cout << "Howard\n";
        break;
    }
}