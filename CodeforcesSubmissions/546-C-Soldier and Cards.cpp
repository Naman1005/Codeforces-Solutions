#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pi 3.141592653589793238462643383279
#define vi vector<int>
#define vll vector<ll>
#define um unordered_map
#define all(a) (a).begin(), (a).end()
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
    ll n, m, k1, k2, cnt = 0, x1, x2;
    cin >> n;
    m = fact(n);
    queue<ll> q1, q2, temp1, temp2;
    cin >> k1;
    fro(i, 0, k1 - 1)
    {
        cin >> x1;
        q1.push(x1);
    }
    cin >> k2;
    fro(i, 0, k2 - 1)
    {
        cin >> x2;
        q2.push(x2);
    }
    temp1 = q1, temp2 = q2;
    while (q1.size() && q2.size())
    {
        cnt++;
        x1 = q1.front(), x2 = q2.front();
        q1.pop();
        q2.pop();
        if (x1 > x2)
            q1.push(x2), q1.push(x1);
        else
            q2.push(x1), q2.push(x2);
        if (cnt > m)
        {
            cnt = -1;
            break;
        }
    }
    cout << cnt << " ";
    if (cnt != -1)
        cout << (q1.empty() ? 2 : 1);
}