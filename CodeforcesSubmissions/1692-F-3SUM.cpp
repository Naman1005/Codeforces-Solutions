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
    ll t, n, temp, s;
    bool flag;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vi vec;
        flag = false;
        int v[10];
        memset(v, 0, sizeof(v));
        fro(i, 0, n - 1)
        {
            cin >> temp;
            temp %= 10;
            if (v[temp] < 3)
                v[temp]++;
        }
        fro(i, 0, 9) fro(j, 1, v[i]) vec.push_back(i);
        s = vec.size();
        fro(i, 0, s - 1) fro(j, i + 1, s - 1) fro(k, j + 1, s - 1) if ((vec[i] + vec[j] + vec[k]) % 10 == 3)
        {
            flag = true;
            break;
        }
        cout<<(flag?"YES":"NO")<<"\n";
    }
}