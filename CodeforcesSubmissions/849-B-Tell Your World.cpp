#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pi 3.141592653589793238462643383279
#define vi vector<int>
#define vll vector<ll>
#define um unordered_map
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
double slope(pair<ll, ll> p1, pair<ll, ll> p2)
{
    return (double)(p2.second - p1.second) / (double)(p2.first - p1.first);
}
double y_intercept(pair<ll, ll> p1, pair<ll, ll> p2)
{
    return (double)(p1.second - slope(p1, p2) * p1.first);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    inp_out();
    cout << setprecision(20) << fixed;
    ll n, temp, cnt;
    cin >> n;
    vector<pair<ll, ll>> vec;
    fro(i, 1, n)
    {
        cin >> temp;
        vec.push_back({i, temp});
    }
    double a = slope(vec[0], vec[1]), b = slope(vec[1], vec[2]), c = slope(vec[2], vec[0]);
    if (a == b && b == c)
    {
        vll diff;
        fro(i, 3, n - 1) if (slope(vec[i], vec[0]) != a) diff.push_back(i);
        if (!diff.size())
        {
            cout << "No\n";
            return 0;
        }
        if (diff.size() == 1)
        {
            cout << "Yes\n";
            return 0;
        }
        ll target = slope(vec[diff[0]], vec[diff[diff.size() - 1]]);
        if (target != a)
        {
            cout << "No\n";
            return 0;
        }
        fro(i, 0, diff.size() - 2) if (slope(vec[diff[i]], vec[diff[i + 1]]) != target)
        {
            cout << "No\n";
            return 0;
        }
        cout << "Yes\n";
        return 0;
    }
    bool fa, fb, fc;
    fa = fb = fc = true;
    fro(i, 3, n - 1)
    {
        if (slope(vec[i], vec[0]) != a && slope(vec[i], vec[2]) != a)
            fa = false;
        if (slope(vec[i], vec[1]) != b && slope(vec[i], vec[0]) != b)
            fb = false;
        if (slope(vec[i], vec[2]) != c && slope(vec[i], vec[1]) != c)
            fc = false;
    }
    if (fa || fb || fc)
        cout << "Yes\n";
    else
        cout << "No\n";
}