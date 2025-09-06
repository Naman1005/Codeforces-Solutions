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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    inp_out();
    cout << setprecision(20) << fixed;
    ll n, x;
    cin >> n;
    vector<char> vec(n);
    vll arr(10, 0);
    fro(i, 0, n - 1)
    {
        cin >> vec[i];
        x = vec[i] - '0';
        switch (x)
        {
            case 2:
            case 3:
            case 5:
            case 7: arr[x]++; break;
            case 4: arr[2] += 2, arr[3]++; break;
            case 6: arr[3]++, arr[5]++; break;
            case 8: arr[2] += 3, arr[7]++; break;
            case 9: arr[2]++, arr[3] += 2, arr[7]++; break;
        }
    }
    pre(i, 9, 2) while (arr[i]--) cout << i;
}